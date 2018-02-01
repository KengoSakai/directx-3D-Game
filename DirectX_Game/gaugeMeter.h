#pragma once
/******************************************************************
***
***		�Q�[�W����
***
***		GaugeMeter.h
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#ifndef _GaugeMETER_H_
#define _GaugeMETER_H_

/******************************************************************
�}�N����`
*******************************************************************/
#include "scene2D.h"

/******************************************************************
�\���̒�`�i�N���X�j
*******************************************************************/
class CGaugeMeter : public CScene2D
{
public:
	CGaugeMeter();
	~CGaugeMeter();
	void Initialize(float m_fLife);
	void Uninitialize(void);
	void Update(void);
	void Draw(void);
	static CGaugeMeter *Create(float m_fLife);
	void SubGauge(float SubLife);
private:
	float Life;		//�̗�
	float LifeGauge;
	float GaugeRate;	//1�_���[�W�ɑ΂��Č����Ă�����
};
#endif
