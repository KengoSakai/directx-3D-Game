/******************************************************************
***
***		���f���Ǘ�����
***
***		modelManager.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _MODELMANAGER_H_
#define _MODELMANAGER_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/

/******************************************************************
�}�N����`
*******************************************************************/

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
class CModelManager
{
public:
	typedef enum
	{
		TYPE_NONE = 0,
		TYPE_PLAYER,
		TYPE_ENEMY,
		TYPE_GOAL,
		TYPE_TREE,
		TYPE_ITEM,
		TYPE_BUILDING,
		TYPE_MAX
	}MODEL_TYPE;

	CModelManager();			//�R���X�g���N�^
	~CModelManager() {}			//�f�X�g���N�^
	void Initialize(void);
	void Unitialize(void);
	void LoadModel(MODEL_TYPE OrderModelType);	//���f���擾����
	LPD3DXMESH GetMesh(MODEL_TYPE OrderModelType);
	DWORD GetNumMaterials(MODEL_TYPE OrderModelType);
	LPD3DXBUFFER GetMaterialBuffer(MODEL_TYPE OrderModelType);
private:
	char *pModelList[TYPE_MAX];	//���f�����X�g
	LPD3DXMESH pMesh[TYPE_MAX];			//���b�V��
	LPD3DXBUFFER pMatBuff[TYPE_MAX];		//�o�b�t�@�|�C���^
	DWORD NumMaterials[TYPE_MAX];		//�v�f��
};

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
#endif
