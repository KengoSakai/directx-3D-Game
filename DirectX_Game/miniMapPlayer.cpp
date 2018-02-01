/******************************************************************
***
***		�~�j�}�b�v�v���C���[����
***
***		miniMapPlayer.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "miniMapPlayer.h"
#include "player.h"
#include "miniMap.h"
/******************************************************************
�R���X�g���N�^
*******************************************************************/
CMiniMapPlayer::CMiniMapPlayer()
{

}

/******************************************************************
����������
*******************************************************************/
void CMiniMapPlayer::Initialize(void)
{
	//�I�u�W�F�N�g���J��Ԃ�
	for (int nCntScene = 0; nCntScene < 100; nCntScene++)
	{
		//�I�u�W�F�N�g�̏��擾
		CScene *pScene;
		pScene = CScene::GetScene(nCntScene);

		//�I�u�W�F�N�g�̃|�C���^�[��NULL�łȂ��Ȃ�
		if (pScene != NULL)
		{
			//�I�u�W�F�N�g�̌^���擾
			CScene::OBJTYPE ObjType;
			ObjType = pScene->GetObjType();

			if (ObjType == CScene::OBJTYPE_MINIMAP)
			{
				//�I�u�W�F�N�g�|�C���^
				CMiniMap *pMiniMap = (CMiniMap*)pScene;
				Position.x = (pMiniMap->GetPosition().x + pMiniMap->GetWidthHeight().x*0.5f);
				Position.y = (pMiniMap->GetPosition().y + pMiniMap->GetWidthHeight().y*0.5f);
				Position.z = 0.0f;
			}
		}
	}
	WidthHeight = D3DXVECTOR3(10.0f, 10.0f, 0.0f);
	CScene2D::Initialize();
}

/******************************************************************
�I������
*******************************************************************/
void CMiniMapPlayer::Uninitalize(void)
{
	CScene2D::Uninitialize();
}

/******************************************************************
�X�V����
*******************************************************************/
void CMiniMapPlayer::Update(void)
{
	//�I�u�W�F�N�g���J��Ԃ�
	for (int nCntScene = 0; nCntScene < 100; nCntScene++)
	{
		//�I�u�W�F�N�g�̏��擾
		CScene *pScene;
		pScene = CScene::GetScene(nCntScene);

		//�I�u�W�F�N�g�̃|�C���^�[��NULL�łȂ��Ȃ�
		if (pScene != NULL)
		{
			//�I�u�W�F�N�g�̌^���擾
			CScene::OBJTYPE ObjType;
			ObjType = pScene->GetObjType();

			//�w�肵���I�u�W�F�N�g�Ȃ�
			if (ObjType == CScene::OBJTYPE_PLAYER)
			{
				//�I�u�W�F�N�g�|�C���^
				CPlayer *pPlayer = (CPlayer*)pScene;

				//�v���C���[�̍��W�擾
				Position.z = 0.0f;
			//	Position.x = pPlayer->GetPosition().x;
				//Position.y = -pPlayer->GetPosition().z;
			}
		}
	}
	Position.x++;
}

/******************************************************************
�`�揈��
*******************************************************************/
void CMiniMapPlayer::Draw(void)
{
	CScene2D::Draw();
}

/******************************************************************
�I�u�W�F�N�g��������
*******************************************************************/
CMiniMapPlayer *CMiniMapPlayer::Create(void)
{
	CMiniMapPlayer * pMiniMapPlayer;
	pMiniMapPlayer = new CMiniMapPlayer;
	pMiniMapPlayer->Initialize();
	CManager::GetTextureManager()->LoadTexture(CTextureManager::TYPE_MINIMAPPLAYER);
	pMiniMapPlayer->BindTexture(CManager::GetTextureManager()->GetTexture(CTextureManager::TYPE_MINIMAPPLAYER));
	pMiniMapPlayer->SetObjType(OBJTYPE_MINIMAPPLAYER);
	
	return pMiniMapPlayer;
}


