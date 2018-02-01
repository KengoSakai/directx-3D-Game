/******************************************************************
***
***		���b�V���t�B�[���h����
***
***		MeshField.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "meshDraw.h"

/******************************************************************
�}�N����`
*******************************************************************/
#define NUM_VERTEX (4)	//���_��
#define NUM_POLYGON (2)
#define NUM_MESH_X (150)			//���̃}�X��
#define NUM_MESH_Z (150)			//�c�̃}�X��

#define NUM_MESH_VERTEX ((NUM_MESH_X+1) * (NUM_MESH_Z+1))								//���_�̑���
#define NUM_MESH_INDEX (((NUM_MESH_X +1)*2) + ((NUM_MESH_Z-1) * (NUM_MESH_X+2)*2) )
#define NUM_MESH_POLYGON (((NUM_MESH_X * NUM_MESH_Z * NUM_POLYGON) + (4 * (NUM_MESH_Z-1))))	//���|���S����

#define MESH_SIZE (10.0f)

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CMeshDraw::CMeshDraw()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CMeshDraw::Initialize(void)
{
	//���_���쐬����
	MakeVertex();

	//�C���f�b�N�X�o�b�t�@�ݒ菈��
	MakeIndex();

	//�X�e�[�^�X�̏�����
	Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�p�x
	Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);		//�g�嗦
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CMeshDraw::Uninitialize(void)
{
	//�o�b�t�@�̔j��
	if (pVertexBuffer != NULL)
	{
		pVertexBuffer->Release();
		pVertexBuffer = NULL;
	}

	//�C���f�b�N�X�o�b�t�@�̔j��
	if (pIndexBuffer != NULL)
	{
		pIndexBuffer->Release();
		pIndexBuffer = NULL;
	}

	CScene::Release();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CMeshDraw::Update(void)
{

}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CMeshDraw::Draw(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pD3DDevice = CManager::GetRenderer()->GetDevice();

	//�s��ݒ菈��
	SetMatrix();

	//���_�t�H�[�}�b�g�̐ݒ�
	pD3DDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pD3DDevice->SetTexture(0, pTexture);

	//���C�g�ݒ�
	pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pD3DDevice->SetStreamSource(0, pVertexBuffer, 0, sizeof(VERTEX_3D));

	pD3DDevice->SetIndices(pIndexBuffer);

	//�|���S���̕`��
	pD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP,	//�`��^�C�v
		0,					//�ŏ��̒��_�C���f�b�N�X�ԍ�
		0,					//�ŏ��̒��_�C���f�b�N�X�ԍ�
		NUM_MESH_VERTEX,	//���_����
		0,					//�n�߂̃C���f�b�N�X�ԍ�
		NUM_MESH_POLYGON);	//�|���S���̑���

							//���C�g�ݒ�
	pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
}

/******************************************************************
���_�ݒ菈���֐�
*******************************************************************/
void CMeshDraw::MakeVertex(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//�ϐ��錾
	int nCnt = 0;	//���[�v�J�E���^

	D3DXVECTOR2 BuffTex;
	BuffTex.x = 0.0f;
	BuffTex.y = 1.0f;

	D3DXVECTOR3 BuffPos(-(MESH_SIZE*0.5f) * NUM_MESH_X,
		0.0f,
		(MESH_SIZE*0.5f)*NUM_MESH_Z);

	//���_�\���̃|�C���^
	VERTEX_3D * pVtx;

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_3D) * NUM_MESH_VERTEX,	//�m�ۂ���o�b�t�@�T�C�Y�i�o�C�g�j
		D3DUSAGE_WRITEONLY,				//�g�p���@
		FVF_VERTEX_3D,					//�g�p���钸�_�t�H�[�}�b�g(0�ł���)
		D3DPOOL_MANAGED,				//�o�b�t�@�ɏ������񂾕��̊Ǘ����@
		&pVertexBuffer,					//�A�h���X�̎w��
		NULL);

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	pVertexBuffer->Lock(
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
			if (nCnt != 0 && nCnt % (NUM_MESH_X + 1) == 0)
			{
				//�c�����炷
				BuffPos.z -= MESH_SIZE;
				BuffPos.x = -(MESH_SIZE*0.5f)*NUM_MESH_X;
				BuffTex.x = 0.0f;
				BuffTex.y++;
			}
			//���_���W�̐ݒ�
			pVtx[nCnt].pos = D3DXVECTOR3(BuffPos.x, BuffPos.y, BuffPos.z);

			//�@�����
			pVtx[nCnt].normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

			//���_�F�̐ݒ�
			pVtx[nCnt].color = D3DCOLOR_RGBA(255, 255, 255, 255);

			//�e�N�X�`���̍��W�ݒ�
			pVtx[nCnt].tex = D3DXVECTOR2(BuffTex.x, BuffTex.y);

			//���ɂ��炷
			BuffPos.x += MESH_SIZE;
			BuffTex.x++;
		}
	}
	//�o�b�t�@���A�����b�N
	pVertexBuffer->Unlock();
}

