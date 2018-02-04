/******************************************************************
***
***		���G�t�F�N�g����
***
***		fire.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "fire.h"

/******************************************************************
�萔��`
*******************************************************************/
#define SIZE (5.0f)
#define FADE_RATE (5.0f)
#define SPEED (0.1f)

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CFire::CFire()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CFire::Initialize(D3DXVECTOR3 OrderPosition)
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
	Color = D3DXCOLOR(255.0f, 155.0f, 5.0f, 255.0f);
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CFire::Uninitialize(void)
{
	//�I�u�W�F�N�g�̔j��
	CParticleBillboard::Uninitialize();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CFire::Update(void)
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
�`�揈���֐�
*******************************************************************/
void CFire::Draw(void)
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
�I�u�W�F�N�g���������֐�
*******************************************************************/
CFire *CFire::Create(D3DXVECTOR3 OrderPosition)
{
	//�I�u�W�F�N�g�|�C���^
	CFire *pFire;

	//�C���X�^���X�̐���
	pFire = new CFire;

	//������
	pFire->Initialize(OrderPosition);

	//�e�N�X�`���ǂݍ���
	CManager::GetTextureManager()->LoadTexture(CTextureManager::TYPE_PARTICLE);

	pFire->SetObjType(OBJTYPE_FIRE);

	//�e�N�X�`����`��N���X�ɐݒ�
	pFire->BindTexture(CManager::GetTextureManager()->GetTexture(CTextureManager::TYPE_PARTICLE));

	return pFire;
}
