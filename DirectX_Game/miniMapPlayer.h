/******************************************************************
***
***		�~�j�}�b�v����
***
***		miniMapPlayer.cpp
***
***		author: Kengo Sakai
***u************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "scene2D.h"
/******************************************************************
�}�N����`
*******************************************************************/

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
class CMiniMapPlayer : public CScene2D
{
public:
	CMiniMapPlayer();
	~CMiniMapPlayer(){}
	void Initialize(void);
	void Uninitalize(void);
	void Update(void);
	void Draw(void);
	static CMiniMapPlayer *Create(void);
private:

};