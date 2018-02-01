#include "manager.h"
#include "enemyModel.h"
#include "particle.h"
#include "bullet.h"
/******************************************************************
�R���X�g���N�^
*******************************************************************/
CEnemyModel::CEnemyModel()
{
	CManager::GetModelManager()->LoadModel(CModelManager::TYPE_ENEMY);
}

/******************************************************************
�����������֐�
*******************************************************************/
void CEnemyModel::Initialize(void)
{
	Position = D3DXVECTOR3(0.0f,10.0f,20.0f);
	Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CEnemyModel::Uninitialize(void)
{
	CModel::Uninitialize();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CEnemyModel::Update(void)
{

}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CEnemyModel::Draw(void)
{
	CModel::SetMatrix();
	CModel::Draw();
}

/******************************************************************
�I�u�W�F�N�g��������
*******************************************************************/
CEnemyModel *CEnemyModel::Create(void)
{
	//�I�u�W�F�N�g�|�C���^
	CEnemyModel *pEnemyModel;

	//�C���X�^���X����
	pEnemyModel = new CEnemyModel;

	//����������
	pEnemyModel->Initialize();

	//�R���e�i�N���X�ɃI�u�W�F�N�g�̌^��ݒ�
	pEnemyModel->SetObjType(OBJTYPE_ENEMY);

	//�}�e���A���o�b�t�@�𑗂�
	pEnemyModel->BindBuff(CManager::GetModelManager()->GetMaterialBuffer(CModelManager::TYPE_ENEMY));

	//���b�V�����𑗂�
	pEnemyModel->BindMesh(CManager::GetModelManager()->GetMesh(CModelManager::TYPE_ENEMY));

	//�}�e���A���̗v�f���𑗂�
	pEnemyModel->BindMaterials(CManager::GetModelManager()->GetNumMaterials(CModelManager::TYPE_ENEMY));
	
	//�e�N�X�`���̐ݒ�
	pEnemyModel->BindTexture(NULL);

	return pEnemyModel;
}

void CEnemyModel::HitObject(void)
{
	Uninitialize();
}
