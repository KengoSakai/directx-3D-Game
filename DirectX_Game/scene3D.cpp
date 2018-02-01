/******************************************************************
***
***		3D�`�揈��
***
***		scene3d.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "scene3d.h"
#include "manager.h"
#include "renderer.h"
#include "camera.h"
/******************************************************************
�}�N����`
*******************************************************************/
#define NUM_VERTEX (4)	//���_��
#define NUM_POLYGON (2)	//�|���S����
#define POLYGON_POSX (300)//�|���S���̕\���ʒuX
#define POLYGON_POSY (100)//�|���S���̕\���ʒuY
#define POLYGON_WIDTH (243)//�|���S���̕�
#define POLYGON_HEIGHT (432)//�|���S���̍���
/*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/*******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CScene3D::CScene3D()
{

}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CScene3D::~CScene3D()
{

}

/******************************************************************
���������������֐�
*******************************************************************/
void CScene3D::Initialize(void)
{
	//���_�쐬����
	MakeVertex();

}

/******************************************************************
�I�������֐�
*******************************************************************/
void CScene3D::Uninitialize(void)
{
	//3D�|���S���̃o�b�t�@�̔j��
	if(m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
	CScene::Release();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CScene3D::Update (void)
{

}

/******************************************************************
�|���S���`�揈���֐�
*******************************************************************/
void CScene3D::Draw(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pD3DDevice =  CManager::GetRenderer()->GetDevice();

	//���_�t�H�[�}�b�g�̐ݒ�
	pD3DDevice -> SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pD3DDevice->SetTexture(0, m_pTexture);

	//���C�g�ݒ�
	pD3DDevice->SetRenderState(D3DRS_LIGHTING,false);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pD3DDevice->SetStreamSource(0,m_pVtxBuff,0,sizeof(VERTEX_3D));

	//�|���S���̕`��
	pD3DDevice -> DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);

	//���C�g�ݒ�
	pD3DDevice->SetRenderState(D3DRS_LIGHTING,true);
}

/******************************************************************
���_�쐬�����֐�
*******************************************************************/
void CScene3D::MakeVertex(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pDevice =  CManager::GetRenderer()->GetDevice();
	
	//���_�o�b�t�@�̐���
	pDevice -> CreateVertexBuffer(
		sizeof(VERTEX_3D) * NUM_VERTEX,	//�m�ۂ���o�b�t�@�T�C�Y�i�o�C�g�j
		D3DUSAGE_WRITEONLY,				//�g�p���@
		FVF_VERTEX_3D,					//�g�p���钸�_�t�H�[�}�b�g(0�ł���)
		D3DPOOL_MANAGED,				//�o�b�t�@�ɏ������񂾕��̊Ǘ����@
		&m_pVtxBuff,					//�A�h���X�̎w��
		NULL);

	//���_�\���̃|�C���^
	VERTEX_3D* pVtx;

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff -> Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(Position.x - Size, Position.y + Size, Position.z);
	pVtx[1].pos = D3DXVECTOR3(Position.x + Size, Position.y + Size, Position.z);
	pVtx[2].pos = D3DXVECTOR3(Position.x - Size, Position.y - Size, Position.z);
	pVtx[3].pos = D3DXVECTOR3(Position.x + Size, Position.y - Size, Position.z);

	//�@�����
	pVtx[0].normal = D3DXVECTOR3(0.0f,1.0f,0.0f);
	pVtx[1].normal = D3DXVECTOR3(0.0f,1.0f,0.0f);
	pVtx[2].normal = D3DXVECTOR3(0.0f,1.0f,0.0f);
	pVtx[3].normal = D3DXVECTOR3(0.0f,1.0f,0.0f);

	//���_���W�̐F
	pVtx[0].color = D3DCOLOR_RGBA((int)Color.r, (int)Color.g, (int)Color.b, (int)Color.a);
	pVtx[1].color = D3DCOLOR_RGBA((int)Color.r, (int)Color.g, (int)Color.b, (int)Color.a);
	pVtx[2].color = D3DCOLOR_RGBA((int)Color.r, (int)Color.g, (int)Color.b, (int)Color.a);
	pVtx[3].color = D3DCOLOR_RGBA((int)Color.r, (int)Color.g, (int)Color.b, (int)Color.a);

	//�e�N�X�`���̍��W
	pVtx[0].tex = D3DXVECTOR2(0.0f,0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f,0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f,1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f,1.0f);

	m_pVtxBuff -> Unlock();
}

/******************************************************************
�e�N�X�`���ǂݍ��ݏ����֐�
*******************************************************************/
void CScene3D :: BindTexture(LPDIRECT3DTEXTURE9 pOrderTexture)
{
	m_pTexture = pOrderTexture;
}

/******************************************************************
���W�ݒ菈��
*******************************************************************/
void CScene3D :: SetPos(D3DXVECTOR3 Pos)
{
	VERTEX_3D* pVtx;

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff -> Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-Pos.x,Pos.y,Pos.z);
	pVtx[1].pos = D3DXVECTOR3(Pos.x,Pos.y,Pos.z);
	pVtx[2].pos = D3DXVECTOR3(-Pos.x,Pos.y,-Pos.z);
	pVtx[3].pos = D3DXVECTOR3(Pos.x,Pos.y,-Pos.z);

	//�o�b�t�@���A�����b�N
	m_pVtxBuff -> Unlock();
}

/******************************************************************
�s��ݒ菈��
*******************************************************************/
void CScene3D ::SetMatrix(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pDevice =  CManager::GetRenderer()->GetDevice();

	//�s��ϊ�
	D3DXMatrixIdentity(&WorldMatrix);	//�P�ʍs��
	D3DXMatrixScaling(&ScaleMatrix,Scale.x,Scale.y,Scale.z);	//�g��s��
	D3DXMatrixTranslation(&TranslationMatrix,Position.x, Position.y, Position.z);	//���s�s��
	D3DXMatrixRotationYawPitchRoll(&RotateMatrix,Rotate.y,Rotate.x,Rotate.z);	//��]�s��
	
	D3DXMatrixMultiply(&WorldMatrix,&WorldMatrix,&ScaleMatrix);
	WorldMatrix = ScaleMatrix * RotateMatrix * TranslationMatrix;

	pDevice->SetTransform(D3DTS_WORLD,&WorldMatrix);
}

void CScene3D::SetBillboard(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	////�P�ʍs��
	D3DXMatrixIdentity(&WorldMatrix);

	InverseMatrix = CManager::GetCamera()->GetViewMatrix();

	//�]�u�s��
	D3DXMatrixTranspose(&WorldMatrix, &InverseMatrix);
	WorldMatrix._14 = 0.0f;
	WorldMatrix._24 = 0.0f;
	WorldMatrix._34 = 0.0f;

	//�g��s��
	D3DXMatrixScaling(&ScaleMatrix, Scale.x, Scale.y, Scale.z);

	//���s�s��
	D3DXMatrixTranslation(&TranslationMatrix, Position.x, Position.y, Position.z);

	WorldMatrix = WorldMatrix * ScaleMatrix*TranslationMatrix;
	//���[���h�ϊ�
	pDevice->SetTransform(D3DTS_WORLD, &WorldMatrix);

}
