#include "manager.h"
#include "goalModel.h"

//�R���X�g���N�^
CGoalModel::CGoalModel()
{
	CManager::GetModelManager()->LoadModel(CModelManager::TYPE_GOAL);
}

//����������
void CGoalModel::Initialize(void)
{
	Position = D3DXVECTOR3(0.0, 10.0, 0.0);
	Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}
//�I������
void CGoalModel::Uninitialize(void)
{
	//���f���̔j��
	CModel::Uninitialize();
}

//�X�V����
void CGoalModel::Update(void)
{

}

//�`�揈��
void CGoalModel::Draw(void)
{
	CModel::SetMatrix();

	//���f���`��
	CModel::Draw();
}

/******************************************************************
�I�u�W�F�N�g���������֐�
*******************************************************************/
CGoalModel *CGoalModel::Create(void)
{
	CGoalModel *pGoalmodel;

	//�C���X�^���X����
	pGoalmodel = new CGoalModel;

	//����������
	pGoalmodel->Initialize();

	//�R���e�i�N���X�ɃI�u�W�F�N�g�̌^��ݒ�
	pGoalmodel->SetObjType(OBJTYPE_GOAL);

	//�}�e���A���o�b�t�@�𑗂�
	pGoalmodel->BindBuff(CManager::GetModelManager()->GetMaterialBuffer(CModelManager::TYPE_GOAL));

	//���b�V�����𑗂�
	pGoalmodel->BindMesh(CManager::GetModelManager()->GetMesh(CModelManager::TYPE_GOAL));

	//�}�e���A���̗v�f���𑗂�
	pGoalmodel->BindMaterials(CManager::GetModelManager()->GetNumMaterials(CModelManager::TYPE_GOAL));

	pGoalmodel->BindTexture(NULL);
	return pGoalmodel;
}
