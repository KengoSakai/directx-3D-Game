//#include "xBoxInput.h"
//
//
//void CXBoxInput::Initialize(void)
//{
//	ZeroMemory(&State, sizeof(XINPUT_STATE));
//}
//
//void CXBoxInput::Uninitialize(void)
//{
//
//}
//
//void CXBoxInput::Update(void)
//{
//	DWORD Result;
//	
//	for (DWORD count=0;count<1;count++)
//	{
//		Result= XInputGetState(Result, State);
//		
//		if (Result == ERROR_SUCCESS)
//		{
//			
//		}
//
//		else 
//		{
//			MessageBox(NULL, "XInput�ڑ����s", "�G���[���b�Z�[�W", MB_OK);					//�N�����ɕ\������^�C�g���ƃ��b�Z�[�W
//		}
//	}
//}
