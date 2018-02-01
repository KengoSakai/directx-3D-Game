/******************************************************************
***
***		�^�C�g������
***
***		title.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "baseScene.h"
#include "fade.h"
#include "title.h"
#include "scene.h"
#include "startButton.h"
#include "titleLogo.h"
#include "meshDome.h"
#include "meshField.h"
#include "game.h"
#include "particle.h"
#include "building.h"
/******************************************************************
�R���X�g���N�^
*******************************************************************/
CTitle::CTitle()
{

}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CTitle::~CTitle()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CTitle::Init(void)
{
	Create3D();
	Create2D();
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CTitle::Uninit(void)
{
	//�S�I�u�W�F�N�g�j��
	CScene::ReleaseAll();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
CBaseScene::SCENE_STATE CTitle::Update(void)
{
	if (CManager::GetInputKeyboard()->GetKeyPress(DIK_SPACE))
	{
		if (CManager::GetFade()->GetFadeState() == CFade::FADE_NONE)
		{
			CManager::GetFade()->SetFade(CFade::FADE_OUT);
		}
	}

	else if (CManager::GetFade()->GetFadeState() == CFade::FADE_MAX)
	{
		return CBaseScene::SCENE_GAME;
	}

	else
	{

	}

	CParticle::Create(D3DXVECTOR3((float)(rand() % 200), 10.0f, (float)(rand() % 200)));
	CParticle::Create(D3DXVECTOR3((float)(rand() % 200)*-1, 10.0f, (float)(rand() % 200)*-1));
	CParticle::Create(D3DXVECTOR3((float)(rand() % 200), 10.0f, (float)(rand() % 200)*-1));
	CParticle::Create(D3DXVECTOR3((float)(rand() % 200)*-1, 10.0f, (float)(rand() % 200)));

	return CBaseScene::SCENE_CONTINUE;
}

/******************************************************************
2D�I�u�W�F�N�g���������֐�
*******************************************************************/
void CTitle::Create2D(void)
{
	CTitleLogo::Create();

	CStartButton::Create();
}

/******************************************************************
3D�I�u�W�F�N�g���������֐�
*******************************************************************/
void CTitle::Create3D(void)
{
	//���b�V���t�B�[���h�̐���
	CMeshField::Create();

	//���b�V���h�[������
	CMeshDome::Create();

	//CBuilding::Create();
}

