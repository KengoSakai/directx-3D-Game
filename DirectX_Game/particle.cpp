/******************************************************************
***
***		�p�[�e�B�N������
***
***		particle.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "particle.h"
#include "camera.h"
#include "DebugFont.h"
/******************************************************************
�}�N����`
******************************************************************/
#define SPEED (0.1f)
#define FADE_RATE (2.0f)
#define SIZE (5.0f)
/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/
CRenderer *CParticle::m_pRenderer = NULL;

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CParticle::CParticle()
{

}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CParticle :: ~CParticle()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CParticle::Initialize(D3DXVECTOR3 Pos)
{
	//�p�[�e�B�N��������
	CParticleBillboard::Initialize();

	Color = D3DXCOLOR(255.0f, 155.0f, 55.0f, 255.0f);
	Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	Size = SIZE;
	CParticleBillboard::SetRotate(D3DXVECTOR3(0.0f, 0.0f, 0.0f), Size);

	EmitterPosition = Pos;
	Rotate.x = cosf((float)rand());
	Rotate.y = sinf((float)rand());
	Rotate.z = cosf((float)rand());
	
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CParticle::Uninitialize(void)
{
	//�I�u�W�F�N�g�̔j��
	CParticleBillboard::Uninitialize();
}

/******************************************************************
�X�V�����֐�z
*******************************************************************/
void CParticle::Update(void)
{
	EmitterPosition += Rotate * SPEED;
	//EmitterPosition.y += 0.5f;
	//���l��������
	Color.a -= FADE_RATE;

	CParticleBillboard::SetColor(Color);
	
	//���l��0�����ɂȂ�����
	if (Color.a < 0)
	{
		//�p�[�e�B�N���̔j��
		Uninitialize();
	}
}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CParticle::Draw(void)
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
CParticle *CParticle::Create(D3DXVECTOR3 EmitterPosition)
{
	//�I�u�W�F�N�g�|�C���^
	CParticle *pParticle;

	//�C���X�^���X�̐���
	pParticle = new CParticle;

	//�������֐��Ăяo��
	pParticle->Initialize(EmitterPosition);

	CManager::GetTextureManager()->LoadTexture(CTextureManager::TYPE_PARTICLE);

	//�e�N�X�`�������蓖�Ă�
	pParticle->BindTexture(CManager::GetTextureManager()->GetTexture(CTextureManager::TYPE_PARTICLE));

	return pParticle;
}
