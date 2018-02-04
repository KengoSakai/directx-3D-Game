/******************************************************************
***
***		�I�u�W�F�N�g�Ǘ�����
***
***		scene.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _SCENE_H_
#define _SCENE_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "main.h"

/******************************************************************
�}�N����`
*******************************************************************/
#define NUM_OBJECT (1000)

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
class CScene
{
public:
	typedef enum
	{
		OBJTYPE_NONE = 0 ,
		OBJTYPE_PARTICLE ,
		OBJTYPE_PLAYER,
		OBJTYPE_MINIMAPPLAYER,
		OBJTYPE_ENEMY,
		OBJTYPE_BG,
		OBJTYPE_FIELD,
		OBJTYPE_WALL,
		OBJTYPE_DOME,
		OBJTYPE_GAUGE,
		OBJTYPE_START,
		OBJTYPE_GOAL,
		OBJTYPE_FADE,
		OBJTYPE_TITLELOGO,
		OBJTYPE_TITLEBUTTON,
		OBJTYPE_MINIMAP,
		OBJTYPE_BUILDING,
		OBJTYPE_TIME,
		OBJTYPE_SCORE,
		OBJTYPE_ITEM,
		OBJTYPE_BULLET,
		OBJTYPE_CUBECOLLIDER,
		OBJTYPE_CLOUD,
		OBJTYPE_TARGET,
		OBJTYPE_OTHERPLAYERSCORE,
		OBJTYPE_MAX
	}OBJTYPE;

	CScene ();							//�R���X�g���N�^
	virtual ~CScene ();					//�f�X�g���N�^
	virtual void Initialize (void) = 0;	//����������
	virtual void Uninitialize (void) = 0;		//�I������
	virtual void Update (void) = 0;		//�X�V����
	virtual void Draw (void) = 0 ;		//�`�揈��

	static void UpdateAll(void);		//�I�u�W�F�N�g�S�X�V����
	static void DrawAll (void);			//�I�u�W�F�N�g�S�`�揈��
	static void ReleaseAll(void);		//�I�u�W�F�N�g�S�j������

	void SetObjType(OBJTYPE type);											//�I�u�W�F�N�g�̎�ފi�[�֐�
	OBJTYPE GetObjType (void){return  m_objType;}							//�I�u�W�F�N�g�̎�ގ擾�֐�
	static CScene *GetScene(int nIdxScene){return  m_apScene[nIdxScene];}	//�I�u�W�F�N�g�̏��擾�֐�
	
private:
	static CScene *m_apScene[NUM_OBJECT];	//�I�u�W�F�N�g�̍ő吔
	static int m_nNumScene;			//�I�u�W�F�N�g�̑���
	
	//�ϐ��錾
	int m_nID;				//�I�u�W�F�N�g�ŗLID
	OBJTYPE m_objType;		//�I�u�W�F�N�g�̎�ފi�[�ϐ�

	protected:
	 void Release(void);				//�I�u�W�F�N�g�j������
};

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************/
#endif