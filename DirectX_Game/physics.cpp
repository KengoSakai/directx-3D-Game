#include "physics.h"

//�R���X�g���N�^
CPhysics::CPhysics()
{

}

//�����������֐�
void CPhysics::Initialize(void)
{
	
}

//
D3DXVECTOR3 CPhysics::AddForce(D3DXVECTOR3 Position,D3DXVECTOR3 AddForce)
{
	Position += AddForce;
	return Position;
}
