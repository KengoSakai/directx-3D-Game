#include "manager.h"
#include "target.h"
#include "targetRespawnPosition.h"

//�R���X�g���N�^
CTarget::CTarget()
{
	CManager::GetModelManager()->LoadModel(CModelManager::TYPE_PLAYER);
}

//�����������֐�
void CTarget::Initialize(void)
{
	CModel::Initialize();
	Position = CTargetRespawnPosition::RespawnPosition();
	Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	Vector = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}

//�I�������֐�
void CTarget::Uninitialize(void)
{
	CModel::Uninitialize();
}

//�X�V�����֐�
void CTarget::Update(void)
{

}

//�`�揈���֐�
void CTarget::Draw(void)
{
	CModel::SetMatrix();

	CModel::Draw();
}

//�I�u�W�F�N�g���������֐�
CTarget *CTarget::Create(void)
{
	CTarget *pTarget;

	pTarget = new CTarget;

	pTarget->Initialize();
	
	pTarget->BindMesh(CManager::GetModelManager()->GetMesh(CModelManager::TYPE_PLAYER));

	pTarget->BindBuff(CManager::GetModelManager()->GetMaterialBuffer(CModelManager::TYPE_PLAYER));

	pTarget->BindMaterials(CManager::GetModelManager()->GetNumMaterials(CModelManager::TYPE_PLAYER));

	pTarget->BindTexture(NULL);
	
	pTarget->SetObjType(OBJTYPE_TARGET);

	return pTarget;
}
