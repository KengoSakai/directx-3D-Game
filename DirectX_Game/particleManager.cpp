/******************************************************************
***
***		�p�[�e�B�N���I�u�W�F�N�g�Ǘ�����
***
***		ParticleMnager.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "particleManager.h"
#include "renderer.h"
/******************************************************************
�}�N����`
*******************************************************************/


/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/


/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/
CParticleManager *CParticleManager::m_apParticle[NUM_PARTICLE];
int CParticleManager :: m_nNumParticle;
/******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CParticleManager :: CParticleManager()
{
	for(int nCntScene = 0 ; nCntScene < NUM_PARTICLE ; nCntScene++)
	{
		if(m_apParticle[nCntScene] == NULL)
		{
			m_apParticle[nCntScene] = this;
			m_nID = nCntScene;
			m_nNumParticle++;
			break;
		}
	}
}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CParticleManager :: ~CParticleManager()
{

}

/******************************************************************
�I�u�W�F�N�g�S�X�V�����֐�
*******************************************************************/
void CParticleManager :: UpdateAll(void)
{
	for(int nCntScene = 0 ; nCntScene < NUM_PARTICLE ; nCntScene++)
	{
		if(m_apParticle[nCntScene] != NULL)
		{
			m_apParticle[nCntScene] -> Update();
		}
	}
}

/******************************************************************
�I�u�W�F�N�g�I�������֐�
*******************************************************************/
void CParticleManager :: Release (void)
{
	//�ϐ��錾
	int nID;
	nID = m_nID;	//�I�u�W�F�N�g�̑�������

	if(m_apParticle[m_nID] != NULL)
	{
		delete m_apParticle[nID] ;
		m_apParticle[nID] = NULL ;
		m_nNumParticle--;
	}
}

/******************************************************************
�I�u�W�F�N�g�S�I�������֐�
*******************************************************************/
void CParticleManager :: ReleaseAll (void)
{
	for(int nCntScene = 0 ; nCntScene < NUM_PARTICLE ; nCntScene++)
	{
		if(m_apParticle[nCntScene] != NULL)
		{
			m_apParticle[nCntScene] -> Uninitialize();
		}
	}
}

/******************************************************************
//�I�u�W�F�N�g�S�`�揈���֐�
*******************************************************************/
void CParticleManager::DrawAll(void)
{
	for(int nCntScene = 0 ; nCntScene < NUM_PARTICLE ; nCntScene++)
	{
		if(m_apParticle[nCntScene] != NULL)
		{
			m_apParticle[nCntScene] -> Draw();
		}
	}
}
