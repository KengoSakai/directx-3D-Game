/******************************************************************
***
***		���C�g����
***
***		light.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _LIGHT_H_
#define _LIGHT_H_

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
class CLight
{
public:
	CLight();	//�R���X�g���N�^
	~CLight();	//�f�X�g���N�^
	void Init(void);	//����������
	void Uninit(void);
	void Update(void);
	void SetShadowLight(void);
	void SetModelLight(void);
	void SetCameraLight(void);
	D3DXVECTOR3 GetPosition(void) { return m_Light.Position; }
private:
	void Debug(void);
	D3DLIGHT9 m_Light;
};
#endif
