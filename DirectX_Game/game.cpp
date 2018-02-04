/******************************************************************
***
***		�Q�[������
***
***		game.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "game.h"
#include "scene.h"
#include "miniMapPlayer.h"
#include "meshField.h"
#include "meshDome.h"
#include "particle.h"

#include "player.h"
#include "enemyModel.h"
#include "goalModel.h"
#include "gaugeBox.h"
#include "gaugeMeter.h"
#include "modelManager.h"
#include "miniMap.h"
#include "building.h"
#include "time.h"
#include "item.h"
#include "pause.h"
#include "cloud.h"
#include "target.h"
#include "score.h"

CScore *CGame::pScore = NULL;
/******************************************************************
�R���X�g���N�^
*******************************************************************/
CGame::CGame()
{

}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CGame::~CGame()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CGame::Init(void)
{
	//3D�I�u�W�F�N�g����
	Create3D();

	//2D�I�u�W�F�N�g����
	Create2D();
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CGame::Uninit(void)
{
	//�S�I�u�W�F�N�g�j��
	CScene::ReleaseAll();

	CParticleManager::ReleaseAll();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
CBaseScene::SCENE_STATE CGame::Update(void)
{
	//���Ԑ؂�Ȃ�
	if (pTime->GetTime() < 0 )
	{
		//�t�F�[�h���Ă��Ȃ��Ȃ�
		if (CManager::GetFade()->GetFadeState() == CFade::FADE_NONE)
		{
			//�t�F�[�h�A�E�g��ݒ�
			CManager::GetFade()->SetFade(CFade::FADE_OUT);
		}

		//�t�F�[�h�A�E�g���I��������
		else if (CManager::GetFade()->GetFadeState() == CFade::FADE_MAX)
		{
			//���̃V�[����
			return CBaseScene::SCENE_RESULT;
		}

		//��O����
		else
		{

		}
	}

	else
	{
		//�P�b���ɃI�u�W�F�N�g�𐶐�
		if (pTime->GetTime()%60==0)
		{
			/*CItem::Create(D3DXVECTOR3((float)(rand() % 200), 10.0f, (float)(rand() % 200)));
			CItem::Create(D3DXVECTOR3((float)(rand() % 200)*-1, 10.0f, (float)(rand() % 200)*-1));
			CItem::Create(D3DXVECTOR3((float)(rand() % 200), 10.0f, (float)(rand() % 200)*-1));
			CItem::Create(D3DXVECTOR3((float)(rand() % 200)*-1, 10.0f, (float)(rand() % 200)));*/
			CTarget::Create();
		}

		//�|�[�Y�{�^�������͂��ꂽ��
		/*if ()
		{
			//�|�[�Y��ʂ�\��

		}
*/
	}
	return CBaseScene::SCENE_CONTINUE;
}

/******************************************************************
2D�I�u�W�F�N�g���������֐�
*******************************************************************/
void CGame::Create2D(void)
{
	CMiniMap::Create();

	CMiniMapPlayer::Create();

	pScore = CScore::Create(CScene::OBJTYPE_SCORE);

	pTime = CTime::Create();
}

/******************************************************************
3D�I�u�W�F�N�g���������֐�
*******************************************************************/
void CGame::Create3D(void)
{
	//���b�V���t�B�[���h�̐���
	CMeshField::Create();

	//���b�V���h�[������
	CMeshDome::Create();

	//�v���C���[�̐���
	CPlayer::Create();

	//CGoalModel::Create();

	CEnemyModel::Create();

	CBuilding::Create();

	for (int Count = 0; Count < 200; Count++)
	{
		//CCloud::Create();
	}
}
