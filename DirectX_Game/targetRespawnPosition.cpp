#include "manager.h"
#include "targetRespawnPosition.h"
#include "DebugFont.h"
//�R���X�g���N�^
CTargetRespawnPosition::CTargetRespawnPosition()
{

}

D3DXVECTOR3 CTargetRespawnPosition::RespawnPosition(void)
{
	//���W
	D3DXVECTOR3 Position;

	//��������ϐ�
	int RandomNumber;
	RandomNumber = (rand() % 5);

	//
	if (RandomNumber == 0)
	{
		Position = D3DXVECTOR3(-630.0f, 0.0f, 0.0f);
	}

	//
	else if (RandomNumber == 1)
	{
		Position = D3DXVECTOR3(630.0f, 0.0f, 0.0f);
	}

	//
	else if (RandomNumber == 2)
	{
		Position = D3DXVECTOR3(0.0f, 0.0f, 630.0f);
	}

	//
	else if (RandomNumber == 3)
	{
		Position = D3DXVECTOR3(0.0f, 0.0f, -630.0f);
	}

	else
	{
		Position = D3DXVECTOR3(-630.0f, 0.0f, 0.0f);
	}
	return Position;
}