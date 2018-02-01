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
#ifndef _STARTBUTTON_H_
#define _STARTBUTTON_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "scene2D.h"
/******************************************************************
�}�N����`
*******************************************************************/

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
class CStartButton : public CScene2D
{
public:
	typedef enum
	{
		FADE_NONE = 0,
		FADE_IN,
		FADE_OUT,
		FADE_MAX
	}FADE;

	~CStartButton();
	void Initialize(void);
	void Uninitialize(void);
	void Update(void);
	void Draw(void);
	static CStartButton *Create(void);
private:
	CStartButton();
	FADE FadeState;
protected:
};

#endif
