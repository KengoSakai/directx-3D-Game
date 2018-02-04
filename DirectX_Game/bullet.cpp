/******************************************************************
***
***		�e����
***
***		bulet.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "bullet.h"
#include "renderer.h"
#include "player.h"
#include "collision.h"
#include "fire.h"
#include "enemyModel.h"
#include "target.h"
#include "exprode.h"
/******************************************************************
�萔��`
*******************************************************************/
#define FADE_RATE (0.8f)
#define SIZE (5.0f)
#define SPEED (1.0f)

CRenderer *CBullet::m_pRenderer = NULL;
/******************************************************************
�R���X�g���N�^
*******************************************************************/
CBullet::CBullet()
{
	State = SHOT;
}

/******************************************************************
�����������֐�
*******************************************************************/
void CBullet::Initialize(D3DXVECTOR3 OrderPosition, D3DXVECTOR3 OrderVector)
{	
	Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	Size = SIZE;
	CScene3D::Initialize();
	Position = OrderPosition;
	Rotate.x = OrderVector.x;
	Rotate.z = OrderVector.z;
	Rotate.y = 0.0f;
	Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	Color = D3DXCOLOR(255.0f, 125.0f, 5.0f, 255.0f);
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CBullet::Uninitialize()
{
	CScene3D::Uninitialize();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CBullet::Update(void)
{
	Position += Rotate*SPEED;
	
	Color.a -= 1.0f;

	//�G�t�F�N�g����
	CFire::Create(Position);

	HitObject();

	if (Color.a < 0.0f)
	{
		Uninitialize();
	}
}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CBullet::Draw(void)
{	

}

/******************************************************************
�I�u�W�F�N�g���������֐�
*******************************************************************/
CBullet *CBullet::Create(D3DXVECTOR3 OrderPosition, D3DXVECTOR3 OrderVector)
{
	CBullet *pBullet;
	pBullet = new CBullet;
	pBullet->Initialize(OrderPosition, OrderVector);
	CManager::GetTextureManager()->LoadTexture(CTextureManager::TYPE_PARTICLE);
	pBullet->BindTexture(CManager::GetTextureManager()->GetTexture(CTextureManager::TYPE_PARTICLE));
	pBullet->SetObjType(OBJTYPE_BULLET);
	return pBullet;
}

/******************************************************************
�I�u�W�F�N�g���������֐�
*******************************************************************/
void CBullet::HitObject(void)
{
	//�I�u�W�F�N�g���J��Ԃ�
	for (int nCntScene = 0; nCntScene < NUM_OBJECT; nCntScene++)
	{
		//�I�u�W�F�N�g�̏��擾
		CScene *pScene = CScene::GetScene(nCntScene);

		//�I�u�W�F�N�g�̃|�C���^�[��NULL�łȂ��Ȃ�
		if (pScene != NULL)
		{
			//�I�u�W�F�N�g�̌^���擾
			CScene::OBJTYPE ObjType = pScene->GetObjType();

			//�G�ɓ���������
			if (ObjType == CScene::OBJTYPE_ENEMY)
			{
				//�I�u�W�F�N�g�|�C���^
				CEnemyModel *pEnemy= (CEnemyModel*)pScene;

				//���̓����蔻��
				if (CCollision::SphereCollision(Position, pEnemy->GetPosition()))
				{
					pEnemy->HitObject();
					CExprode::Create(Position);
					State = HIT;
					continue;
				}
			}

			//�^�[�Q�b�g�ɓ���������
			else if (ObjType == CScene::OBJTYPE_TARGET)
			{
				//�I�u�W�F�N�g�|�C���^
				CTarget *pTarget = (CTarget*)pScene;

				//���̓����蔻��
				if (CCollision::SphereCollision(Position, pTarget->GetPosition()))
				{
					pTarget->HitObject();
					for (int count = 0; count < NUM_EXPRODE; count++)
					{
						CExprode::Create(Position);
					}
					State = HIT;
					continue;
				}
			}
			else
			{

			}
		}
	}

	//�����I�u�W�F�N�g�ɓ�������
	if (State == HIT)
	{
		Uninitialize();
	}
}
