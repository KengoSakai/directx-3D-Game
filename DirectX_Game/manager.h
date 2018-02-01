/******************************************************************
***
***		�Q�[������
***
***		manager.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _MANAGER_H_
#define _MANAGER_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "main.h"
#include "input.h"
#include "xBoxInput.h"
/******************************************************************
�}�N����`
*******************************************************************/

/******************************************************************
�O���錾
*******************************************************************/
class CRenderer;
class CInputKeyboard;
class CCamera;
class CDebugFont;
class CLight;
class CSceneManager;
class CModelManager;
class CTextureManager;
class CFade;
class CShader;
/******************************************************************
�\���̒�`�i�N���X�j
*******************************************************************/
class CManager
{
public:
	CManager ();			//�R���X�g���N�^
	~CManager ();			//�f�X�g���N�^
	HRESULT Init (HINSTANCE hInstance,
		HWND hWnd,
		BOOL bWindow);		//����������
	void Uninit (void);		//�I������
	void Update (void);		//�X�V����
	void Draw (void);		//�`�揈��

	//�C�����C���֐�
	static CRenderer *GetRenderer(void){return m_pRenderer;}
	static CInputKeyboard *GetInputKeyboard(void){return m_pInputKeyboard;}
	static CCamera *GetCamera(void){return m_pCamera;}
	static CDebugFont *GetDebugFont(void) { return pDebugFont; }
	static CModelManager *GetModelManager(void) { return pModelManager; }
	static CTextureManager *GetTextureManager(void) { return pTextureManager; }
	static CLight *GetLight(void) { return m_pLight; }
	static CSceneManager *GetSceneManager(void) { return pSceneManager; }
	static CFade *GetFade(void) { return pFade; }
	static CXBoxInput *GetXBoxInput(void) { return pXBoxInput; }
	static CShader *GetShader(void) { return pShader; }
private:

protected:
	static CRenderer *m_pRenderer;
	static CInputKeyboard *m_pInputKeyboard;
	static CCamera *m_pCamera;
	static CLight *m_pLight;
	static CSceneManager *pSceneManager;
	static CDebugFont *pDebugFont;
	static CModelManager *pModelManager;
	static CTextureManager *pTextureManager;
	static CFade *pFade;
	static CXBoxInput *pXBoxInput;
	static CShader *pShader;
};

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************/
#endif