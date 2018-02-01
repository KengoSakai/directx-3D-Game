/******************************************************************
***
***		��������
***
***		number.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "main.h"
#include "manager.h"
#include "textureManager.h"
#include "renderer.h"
#include "number.h"
#include "score.h"

/******************************************************************
�}�N����`
*******************************************************************/
#define NUM_VERTEX (4)
#define NUM_POLYGON (2)

#define POLYGON_POSX (500)											//�|���S���̕\���ʒuX
#define POLYGON_POSY (10)											//�|���S���̕\���ʒuY
#define POLYGON_WIDTH (30)											//�|���S���̕�
#define POLYGON_HEIGHT (100)										//�|���S���̍���
#define POLYGON_SCALE (30.0f)
/******************************************************************
�\���̒�`�܂��̓N���X��`
*******************************************************************/


/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/
CRenderer *CNumber::pRenderer = NULL;

//�R���X�g���N�^
CNumber::CNumber()
{
	CManager::GetTextureManager()->LoadTexture(CTextureManager::TYPE_NUMBER);

	pTexture = CManager::GetTextureManager()->GetTexture(CTextureManager::TYPE_NUMBER);

}

//�f�X�g���N�^
CNumber :: ~CNumber()
{

}

//�����������֐�
HRESULT CNumber::Init(int Digit, D3DXVECTOR3 OrderPosition)
{
	Position = OrderPosition;	//���W
	Rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//�p�x
	Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0);			//�g�嗦

	//���_�o�b�t�@����
	MakeVertex(Digit);

	return S_OK;
}

//�I�������֐�
void CNumber::Uninit(void)
{
	//�o�b�t�@��NULL�łȂ��Ȃ�
	if (pVtxBuff != NULL)
	{
		//�o�b�t�@�̊J��
		pVtxBuff->Release();
		pVtxBuff = NULL;
	}
}

//�X�V�����֐�
void CNumber::Update(void)
{

}

//�`�揈���֐�
void CNumber::Draw(void)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//�����_�[�X�e�[�g�̏�Ԏ擾
	pRenderer = CManager::GetRenderer();

	//�s��ϊ�
	SetMatrix();

	//Z�o�b�t�@�̐ݒ�
	pRenderer->SetzBuff();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(
		0,
		pVtxBuff,
		0,						//�f�[�^�̃I�t�Z�b�g
		sizeof(VERTEX_2D)		//�X�g���C�h�ʁi�o�C�g�j
	);

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D | D3DFVF_TEX1);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, pTexture);

	//�|���S���̕`��
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,
		0,
		NUM_POLYGON);

	pRenderer->SetDefaultBrend();
}

//�I�u�W�F�N�g���������֐�
CNumber *CNumber::Create(int Digit, D3DXVECTOR3 OrderPosition)
{
	//�|�C���^�錾
	CNumber *pNumber;

	//�C���X�^���X�̐���
	pNumber = new CNumber;

	//����������
	pNumber->Init(Digit, OrderPosition);

	
	return pNumber;
}

//�\�������ݒ菈���֐�
void CNumber::SetNumber(int Number)
{
	//�e�N�X�`�����W�̐ݒ�
	VERTEX_2D* pVtx;

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	pVtxBuff->Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//�e�N�X�`���̍��W
	pVtx[0].tex = D3DXVECTOR2((float)Number / 10.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2((float)Number / 10.0f + 0.1f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2((float)Number / 10.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2((float)Number / 10.0f + 0.1f, 1.0f);

	//�o�b�t�@�̃A�����b�N
	pVtxBuff->Unlock();
}

//�s��ݒ菈���֐�
void CNumber::SetMatrix(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//�P�ʍs��
	D3DXMatrixIdentity(&mtxWorld);

	//�g��s��
	D3DXMatrixScaling(&mtxScale, Scale.x, Scale.y, Scale.z);

	//���s�s��
	D3DXMatrixTranslation(&mtxTrans, Position.x, Position.y, Position.z);

	//��]�s��
	D3DXMatrixRotationYawPitchRoll(&mtxRot,
		D3DXToRadian(Rot.y),
		D3DXToRadian(Rot.x),
		D3DXToRadian(Rot.z));

	D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxScale);
	mtxWorld = mtxScale * mtxRot * mtxTrans;
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);
}

//���_�o�b�t�@���������֐�
void CNumber::MakeVertex(int Digit)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_2D) * NUM_VERTEX,	//�m�ۂ���o�b�t�@�T�C�Y�i�o�C�g�j
		D3DUSAGE_WRITEONLY,				//�g�p���@
		FVF_VERTEX_2D,					//�g�p���钸�_�t�H�[�}�b�g(0�ł���)
		D3DPOOL_MANAGED,				//�o�b�t�@�ɏ������񂾕��̊Ǘ����@
		&pVtxBuff,					//�A�h���X�̎w��
		NULL);

	VERTEX_2D* pVtx;

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	pVtxBuff->Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(Position.x - (Digit * POLYGON_SCALE), Position.y, -10.0f);										//(X.Y.Z)
	pVtx[1].pos = D3DXVECTOR3(Position.x + POLYGON_WIDTH - (Digit * POLYGON_SCALE), Position.y, -10.0f);						//(X.Y.Z)
	pVtx[2].pos = D3DXVECTOR3(Position.x - (Digit * POLYGON_SCALE), Position.y + POLYGON_HEIGHT, -10.0f);						//(X.Y.Z)
	pVtx[3].pos = D3DXVECTOR3(Position.x + POLYGON_WIDTH - (Digit * POLYGON_SCALE), Position.y + POLYGON_HEIGHT, -10.0f);		//(X.Y.Z)

																																//���_�t���O
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_���W�̐F
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`���̍��W
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//�o�b�t�@�̃A�����b�N
	pVtxBuff->Unlock();

}
