/******************************************************************
***
***		���f���Ǘ�����
***
***		modelManager.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "modelManager.h"

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CModelManager::CModelManager()
{
	for (int count = 0; count < TYPE_MAX; count++)
	{
		pModelList[count] = NULL;
		pMesh[count] = NULL;
		pMatBuff[count] = NULL;
		NumMaterials[count] = NULL;
	}
}
/******************************************************************
�����������֐�
*******************************************************************/
void CModelManager::Initialize(void)
{
	//���f�����X�g��������
	pModelList[TYPE_PLAYER] = "data/Model/a.x";
	pModelList[TYPE_ENEMY] = "data/Model/incect_face_RED.x";
	pModelList[TYPE_GOAL] = "data/Model/goal.x";
	pModelList[TYPE_TREE] = "data/Model/tree_02.x";
	pModelList[TYPE_ITEM] = "data/Model/a.x";
	pModelList[TYPE_BUILDING] = "data/Model/building002.x";
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CModelManager::Unitialize(void)
{
	for (int count = 0; count < TYPE_MAX; count++)
	{
		//���f�����X�g��j��
		if (pModelList[count] != NULL)
		{
			pModelList[count] = NULL;
		}

		//���b�V���̔j��
		if (pMesh[count] != NULL)
		{
			pMesh[count]->Release();
			pMesh[count] = NULL;
		}
		
		//�}�e���A���o�b�t�@�̔j��
		if (pMatBuff[count] != NULL)
		{
			pMatBuff[count]->Release();
			pMatBuff[count] = NULL;
		}
	}
}

/******************************************************************
���f���擾�֐�
*******************************************************************/
void CModelManager::LoadModel(MODEL_TYPE OrderModelType)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	
	if (pMatBuff[OrderModelType] == NULL && NumMaterials[OrderModelType] == NULL&&pMesh[OrderModelType]==NULL)
	{
		//���f���ǂݍ���
		if (FAILED(D3DXLoadMeshFromX(pModelList[OrderModelType], D3DXMESH_MANAGED, pDevice, NULL, &pMatBuff[OrderModelType], NULL, &NumMaterials[OrderModelType], &pMesh[OrderModelType])))
		{
			MessageBox(NULL, "���f�����ǂݍ��߂܂���ł���", "�G���[���b�Z�[�W", MB_OK);
			PostQuitMessage(0);
		}
	}
}

LPD3DXMESH CModelManager::GetMesh(MODEL_TYPE OrderModelType) 
{ return pMesh[OrderModelType]; }

DWORD CModelManager::GetNumMaterials(MODEL_TYPE OrderModelType) 
{ return NumMaterials[OrderModelType]; }

LPD3DXBUFFER CModelManager::GetMaterialBuffer(MODEL_TYPE OrderModelType) 
{ return pMatBuff[OrderModelType]; }
