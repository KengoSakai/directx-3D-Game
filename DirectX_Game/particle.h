/******************************************************************
***
***		�p�[�e�B�N������
***
***		particle.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _PARTICLE_H_
#define _PARTICLE_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "particleBillboard.h"
/******************************************************************
�}�N����`
*******************************************************************/
class CRenderer;
/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
class CParticle : public CParticleBillboard
{
public:
	CParticle();	//�R���X�g���N�^
	~CParticle();	//�f�X�g���N�^
	void Initialize(D3DXVECTOR3 Pos);	//����������
	void Uninitialize(void);			//�I������
	void Update(void);					//�X�V����
	void Draw(void);					//�`�揈��
	//�ÓI�����o�[�֐�
	static CParticle *Create(D3DXVECTOR3 EmitterPosition);	//�I�u�W�F�N�g��������

private:
	//�ÓI�����o�[�ϐ�
	static CRenderer *m_pRenderer;
};
#endif
