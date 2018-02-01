/******************************************************************
***
***		���b�V���h�[������
***
***		meshDome.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "meshDome.h"
#include "textureManager.h"
/******************************************************************
�}�N����`
*******************************************************************/
#define NUM_VERTEX (4)	//���_��
#define NUM_POLYGON (2)
#define NUM_MESH_X (20)			//���̃}�X��
#define NUM_MESH_Z (4)			//�c�̃}�X��
#define NUM_Y (100.0f)
#define NUM_MESH_VERTEX ((NUM_MESH_X+1) * (NUM_MESH_Z+1))								//���_�̑���
#define NUM_MESH_INDEX (((NUM_MESH_X +1)*2) + ((NUM_MESH_Z-1) * (NUM_MESH_X+2)*2) )
#define NUM_MESH_POLYGON (((NUM_MESH_X * NUM_MESH_Z * NUM_POLYGON) + (4 * (NUM_MESH_Z-1))))	//���|���S����
#define NUM_ROT ((360.0f/(NUM_MESH_X-2)))
#define NUM_LENGTH (500.0f)
#define POS_Y ((NUM_Y*NUM_MESH_Z)*2) 

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/
CRenderer *CMeshDome::m_pRenderer = NULL;
/******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CMeshDome::CMeshDome()
{
	/*CManager::GetTextureManager()->LoadTexture(CTextureManager::TYPE_SKY);
	pTexture = CManager::GetTextureManager()->GetTexture(CTextureManager::TYPE_SKY);
*/
	pTexture = NULL;
}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CMeshDome::~CMeshDome()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CMeshDome::Initialize(void)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//���_���쐬����
	MakeVertex();

	//�C���f�b�N�X�o�b�t�@�ݒ菈��
	MakeIndex();

	//�X�e�[�^�X�̏�����
	m_Pos = D3DXVECTOR3(0.0f,POS_Y,0.0f);		//���W
	m_Rot = D3DXVECTOR3(180.0f,0.0f,0.0f);	//�p�x
	m_Scale = D3DXVECTOR3(1.0f,1.0f,1.0f);		//�g�嗦
	Color = D3DXCOLOR(255.0f,255.0f,255.0f,255.0f);
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CMeshDome::Uninitialize(void)
{
	//�o�b�t�@�̔j��
	if(m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//�C���f�b�N�X�o�b�t�@�̔j��
	if(m_IndexBuff != NULL)
	{
		m_IndexBuff->Release();
		m_IndexBuff = NULL;
	}
	
	CScene::Release();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CMeshDome::Update(void)
{
	m_Rot.y +=0.01f;
	//Color.r = 0.0f;
	//Color.g = 0.0f;
	//Color.b = 0.0f;
	//SetColor();
}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CMeshDome::Draw(void)
{
	//�����_�[�X�e�[�g�̏�Ԏ擾
	m_pRenderer = CManager::GetRenderer();

	//Z�o�b�t�@�̐ݒ�
	m_pRenderer->SetzBuff();

	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pD3DDevice =  CManager::GetRenderer()->GetDevice();

	//�P�ʍs��
	D3DXMatrixIdentity(&m_mtxWorld);
	
	//�g��s��
	D3DXMatrixScaling(&m_mtxScale,m_Scale.x,m_Scale.y,m_Scale.z);
	
	//���s�s��
	D3DXMatrixTranslation(&m_mtxTrans,m_Pos.x,m_Pos.y,m_Pos.z);
	
	//��]�s��
	D3DXMatrixRotationYawPitchRoll(&m_mtxRot,
		D3DXToRadian(m_Rot.y),
		D3DXToRadian(m_Rot.x),
		D3DXToRadian(m_Rot.z));
	
	D3DXMatrixMultiply(&m_mtxWorld,&m_mtxWorld,&m_mtxScale);
	
	//���[���h�ϊ�
	m_mtxWorld = m_mtxScale * m_mtxRot * m_mtxTrans;

	//���[���h���W�ɐݒ�
	pD3DDevice->SetTransform(D3DTS_WORLD,&m_mtxWorld);



	//���_�t�H�[�}�b�g�̐ݒ�
	pD3DDevice -> SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pD3DDevice->SetTexture(0,NULL);

	//���C�g�ݒ�
	pD3DDevice->SetRenderState(D3DRS_LIGHTING,false);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pD3DDevice->SetStreamSource(0,m_pVtxBuff,0,sizeof(VERTEX_3D));

	pD3DDevice->SetIndices(m_IndexBuff);

	//�|���S���̕`��
	pD3DDevice -> DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP,	//�`��^�C�v
		0,					//�ŏ��̒��_�C���f�b�N�X�ԍ�
		0,					//�ŏ��̒��_�C���f�b�N�X�ԍ�
		NUM_MESH_VERTEX,	//���_����
		0,					//�n�߂̃C���f�b�N�X�ԍ�
		NUM_MESH_POLYGON);	//�|���S���̑���

	//���C�g�ݒ�
	pD3DDevice->SetRenderState(D3DRS_LIGHTING,true);
}

/******************************************************************
���_�ݒ菈���֐�
*******************************************************************/
void CMeshDome::MakeVertex(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pDevice =  CManager::GetRenderer()->GetDevice();

	//�ϐ��錾
	int nCnt = 0;	//���[�v�J�E���^
	int nCntSec = 0;
	float fRot=0.0f;
	D3DXVECTOR2 BuffTex;
	BuffTex.x = 0.0f;
	BuffTex.y = 1.0f;

	D3DXVECTOR3 BuffPos(NUM_LENGTH*cosf(D3DXToRadian(0.0f))-sinf(D3DXToRadian(0.0f))
		,0.0f
		,NUM_LENGTH*sinf(D3DXToRadian(fRot))+cosf(D3DXToRadian(fRot)));

	//���_�\���̃|�C���^
	VERTEX_3D * pVtx;

	//���_�o�b�t�@�̐���
	pDevice -> CreateVertexBuffer(
		sizeof(VERTEX_3D) * NUM_MESH_VERTEX,	//�m�ۂ���o�b�t�@�T�C�Y�i�o�C�g�j
		D3DUSAGE_WRITEONLY,				//�g�p���@
		FVF_VERTEX_3D,					//�g�p���钸�_�t�H�[�}�b�g(0�ł���)
		D3DPOOL_MANAGED,				//�o�b�t�@�ɏ������񂾕��̊Ǘ����@
		&m_pVtxBuff,					//�A�h���X�̎w��
		NULL);

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff -> Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//�c�̃|���S�������J��Ԃ�
	for(int z = 0 ; z < NUM_MESH_Z+1 ; z++)
	{
		//���̃|���S�������J��Ԃ�
		for(int x = 0 ; x < NUM_MESH_X+1 ; x++,nCnt++)
		{
			if(nCnt != 0 && nCnt %(NUM_MESH_X+1)==0)
			{
				//�������炷
				BuffPos.x = NUM_LENGTH*z*cosf(D3DXToRadian(fRot))-sinf(D3DXToRadian(fRot));
				BuffPos.z = NUM_LENGTH*z*sinf(D3DXToRadian(fRot))+cosf(D3DXToRadian(fRot));
				BuffPos.y +=z*NUM_Y;

				BuffTex.x = 0.0f;
				BuffTex.y+=(1.0f/NUM_MESH_Z);
			}
			//���_���W�̐ݒ�
			pVtx[nCnt].pos = D3DXVECTOR3(BuffPos.x,BuffPos.y,BuffPos.z);

			//�@�����
			pVtx[nCnt].normal = D3DXVECTOR3(0.0f,1.0f,0.0f);

			//���_�F�̐ݒ�
			pVtx[nCnt].color = D3DCOLOR_RGBA(105,155,255,255);

			//�e�N�X�`���̍��W�ݒ�
			pVtx[nCnt].tex = D3DXVECTOR2(BuffTex.x,BuffTex.y);

			//���ɂ��炷
			BuffPos.x = z*NUM_LENGTH*cosf(D3DXToRadian(fRot))-sinf(D3DXToRadian(fRot));
			BuffPos.z = z*NUM_LENGTH*sinf(D3DXToRadian(fRot))+cosf(D3DXToRadian(fRot));

			fRot+=NUM_ROT;
			BuffTex.x+=(1.0f/NUM_MESH_X);
		}
		fRot=0.0f;
	}
	//�o�b�t�@���A�����b�N
	m_pVtxBuff -> Unlock();
}

/******************************************************************
�C���f�b�N�X�o�b�t�@�ݒ菈���֐�
*******************************************************************/
void CMeshDome::MakeIndex(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pDevice =  CManager::GetRenderer()->GetDevice();

	//�C���f�b�N�X�o�b�t�@�p�|�C���^
	WORD *pIndex = NULL;
	int nIndex = NUM_MESH_X+1;
	int nIndexCnt = nIndex;
	int nCntSec = 0;

	//�C���f�b�N�X�o�b�t�@�̐���
	pDevice ->CreateIndexBuffer(
		sizeof(WORD) * NUM_MESH_INDEX,	//�m�ۂ���o�b�t�@�T�C�Y�i�o�C�g�j
		D3DUSAGE_WRITEONLY,				//�g�p���@
		D3DFMT_INDEX16,					//�g�p���钸�_�t�H�[�}�b�g(0�ł���)
		D3DPOOL_MANAGED,				//�o�b�t�@�ɏ������񂾕��̊Ǘ����@
		&m_IndexBuff,					//�A�h���X�̎w��
		NULL);

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_IndexBuff -> Lock(
		0,				//�͈͎w��
		0,
		(void**)&pIndex,	//���z�A�h���X�̎擾
		0);

	//�y�̐������J��Ԃ�
	for(int nCnt = 0 ; nCnt <NUM_MESH_INDEX  ; nCnt +=2 , nCntSec++)
	{		
		//�[�ɗ�����
		if(nCntSec !=0 && nCntSec % (NUM_MESH_X+1) == 0)
		{
			//�O�Ɠ����_��ł�
			pIndex[nCnt] = pIndex[nCnt-1];
			
			nIndexCnt += NUM_MESH_X+1;
			nIndex = nIndexCnt;
			pIndex[nCnt+1] = nIndex;
			nCnt += 2;
		}

		//�C���f�b�N�X�o�b�t�@��ݒ�
		pIndex[nCnt] = nIndex;
		pIndex[nCnt+1] = pIndex[nCnt] - (NUM_MESH_X + 1);
		nIndex++;
	}

	//pIndex=NULL;

	//�o�b�t�@���A�����b�N
	m_IndexBuff -> Unlock();
}

/******************************************************************
�I�u�W�F�N�g�쐬�֐�
*******************************************************************/
CMeshDome *CMeshDome::Create(void)
{
	//�I�u�W�F�N�g�|�C���^
	CMeshDome *pMeshField;

	//�C���X�^���X�̐���
	pMeshField = new CMeshDome;

	//����������
	pMeshField -> Initialize();

	//�I�u�W�F�N�g�̌^�o�^�֐��Ăяo��
	pMeshField->SetObjType(OBJTYPE_DOME);

	return pMeshField;
}

void CMeshDome::SetColor(void)
{
	int nCnt = 0;	//���[�v�J�E���^

	//���_�\���̃|�C���^
	VERTEX_3D * pVtx;

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff->Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//�c�̃|���S�������J��Ԃ�
	for (int z = 0; z < NUM_MESH_Z + 1; z++)
	{
		//���̃|���S�������J��Ԃ�
		for (int x = 0; x < NUM_MESH_X + 1; x++, nCnt++)
		{
			//���_�F�̐ݒ�
			pVtx[nCnt].color = Color;
		}
	}
	//�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();

}