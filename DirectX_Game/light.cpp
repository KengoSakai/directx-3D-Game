/******************************************************************
***
***		���C�g����
***
***		light.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "light.h"
#include "camera.h"
/******************************************************************
�R���X�g���N�^
*******************************************************************/
CLight::CLight()
{

}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CLight::~CLight()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CLight::Init(void)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	m_Light.Type = D3DLIGHT_DIRECTIONAL;
	m_Light.Diffuse = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	m_Light.Ambient = D3DXCOLOR(0.2f,0.2f,0.2f,1.0f);
	m_Light.Position = D3DXVECTOR3(0.0f,1000.0f,0.0f);
	D3DXVECTOR3 Direct(1.0f,0.0f,1.0f);
	D3DXVec3Normalize((D3DXVECTOR3*)&m_Light.Direction,&Direct);
	
	pDevice->SetLight(0,&m_Light);

	pDevice->LightEnable(0,TRUE);

	pDevice->SetRenderState(D3DRS_LIGHTING,TRUE);
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CLight::Uninit(void)
{

}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CLight::Update(void)
{
#ifdef _DEBUG
	Debug();	//�f�o�b�O����
#endif

	//D3DXVECTOR3 Direct(0.0f,-0.5f,1.0f);
	//D3DXVec3Normalize((D3DXVECTOR3*)&m_Light.Direction,&Direct);
}

/******************************************************************
�f�o�b�O�����֐�
*******************************************************************/
void CLight::Debug(void)
{
	//U�����͂��ꂽ��
	if(CManager :: GetInputKeyboard() ->GetKeyPress(DIK_Y))
	{
		m_Light.Diffuse.r += 0.05f;
	}

	//U�����͂��ꂽ��
	if(CManager :: GetInputKeyboard() ->GetKeyPress(DIK_U))
	{
		m_Light.Diffuse.g += 0.05f;
	}

	//I�����͂��ꂽ��
	if(CManager :: GetInputKeyboard() ->GetKeyPress(DIK_I))
	{
		m_Light.Diffuse.b += 0.05f;
	}

	//O�����͂��ꂽ��
	if(CManager :: GetInputKeyboard() ->GetKeyPress(DIK_O))
	{
		m_Light.Diffuse.a += 0.05f;
	}

	//P�����͂��ꂽ��
	if(CManager :: GetInputKeyboard() ->GetKeyPress(DIK_P))
	{
		m_Light.Diffuse.r = 1.0f;
		m_Light.Diffuse.g = 1.0f;
		m_Light.Diffuse.b = 1.0f;
		m_Light.Diffuse.a = 1.0f;
	}
	
	//H�����͂��ꂽ��
	if(CManager :: GetInputKeyboard() ->GetKeyPress(DIK_G))
	{
		m_Light.Ambient.r +=0.05f;
	}

	if(CManager :: GetInputKeyboard() ->GetKeyPress(DIK_H))
	{
		m_Light.Ambient.g +=0.05f;
	}

	if(CManager :: GetInputKeyboard() ->GetKeyPress(DIK_J))
	{
		m_Light.Ambient.b +=0.05f;
	}

	if(CManager :: GetInputKeyboard() ->GetKeyPress(DIK_K))
	{
		m_Light.Ambient.a +=0.05f;
	}

	if(CManager :: GetInputKeyboard() ->GetKeyPress(DIK_L))
	{
		m_Light.Ambient.r =0.2f;
		m_Light.Ambient.g =0.2f;
		m_Light.Ambient.b =0.2f;
		m_Light.Ambient.a =1.0f;
	}
}


/******************************************************************
�e�p���C�g�ݒ菈���֐�
*******************************************************************/
void CLight::SetShadowLight(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_Light.Type = D3DLIGHT_DIRECTIONAL;
	m_Light.Position = D3DXVECTOR3(10.0f, 100.0f, 10.0f);
	D3DXVECTOR3 Direct(1.0f, 0.0f, 1.0f);

	m_Light.Diffuse = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	m_Light.Ambient = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);

	pDevice->SetLight(0, &m_Light);
}


/******************************************************************
���f���p���C�g�ݒ菈���֐�
*******************************************************************/
void CLight::SetModelLight(void)
{	
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_Light.Type = D3DLIGHT_DIRECTIONAL;
	m_Light.Position = D3DXVECTOR3(10.0f, 100.0f, 10.0f);
	D3DXVECTOR3 Direct(1.0f, 0.0f, 1.0f);

	m_Light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light.Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);
	pDevice->SetLight(0, &m_Light);
}

/******************************************************************
���f���p���C�g�ݒ菈���֐�
*******************************************************************/
void CLight::SetCameraLight(void)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	m_Light.Type = D3DLIGHT_POINT;
	m_Light.Diffuse = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);
	m_Light.Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);
	m_Light.Specular= D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);
	m_Light.Position = CManager::GetCamera()->GetPosView();
	m_Light.Range = 100.0f;
	D3DXVECTOR3 Direct(1.0f, 1.0f, 1.0f);
	D3DXVec3Normalize((D3DXVECTOR3*)&m_Light.Direction, &Direct);

	pDevice->SetLight(1, &m_Light);
	pDevice->LightEnable(1, TRUE);

}
