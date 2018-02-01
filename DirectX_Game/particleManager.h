/******************************************************************
***
***		�p�[�e�B�N���̃I�u�W�F�N�g�Ǘ�����
***
***		particleManager.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _PARTICLEMANAGER_H_
#define _PARTICLEMANAGER_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "main.h" 
/******************************************************************
�}�N����`
*******************************************************************/
#define NUM_PARTICLE (1000)		//�p�[�e�B�N���̐�	
/******************************************************************
�N���X��`
*******************************************************************/
class CParticleManager
{
public:
	CParticleManager();				//�R���X�g���N�^
	~CParticleManager();			//�f�X�g���N�^

	//�������z�֐�
	virtual void Initialize(void) = 0;	//����������
	virtual void Uninitialize(void) = 0;	//�I������
	virtual void Update(void) = 0;	//�X�V����
	virtual void Draw(void) = 0;		//�`�揈��

	static void UpdateAll(void);		//�I�u�W�F�N�g�S�X�V����
	static void DrawAll (void);			//�I�u�W�F�N�g�S�`�揈��
	static void ReleaseAll(void);		//�I�u�W�F�N�g�S�j������

private:
	static CParticleManager *m_apParticle[NUM_PARTICLE];	//�I�u�W�F�N�g�̍ő吔
	static int m_nNumParticle;			//�I�u�W�F�N�g�̑���
	
	//�ϐ��錾
	int m_nID;				//�I�u�W�F�N�g�ŗLID

protected:
	 void Release(void);				//�I�u�W�F�N�g�j������
};
#endif
