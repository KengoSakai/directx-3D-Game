/******************************************************************
***
***		����
***
***		.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "startButton.h"
/******************************************************************
�}�N����`
*******************************************************************/
#define FADE_RATE (2.0f)

CStartButton::CStartButton()
{

}

CStartButton::~CStartButton()
{

}

void CStartButton::Initialize(void)
{
	Position = D3DXVECTOR3(400.0f, 500.0f, 0.0f);
	WidthHeight = D3DXVECTOR3(500.0f, 100.0f, 0.0f);
	Color = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);
	FadeState = FADE_IN;
	CScene2D::Initialize();
}

void CStartButton::Uninitialize(void)
{
	CScene2D::Uninitialize();
}

void CStartButton::Update(void)
{
	CScene2D::SetColor(Color);

	if (FadeState == FADE_NONE)
	{
		return;
	}

	if (FadeState == FADE_IN)
	{
		//���l�������Ă���
		Color.a -= FADE_RATE;

		//�t�F�[�h�I��
		if (Color.a <= 0.0f)
		{
			//���l��0�ɂ���
			Color.a = 0.0f;

			//�t�F�[�h�A�E�g�̏�Ԃ�
			FadeState = FADE_OUT;
			return;
		}
	}

	else if (FadeState == FADE_OUT)
	{
		Color.a += FADE_RATE;

		if (Color.a > 255.0f)
		{
			Color.a = 255.0f;
			FadeState = FADE_IN;
			return;
		}

	}

	else
	{
		return;
	}

}

void CStartButton::Draw(void)
{
	CScene2D::Draw();
}

/******************************************************************
�I�u�W�F�N�g���������֐�
*******************************************************************/
CStartButton *CStartButton::Create(void)
{
	//�|�C���^�錾
	CStartButton *pStartButton;

	//�C���X�^���X����
	pStartButton = new CStartButton;

	//����������
	pStartButton->Initialize();

	pStartButton->SetObjType(OBJTYPE_TITLEBUTTON);
	
	CManager::GetTextureManager()->LoadTexture(CTextureManager::TYPE_STARTBUTTON);
	
	pStartButton->BindTexture(CManager::GetTextureManager()->GetTexture(CTextureManager::TYPE_STARTBUTTON));

	return pStartButton;
}
