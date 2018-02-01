/******************************************************************
***
***		�Q�[������
***
***		manager.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "DebugFont.h"
#include "camera.h"
#include "fade.h"
#include "light.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include "modelManager.h"
#include "textureManager.h"

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/
CRenderer *CManager::m_pRenderer = NULL;
CInputKeyboard *CManager::m_pInputKeyboard = NULL;
CCamera *CManager::m_pCamera = NULL;
CLight *CManager::m_pLight = NULL;
CSceneManager *CManager::pSceneManager = NULL;
CModelManager *CManager::pModelManager = NULL;
CTextureManager *CManager::pTextureManager = NULL;
#ifdef _DEBUG
	CDebugFont *CManager::pDebugFont = NULL;
#endif
	CFade *CManager::pFade = NULL;
/******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CManager :: CManager ()
{

}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CManager :: ~CManager ()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
HRESULT CManager :: Init (HINSTANCE hInstance,HWND hWnd,BOOL bWindow)
{
	//�����_���[�̐���
	m_pRenderer = new CRenderer;
	m_pRenderer -> Init(hWnd , bWindow);

	//�L�[�{�[�h�̐���
	m_pInputKeyboard = new CInputKeyboard;
	m_pInputKeyboard -> Init(hInstance , hWnd);

	//�J�����̐���
	m_pCamera = new CCamera;
	m_pCamera -> Init();

	//���C�g�̐���
	m_pLight = new CLight;
	m_pLight->Init();

#ifdef _DEBUG

	//�f�o�b�O�t�H���g�̐���
	pDebugFont = new CDebugFont;
	pDebugFont->Initialize();
#endif

	//���f���Ǘ��N���X�̐���
	pModelManager = new CModelManager;
	pModelManager->Initialize();

	//�e�N�X�`���Ǘ��N���X�̐���
	pTextureManager = new CTextureManager;
	pTextureManager->Initialize();

	//�V�[���̐���
	pSceneManager = new CSceneManager;
	pSceneManager->Initialize();

	//�t�F�[�h�̐���
	pFade = pFade->Create();

	return S_OK;
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CManager :: Uninit (void)
{
	//���C�g�̔j��
	if (m_pLight != NULL)
	{
		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = NULL;
	}

	//���f���Ǘ��N���X�̔j��
	if(pModelManager!=NULL)
	{
		pModelManager->Unitialize();
		delete pModelManager;
		pModelManager = NULL;
	}

	//�e�N�X�`���Ǘ��N���X�̔j��
	if (pTextureManager!=NULL)
	{
		pTextureManager->Uninitialize();
		delete  pTextureManager;
		pTextureManager = NULL;
	}

	//�L�[�{�[�h�̔j��
	if(m_pInputKeyboard != NULL)
	{
		m_pInputKeyboard->Uninit();
		delete m_pInputKeyboard;
		m_pInputKeyboard = NULL;
	}

	//�J�����̔j��
	if(m_pCamera != NULL)
	{
		m_pCamera->Uninit();
		delete m_pCamera;
		m_pCamera = NULL;
	}

#ifdef _DEBUG

	//�f�o�b�O�t�H���g�̔j��
	if (pDebugFont != NULL)
	{
		pDebugFont->Uninitialize();
		delete pDebugFont;
		pDebugFont = NULL;
	}
#endif

	//�V�[���̔j��
	if(pSceneManager != NULL)
	{
		pSceneManager->Uninitalize();
		delete pSceneManager;
		pSceneManager = NULL;
	}

	//�����_���[�̔j��
	if (m_pRenderer != NULL)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = NULL;
	}
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CManager :: Update (void)
{
#ifdef _DEBUG

#endif
	//�I�u�W�F�N�g�̍X�V
	m_pRenderer-> Update();

	//�L�[�{�[�h�̍X�V
	m_pInputKeyboard -> Update();
	
	//�J�����̍X�V
	m_pCamera->Update();
	
	//���C�g�̍X�V
	m_pLight->Update();
	
	//�V�[���̍X�V
	pSceneManager->Update();
}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CManager :: Draw (void)
{
	//�I�u�W�F�N�g�`��
	m_pRenderer -> Draw();	
#ifdef _DEBUG
	
#endif
}


