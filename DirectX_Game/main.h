/******************************************************************
***
***		���C������
***
***		main.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "windows.h"
#include "d3dx9.h"
#include <stdio.h>

/******************************************************************
���C�u�����t�@�C��
*******************************************************************/
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>
#include <XInput.h>
#include <XAudio2.h>
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "winmm.lib")
#pragma comment (lib,"dinput8.lib")

/******************************************************************
�}�N����`
*******************************************************************/
#define SCREEN_WIDTH (1280)	//�E�B���h�E�̕�
#define SCREEN_HEIGHT (720)	//�E�B���h�E�̍���

#define	FVF_VERTEX_2D	(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1 | D3DFVF_NORMAL)

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
	
//2D�p���_�\����
	typedef struct
	{
		D3DXVECTOR3 pos;	// ���_���W
		float rhw;			// ���W�ϊ��p�W��(1.0f�ŌŒ�)
		D3DCOLOR col;		// ���_�J���[
		D3DXVECTOR2 tex;	// �e�N�X�`�����W
	} VERTEX_2D;



//3D�p���_�\����
	typedef struct
	{
		D3DXVECTOR3 pos;		
		D3DXVECTOR3 normal;
		D3DCOLOR color;
		D3DXVECTOR2 tex;
	}VERTEX_3D;
#endif
