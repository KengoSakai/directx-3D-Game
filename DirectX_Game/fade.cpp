/******************************************************************
***
***		�t�F�[�h����
***
***		fade.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "fade.h"
/******************************************************************
�}�N����`
*******************************************************************/
#define FADE_RATE (5)

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CFade::CFade()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CFade::Initialize(void)
{
	Position = D3DXVECTOR3(0.0f,0.0f,0.0f);
	WidthHeight = D3DXVECTOR3(SCREEN_WIDTH,SCREEN_HEIGHT,0.0f);
	Color = D3DXCOLOR(255,255,255,0);

	FadeState = FADE_NONE;
	CScene2D::Initialize();
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CFade::Uninitialize(void)
{
	if (FadeState == FADE_NONE)
	{
		CScene2D::Uninitialize();
	}
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CFade::Update(void)
{
	CScene2D::SetColor(Color);

	if(FadeState == FADE_NONE)
	{
		return;
	}

	if(FadeState == FADE_IN)
	{
		//���l�������Ă���
		Color.a -= FADE_RATE;

		//�t�F�[�h�I��
		if(Color.a <= 0)
		{
			//���l��0�ɂ���
			Color.a = 0;

			//�t�F�[�h���Ă��Ȃ���Ԃ�
			FadeState = FADE_NONE;
			return;
		}
	}

	else if(FadeState == FADE_OUT)
	{
		Color.a += FADE_RATE;

		if(Color.a > 255)
		{
			Color.a = 255;
			FadeState = FADE_MAX;
		}
	}

	else
	{
		FadeState = FADE_IN;
		return;
	}

}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CFade::Draw(void)
{
	CScene2D::Draw();
}

/******************************************************************
�I�u�W�F�N�g���������֐�
*******************************************************************/
CFade *CFade::Create(void)
{
	//�I�u�W�F�g�|�C���^
	CFade *pFade;

	//�C���X�^���X�̐���
	pFade = new CFade;

	//����������
	pFade->Initialize();

	pFade->SetObjType(OBJTYPE_FADE);

	pFade->BindTexture(NULL);

	return pFade;
}