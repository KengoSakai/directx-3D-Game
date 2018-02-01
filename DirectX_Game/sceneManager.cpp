#include "manager.h"
#include "sceneManager.h"
#include "title.h"
#include "game.h"
#include "result.h"

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CSceneManager::CSceneManager()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CSceneManager::Initialize(void)
{
	pBaseScene = new CGame;
	pBaseScene->Init();
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CSceneManager::Uninitalize(void)
{
	//�V�[���̔j��
	if (pBaseScene != NULL)
	{
		pBaseScene->Uninit();
		delete pBaseScene;
		pBaseScene = NULL;
	}
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CSceneManager::Update(void)
{
	//���݂̃V�[���̏�Ԃ��擾
	pBaseScene->SceneState = pBaseScene->Update();

	//�t�F�[�h�A�E�g���I�������
	if (CManager::GetFade()->GetFadeState() == CFade::FADE_MAX)
	{
		//���̃V�[�����^�C�g���Ȃ�
		if (pBaseScene->SceneState == CBaseScene::SCENE_TITLE)
		{
			Uninitalize();
			pBaseScene->SetMode(pBaseScene = new CTitle);
			return;
		}

		//���̃V�[�����Q�[���Ȃ�
		else if (pBaseScene->SceneState == CBaseScene::SCENE_GAME)
		{
			Uninitalize();
			pBaseScene->SetMode(pBaseScene = new CGame);
			return;
		}

		//���̃V�[�������U���g�Ȃ�
		else if (pBaseScene->SceneState == CBaseScene::SCENE_RESULT)
		{
			Uninitalize();
			pBaseScene->SetMode(pBaseScene = new CResult);
			return;
		}

		//��O����
		else
		{

		}
	} 
}
