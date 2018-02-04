/******************************************************************
***
***		���j����
***
***		exprode.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "exprode.h"
#include "manager.h"
#include "renderer.h"

/******************************************************************
�萔��`
*******************************************************************/
#define SIZE (5.0f)
#define FADE_RATE (2.0f)
#define SPEED (0.5f)

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CExprode::CExprode()
{

}

/******************************************************************
����������
*******************************************************************/
void CExprode::Initialize(D3DXVECTOR3 OrderPosition)
{
	//���_�o�b�t�@�̏�����
	CParticleBillboard::Initialize();

	//�p�x
	Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	OrderPosition.y = 5.0f;

	//�g�嗦
	Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

	//�T�C�Y
	Size = SIZE;

	//���_�o�b�t�@���Đݒ�
	CParticleBillboard::SetRotate(D3DXVECTOR3(0.0f, 0.0f, 0.0f), Size);

	//�G�~�b�^�[
	EmitterPosition = OrderPosition;

	//�p�x�̐ݒ�
	Rotate.x = cosf((float)rand());
	Rotate.y = sinf((float)rand());
	Rotate.z = cosf((float)rand());

	//�F�̏�����
	Color = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);
}

/******************************************************************
�I������
*******************************************************************/
void CExprode::Uninitialize(void)
{
	//�I�u�W�F�N�g�̔j��
	CParticleBillboard::Uninitialize();
}

/******************************************************************
�X�V����
*******************************************************************/
void CExprode::Update(void)
{
	//�G�~�b�^�[�̈ړ�
	EmitterPosition += Rotate * SPEED;

	//���l�̌��Z
	Color.a -= FADE_RATE;

	//���_�o�b�t�@�̐F�ݒ�
	SetColor(Color);

	if (Color.a < 0.0f)
	{
		//�I������
		Uninitialize();
	}
}

/******************************************************************
�`�揈��
*******************************************************************/
void CExprode::Draw(void)
{
	//���u�����f�B���O
	CManager::GetRenderer()->SetAlphaBlend();

	//�r���{�[�h�ݒ�
	CParticleBillboard::SetBillboard();

	//�`��
	CParticleBillboard::Draw();

	//���u�����f�B���O����
	CManager::GetRenderer()->SetDefaultBrend();

}

/******************************************************************
�I�u�W�F�N�g��������
*******************************************************************/
CExprode *CExprode::Create(D3DXVECTOR3 OrderPosition)
{
	CExprode *pExprode;


	//�C���X�^���X����
	pExprode = new CExprode;

	//������
	pExprode->Initialize(OrderPosition);

	//�e�N�X�`���ݒ�
	pExprode->BindTexture(NULL);

	pExprode->SetObjType(OBJTYPE_PARTICLE);

	return pExprode;
}