/******************************************************************
�C���f�b�N�X�o�b�t�@�ݒ菈���֐�
*******************************************************************/
void CMeshDraw::MakeIndex(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//�C���f�b�N�X�o�b�t�@�p�|�C���^
	WORD *pIndex = NULL;
	int nIndex = NUM_MESH_X + 1;
	int nIndexCnt = nIndex;
	int nCntSec = 0;

	//�C���f�b�N�X�o�b�t�@�̐���
	pDevice->CreateIndexBuffer(
		sizeof(WORD) * NUM_MESH_INDEX,	//�m�ۂ���o�b�t�@�T�C�Y�i�o�C�g�j
		D3DUSAGE_WRITEONLY,				//�g�p���@
		D3DFMT_INDEX16,					//�g�p���钸�_�t�H�[�}�b�g(0�ł���)
		D3DPOOL_MANAGED,				//�o�b�t�@�ɏ������񂾕��̊Ǘ����@
		&pIndexBuffer,					//�A�h���X�̎w��
		NULL);

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	pIndexBuffer->Lock(
		0,				//�͈͎w��
		0,
		(void**)&pIndex,	//���z�A�h���X�̎擾
		0);

	//�y�̐������J��Ԃ�
	for (int nCnt = 0; nCnt < NUM_MESH_INDEX; nCnt += 2, nCntSec++)
	{
		//�[�ɗ�����
		if (nCntSec != 0 && nCntSec % (NUM_MESH_X + 1) == 0)
		{
			//�O�Ɠ����_��ł�
			pIndex[nCnt] = pIndex[nCnt - 1];

			nIndexCnt += NUM_MESH_X + 1;
			nIndex = nIndexCnt;
			pIndex[nCnt + 1] = nIndex;
			nCnt += 2;
		}

		//�C���f�b�N�X�o�b�t�@��ݒ�
		pIndex[nCnt] = nIndex;
		pIndex[nCnt + 1] = pIndex[nCnt] - (NUM_MESH_X + 1);
		nIndex++;
	}
	pIndex = NULL;
	//�o�b�t�@���A�����b�N
	pIndexBuffer->Unlock();
}

/******************************************************************
�s��ݒ菈���֐�
*******************************************************************/
void CMeshDraw::SetMatrix(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//�P�ʍs��
	D3DXMatrixIdentity(&WorldMatrix);
	
	//�g��s��
	D3DXMatrixScaling(&ScaleMatrix, Scale.x, Scale.y, Scale.z);

	//���s�s��
	D3DXMatrixTranslation(&TranslationMatrix, Position.x, Position.y, Position.z);

	//��]�s��
	D3DXMatrixRotationYawPitchRoll(&RotateMatrix,
		D3DXToRadian(Rotate.y),
		D3DXToRadian(Rotate.x),
		D3DXToRadian(Rotate.z));

	WorldMatrix = RotateMatrix * ScaleMatrix *   TranslationMatrix;

	pDevice->SetTransform(D3DTS_WORLD, &WorldMatrix);
}

/******************************************************************
�e�N�X�`���ǂݍ��ݏ����֐�
*******************************************************************/
void CMeshDraw::BindTexture(LPDIRECT3DTEXTURE9 pOrderTexture)
{
	pTexture = pOrderTexture;
}
