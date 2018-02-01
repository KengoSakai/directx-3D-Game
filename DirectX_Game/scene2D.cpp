/******************************************************************
***
***		�QD�`�揈��
***
***		scene2D.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "scene2D.h"
#include "manager.h"
#include "renderer.h"

/******************************************************************
�}�N����`
*******************************************************************/

#define NUM_VERTEX (4)
#define NUM_POLYGON (2)
/******************************************************************
�\���̒�`
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
CScene2D :: CScene2D ()
{

}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CScene2D :: ~CScene2D ()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CScene2D :: Initialize(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//�����l�ݒ�
	Scale.x = 1.0f;
	Scale.y = 1.0f;
	Scale.z = 0.0f;

	Rotate.x = 0.0f;
	Rotate.y = 0.0f;
	Rotate.z = 0.0f;
	m_pTexture = NULL;

	//���_�o�b�t�@�̐���
	pDevice -> CreateVertexBuffer(
		sizeof(VERTEX_2D) * NUM_VERTEX,	//�m�ۂ���o�b�t�@�T�C�Y�i�o�C�g�j
		D3DUSAGE_WRITEONLY,				//�g�p���@
		FVF_VERTEX_2D,					//�g�p���钸�_�t�H�[�}�b�g(0�ł���)
		D3DPOOL_MANAGED,				//�o�b�t�@�ɏ������񂾕��̊Ǘ����@
		&m_pVtxBuff,					//�A�h���X�̎w��
		NULL);

	VERTEX_2D* pVtx;

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff -> Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(Position.x, Position.y,0.0f);										//(X.Y.Z)
	pVtx[1].pos = D3DXVECTOR3(Position.x+WidthHeight.x, Position.y,0.0f);						//(X.Y.Z)
	pVtx[2].pos = D3DXVECTOR3(Position.x, Position.y+ WidthHeight.y,0.0f);					//(X.Y.Z)
	pVtx[3].pos = D3DXVECTOR3(Position.x+ WidthHeight.x, Position.y+ WidthHeight.y,0.0f);		//(X.Y.Z)

	//���_�t���O
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_���W�̐F
	pVtx[0].col = D3DCOLOR_RGBA(255,255,255,255);
	pVtx[1].col = D3DCOLOR_RGBA(255,255,255,255);
	pVtx[2].col = D3DCOLOR_RGBA(255,255,255,255);
	pVtx[3].col = D3DCOLOR_RGBA(255,255,255,255);

	//�e�N�X�`���̍��W
	pVtx[0].tex = D3DXVECTOR2(0.0f,0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f,0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f,1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f,1.0f);

	//�o�b�t�@�̃A�����b�N
	m_pVtxBuff -> Unlock();
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CScene2D :: Uninitialize(void)
{
	//���_�o�b�t�@�̔j��
	if(m_pVtxBuff != NULL)
	{
		m_pVtxBuff -> Release();
		m_pVtxBuff = NULL;
	}

	//�V�[���j��
	CScene::Release();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CScene2D::Update(void)
{

}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CScene2D :: Draw (void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D | D3DFVF_TEX1);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice -> SetStreamSource(
		0,
		m_pVtxBuff,
		0,						//�f�[�^�̃I�t�Z�b�g
		sizeof(VERTEX_2D)		//�X�g���C�h�ʁi�o�C�g�j
		);

	//�e�N�X�`���̐ݒ�
	pDevice -> SetTexture(0,m_pTexture);

	// �|���S���̕`��
	pDevice -> DrawPrimitive(
		D3DPT_TRIANGLESTRIP,
		0,
		NUM_POLYGON);
}

/******************************************************************
�e�N�X�`�����W�ݒ菈���֐�
*******************************************************************/
void CScene2D :: SetTexPos(D3DXVECTOR3 TexPos , D3DXVECTOR3 TexWh)
{
	VERTEX_2D* pVtx;
	
	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff -> Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//�e�N�X�`���̍��W
	pVtx[0].tex = D3DXVECTOR2(TexPos.x,TexPos.y);
	pVtx[1].tex = D3DXVECTOR2(TexPos.x + TexWh.x,TexPos.y);
	pVtx[2].tex = D3DXVECTOR2(TexPos.x, TexWh.y);
	pVtx[3].tex = D3DXVECTOR2(TexPos.x + TexWh.x , TexWh.y);

	//�o�b�t�@�̃A�����b�N
	m_pVtxBuff -> Unlock();
}

/******************************************************************
���_�F�ݒ菈���֐�
*******************************************************************/
void CScene2D :: SetColor(D3DXCOLOR OrderColor)
{
	VERTEX_2D* pVtx;
	
	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff -> Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//�e�N�X�`���̍��W
	pVtx[0].col = D3DCOLOR_RGBA((int)OrderColor.r,(int)OrderColor.g,(int)OrderColor.b,(int)OrderColor.a);
	pVtx[1].col = D3DCOLOR_RGBA((int)OrderColor.r,(int)OrderColor.g,(int)OrderColor.b,(int)OrderColor.a);
	pVtx[2].col = D3DCOLOR_RGBA((int)OrderColor.r,(int)OrderColor.g,(int)OrderColor.b,(int)OrderColor.a);
	pVtx[3].col = D3DCOLOR_RGBA((int)OrderColor.r,(int)OrderColor.g,(int)OrderColor.b,(int)OrderColor.a);

	//�o�b�t�@�̃A�����b�N
	m_pVtxBuff -> Unlock();
}

void CScene2D::SetPosition(void)
{
	VERTEX_2D* pVtx;

	//�o�b�t�@�����b�N���ĉ��z�A�h���X���擾����
	m_pVtxBuff->Lock(
		0,				//�͈͎w��
		0,
		(void**)&pVtx,	//���z�A�h���X�̎擾
		0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(Position.x, Position.y, 0.0f);										//(X.Y.Z)
	pVtx[1].pos = D3DXVECTOR3(Position.x + WidthHeight.x, Position.y, 0.0f);						//(X.Y.Z)
	pVtx[2].pos = D3DXVECTOR3(Position.x, Position.y + WidthHeight.y, 0.0f);					//(X.Y.Z)
	pVtx[3].pos = D3DXVECTOR3(Position.x + WidthHeight.x, Position.y + WidthHeight.y, 0.0f);		//(X.Y.Z)
																									//�o�b�t�@�̃A�����b�N
	m_pVtxBuff->Unlock();
}

/******************************************************************
�e�N�X�`���ǂݍ��ݏ����֐�
*******************************************************************/
void CScene2D :: BindTexture(LPDIRECT3DTEXTURE9 pOrderTexture)
{
	m_pTexture = pOrderTexture;
}
