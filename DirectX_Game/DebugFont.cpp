#include "manager.h"
#include "renderer.h"
#include "DebugFont.h"

CDebugFont::CDebugFont()
{
	pDebugFont = NULL;

}

CDebugFont::~CDebugFont()
{

}

void CDebugFont::Initialize(void)
{
#ifdef _DEBUG
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	D3DXCreateFont(
		pDevice,
		18,					//��
		0,					//����
		0,					//�t�H���g�̑���
		0,					//�~�b�v�}�b�v�̑���
		FALSE,				//�΂߂��ǂ���
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,	//�i��
		DEFAULT_PITCH,
		"Terminal",			//�t�H���g�̖��O
		&pDebugFont			//�|�C���^�[
	);
#endif
}

void CDebugFont::Uninitialize(void)
{
	if (pDebugFont != NULL)
	{
		pDebugFont->Release();
		pDebugFont = NULL;
	}
}

void CDebugFont::AddDebugFont( char *AddDebugFont,float ObjectValue, int PositionX, int PositionY)
{
	char aString[256];
	sprintf(&aString[0], "%s:%f\n", AddDebugFont , ObjectValue);
	RECT rect = {
		PositionX,
		PositionY,
		SCREEN_WIDTH,
		SCREEN_HEIGHT
	};

	pDebugFont->DrawText(
		NULL,
		&aString[0],			//�\�����镶��
		-1,
		&rect,
		DT_LEFT,						//���l��
		D3DCOLOR_RGBA(255, 255, 0, 255)	//�F
	);
}
