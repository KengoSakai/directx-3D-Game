/******************************************************************
***
***		�v���C���[����
***
***		player.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "game.h"
#include "item.h"
#include "input.h"
#include "particle.h"
#include "score.h"

/******************************************************************
�}�N����`
*******************************************************************/
#define NUM_GRAVITY (4.9f)	//�d��

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CItem::CItem()
{
	CManager::GetModelManager()->LoadModel(CModelManager::TYPE_ITEM);
}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CItem::~CItem()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CItem::Initialize(D3DXVECTOR3 OrderPosition)
{
	//���f���̏�����
	CModel::Initialize();

	//�����̃X�e�[�^�X
	Position = OrderPosition;	//���W
	Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//��]
	Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);	//�g�嗦
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CItem::Uninitialize(void)
{
	CModel::Uninitialize();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CItem::Update(void)
{

}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CItem::Draw(void)
{
	//�s���ݒ�
	SetMatrix();

	CModel::Draw();
}

/******************************************************************
�I�u�W�F�N�g�쐬�֐�
*******************************************************************/
CItem *CItem::Create(D3DXVECTOR3 OrderPosition)
{
	//�I�u�W�F�N�g�|�C���^
	CItem *pItem;

	//�C���X�^���X�̐���
	pItem = new CItem;

	//����������
	pItem->Initialize(OrderPosition);

	//�I�u�W�F�N�g�̌^�o�^�֐��Ăяo��
	pItem->SetObjType(OBJTYPE_ITEM);

	//�o�b�t�@���𑗂�
	pItem->BindBuff(CManager::GetModelManager()->GetMaterialBuffer(CModelManager::TYPE_ITEM));

	//�v�f���𑗂�
	pItem->BindMaterials(CManager::GetModelManager()->GetNumMaterials(CModelManager::TYPE_ITEM));

	//���b�V�����𑗂�
	pItem->BindMesh(CManager::GetModelManager()->GetMesh(CModelManager::TYPE_ITEM));

	pItem->BindTexture(NULL);

	return pItem;
}


/******************************************************************
�ʒu���擾�֐�
*******************************************************************/
D3DXVECTOR3 CItem::GetPosition(void)
{
	return Position;
}

void CItem::Hit(OBJTYPE Type)
{
	for (int a = 0; a < 20; a++)
	{
		CParticle::Create(Position);
	}

	if (Type == OBJTYPE_PLAYER)
	{
		//�X�R�A�̉��Z
	//	CGame::GetScore()->AddScore(10);
	}

	else if (Type == OBJTYPE_ENEMY)
	{
	//	CGame::GetOtherPlayerScore()->AddScore(10);
	}

	else
	{

	}
	//�A�C�e���̔j��
	Uninitialize();
}
