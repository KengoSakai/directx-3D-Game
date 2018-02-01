#pragma once
/******************************************************************
***
***		����
***
***		.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _TITLELOGO_H_
#define _TITLELOGO_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "scene2D.h"

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
class CTitleLogo : public CScene2D
{
public:
	~CTitleLogo() {}	//�f�X�g���N�^
	void Initialize(void);		//����������
	void Uninitialize(void);		//�I������
	void Update(void);		//�X�V����
	void Draw(void);		//�`�揈��
	static CTitleLogo *Create(void);

private:
	CTitleLogo();			//�R���X�g���N�^
protected:

};

#endif
