/******************************************************************
***
***		�����z�u����
***
***		building.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "building.h"
/******************************************************************
�}�N����`
*******************************************************************/
#define NUM_BUILD (4)
/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CBuilding::CBuilding()
{
	CManager::GetModelManager()->LoadModel(CModelManager::TYPE_BUILDING);
	CManager::GetTextureManager()->LoadTexture(CTextureManager::TYPE_TREE);
}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CBuilding::~CBuilding()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CBuilding::Initialize(int nCnt)
{
	//���f���̏�����
	CModel::Initialize();

	//���W�ݒ�i�O���t�@�C���ł�������������j
	SetPosition(nCnt);
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CBuilding::Uninitialize(void)
{
	CModel::Uninitialize();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CBuilding::Update(void)
{
	//Rotate.y++;
}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CBuilding::Draw(void)
{
	CModel::SetMatrix();
	//�`�揈��
	CModel::Draw();
}

/******************************************************************
�I�u�W�F�N�g�쐬�֐�
*******************************************************************/
CBuilding *CBuilding::Create(void)
{
	//�I�u�W�F�N�g�|�C���^
	CBuilding *pBuilding;

	//�\������I�u�W�F�N�g���J��Ԃ�
	for (int nCnt = 0; nCnt < NUM_BUILD; nCnt++)
	{
		//�C���X�^���X�̐���
		pBuilding = new CBuilding;

		//����������
		pBuilding->Initialize(nCnt);

		//�I�u�W�F�N�g�̌^�o�^�֐��Ăяo��
		pBuilding->SetObjType(OBJTYPE_BUILDING);

		//�o�b�t�@���𑗂�
		pBuilding->BindBuff(CManager::GetModelManager()->GetMaterialBuffer(CModelManager::TYPE_BUILDING));

		//�v�f���𑗂�
		pBuilding->BindMaterials(CManager::GetModelManager()->GetNumMaterials(CModelManager::TYPE_BUILDING));

		//���b�V�����𑗂�
		pBuilding->BindMesh(CManager::GetModelManager()->GetMesh(CModelManager::TYPE_BUILDING));

		pBuilding->BindTexture(CManager::GetTextureManager()->GetTexture(CTextureManager::TYPE_TREE));
	}
	return pBuilding;
}

/******************************************************************
�ʒu���擾�֐�
*******************************************************************/
D3DXVECTOR3 CBuilding::GetPosition(void)
{
	return Position;
}

/******************************************************************
�����̔z�u�ʒu�ݒ菈���֐�
*******************************************************************/
void CBuilding::SetPosition(int nCnt)
{
	if (nCnt < NUM_BUILD)
	{
		Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);				//�g�嗦

		if (nCnt == 0)
		{
			//�����̃X�e�[�^�X
			Position = D3DXVECTOR3(-450.0f, 0.0f, 450.0f);	//���W
			Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//��]
			return;
		}

		else if (nCnt == 1)
		{
			//�����̃X�e�[�^�X
			Position = D3DXVECTOR3(-450.0f, 0.0f, -450.0f);	//���W
			Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//��]
			return;
		}

		else if (nCnt == 2)
		{
			//�����̃X�e�[�^�X
			Position = D3DXVECTOR3(450.0f, 0.0f, 450.0f);	//���W
			Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//��]
			return;
		}

		else if (nCnt == 3)
		{
			//�����̃X�e�[�^�X
			Position = D3DXVECTOR3(450.0f, 0.0f, -450.0f);	//���W
			Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//��]
			return;
		}
	}

	else
	{
		MessageBox(NULL, "�K�萔�ȏ�̃I�u�W�F�N�g��z�u���悤�Ƃ��܂���", "�G���[���b�Z�[�W", MB_OK);
	}
}
