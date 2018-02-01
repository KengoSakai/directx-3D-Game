/******************************************************************
***
***		�p�[�e�B�N���r���{�[�h����
***
***		particleBillboard.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "particleBillboard.h"
#include "camera.h"
//#include "shader.h"
/******************************************************************
�}�N����`
*******************************************************************/
#define NUM_VERTEX (4)	//���_��
#define NUM_POLYGON (2)	//�|���S����
/*******************************************************************/

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/*******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CParticleBillboard::CParticleBillboard()
{
	Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CParticleBillboard::~CParticleBillboard()
{

}

/******************************************************************
���������������֐�
*******************************************************************/
void CParticleBillboard::Initialize(void)
{
	Color = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);
	Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	Scale = D3DXVECTOR3(10.0f, 10.0f, 10.0f);

	//���_�쐬����
	MakeVertex();
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CParticleBillboard::Uninitialize(void)
{

	//3D�|���S���̃o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//�V�[���j��
	CParticleManager::Release();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CParticleBillboard::Update(void)
{

}

/******************************************************************
�|���S���`�揈���֐�
*******************************************************************/
void CParticleBillboard::Draw(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pD3DDevice = CManager::GetRenderer()->GetDevice();
	
	//���_�t�H�[�}�b�g�̐ݒ�
	pD3DDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pD3DDevice->SetTexture(0, m_pTexture);

	//���C�g�ݒ�
	pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pD3DDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//�|���S���̕`��
	pD3DDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, NUM_POLYGON);

	//���C�g�ݒ�
	pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
}

/******************************************************************
���_�쐬�����֐�
*******************************************************************/
void CParticleBillboard::MakeVertex(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_3D) * NUM_VERTEX,	//�m�ۂ���o�b�t�@�T�C�Y�i�o�C�g�j
		D3DUSAGE_WRITEONLY,				//�g�p���@
		FVF_VERTEX_3D,					//�g�p���钸�_�t�H�[�}�b�g(0�ł���)
		D3DPOOL_MANAGED,				//�o�b�t�@�ɏ������񂾕��̊Ǘ����@
		&m_pVtxBuff,					//�A�h���X�̎w��
		NULL);

	//���_�\���̃|�C���^
	VERTEX_3D* pVtx;

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff->Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-10.0f, 0.0f, 10.0f);
	pVtx[1].pos = D3DXVECTOR3(10.0f, 0.0f, 10.0f);
	pVtx[2].pos = D3DXVECTOR3(-10.0f, 0.0f, -10.0f);
	pVtx[3].pos = D3DXVECTOR3(10.0f, 0.0f, -10.0f);

	//�@�����
	pVtx[0].normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//���_���W�̐F
	pVtx[0].color = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].color = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].color = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].color = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`���̍��W
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	m_pVtxBuff->Unlock();
}

/******************************************************************
�e�N�X�`���ǂݍ��ݏ����֐�
*******************************************************************/
void CParticleBillboard::BindTexture(LPDIRECT3DTEXTURE9 pOrderTexture)
{
	m_pTexture = pOrderTexture;
}

/******************************************************************
���_�F�ݒ菈���֐�
*******************************************************************/
void CParticleBillboard::SetColor(D3DXCOLOR OrderColor)
{
	VERTEX_3D* pVtx;

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff->Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//�e�N�X�`���̍��W
	pVtx[0].color = D3DCOLOR_RGBA((int)OrderColor.r, (int)OrderColor.g, (int)OrderColor.b, (int)OrderColor.a);
	pVtx[1].color = D3DCOLOR_RGBA((int)OrderColor.r, (int)OrderColor.g, (int)OrderColor.b, (int)OrderColor.a);
	pVtx[2].color = D3DCOLOR_RGBA((int)OrderColor.r, (int)OrderColor.g, (int)OrderColor.b, (int)OrderColor.a);
	pVtx[3].color = D3DCOLOR_RGBA((int)OrderColor.r, (int)OrderColor.g, (int)OrderColor.b, (int)OrderColor.a);

	//�o�b�t�@�̃A�����b�N
	m_pVtxBuff->Unlock();
}

/******************************************************************
��]�����֐�
*******************************************************************/
void CParticleBillboard::SetRotate(D3DXVECTOR3 Position, float Size)
{
	VERTEX_3D* pVtx;

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff->Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(Position.x- Size, Position.y + Size, Position.z);
	pVtx[1].pos = D3DXVECTOR3(Position.x+ Size, Position.y + Size, Position.z);
	pVtx[2].pos = D3DXVECTOR3(Position.x - Size, Position.y - Size, Position.z);
	pVtx[3].pos = D3DXVECTOR3(Position.x + Size, Position.y - Size, Position.z);

	//�o�b�t�@�̃A�����b�N
	m_pVtxBuff->Unlock();
}

void CParticleBillboard::SetBillboard(void)
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
	D3DXMatrixTranslation(&TranslationMatrix, EmitterPosition.x, EmitterPosition.y, EmitterPosition.z);

	WorldMatrix = WorldMatrix * ScaleMatrix*TranslationMatrix;
	//���[���h�ϊ�
	pDevice->SetTransform(D3DTS_WORLD, &WorldMatrix);
}

