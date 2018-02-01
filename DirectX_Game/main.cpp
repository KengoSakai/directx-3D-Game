/******************************************************************
***
***		���C������
***
***		main.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "main.h"
#include "manager.h"
#include "DebugFont.h"
/******************************************************************
�}�N����`
*******************************************************************/
#define CLASS_NAME		"AppClass"			// �E�C���h�E�̃N���X��
#define WINDOW_NAME		"3d"	// �E�C���h�E�̃L���v�V������

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/
CManager *pManager = NULL;
/******************************************************************
���C���֐�
*******************************************************************/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		NULL
	};

	RECT rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
	HWND hWnd;
	MSG msg;
	DWORD dwCurrentTime;
	DWORD dwFrameCount;
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;

	//�E�B���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);

	//�w�肵���N���C�A���g�̈���m�ۂ��邽�߂ɕK�v�ȃE�B���h�E���W���v�Z
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	//�E�B���h�E�̍쐬
	hWnd = CreateWindow(CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(rect.right - rect.left),
		(rect.bottom - rect.top),
		NULL,
		NULL,
		hInstance,
		NULL);

	//���������m��
	pManager = new CManager;

	//����������
	pManager ->Init(hInstance,hWnd,TRUE);

	//����\��ݒ�
	timeBeginPeriod(1);

	//�t���[���J�E���g������
	dwCurrentTime =
		dwFrameCount = 0;
	dwExecLastTime = 
		dwFPSLastTime = timeGetTime();

	//�E�C���h�E�̕\��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//���b�Z�[�W���[�v
	while(1)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				//���b�Z�[�W�̖|��ƃf�B�X�p�b�`
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			dwCurrentTime = timeGetTime();
			if((dwCurrentTime - dwFPSLastTime) >= 500)	//0.5�b���ƂɎ��s
			{
				dwFPSLastTime = dwCurrentTime;
				dwFrameCount = 0;
			}

			if((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
			{
				dwExecLastTime = dwCurrentTime;

				//�X�V����
				pManager -> Update();

				//�`�揈��
				pManager -> Draw();

				dwFrameCount++;
			}
		}
	}

	//�����_���[�̔j��
	if(pManager != NULL)
	{
		//�I������
		pManager -> Uninit();
		delete pManager;
		pManager = NULL;
	}
	//�E�B���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	//����\��߂�
	timeEndPeriod(1);

	return (int)msg.wParam;
}

/******************************************************************
�E�B���h�E�v���V�[�W��
*******************************************************************/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		//�E�B���h�E�����ꂽ�Ƃ�
	case WM_CREATE:
		break;

		//�E�B���h�E���j�����ꂽ�Ƃ�
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

		//�L�[���͂��������Ƃ�
	case WM_KEYDOWN:

		switch(wParam)
		{
			//ESC�L�[�������ꂽ��
		case VK_ESCAPE:			
			DestroyWindow(hWnd);	//�E�B���h�E��j��
			break;

		case VK_F5:

			break;
		}
		break;

		//��L�ɊY�����Ȃ��ꍇ
	default:
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
