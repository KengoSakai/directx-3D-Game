#include "collision.h"

CCollision::CCollision()
{

}

CCollision::~CCollision()
{

}

bool CCollision::SphereCollision(D3DXVECTOR3 MyPosition, D3DXVECTOR3 OtherPosition)
{
	//�w�肵���I�u�W�F�N�g�Ƃ̋��������߂�
	D3DXVECTOR3 DistanceAtoB = MyPosition - OtherPosition;
	float Distance = D3DXVec3LengthSq(&DistanceAtoB);

	return Distance <= 600.0f;
}

bool CCollision::CubeCollision(D3DXVECTOR3 MyPos, D3DXVECTOR3 OtherPos)
{
	return false;
}

float CCollision::Distance(D3DXVECTOR3 MyPos, D3DXVECTOR3 OtherPos)
{
	//�w�肵���I�u�W�F�N�g�Ƃ̋��������߂�
	D3DXVECTOR3 DistanceAtoB = MyPos - OtherPos;
	float Distance = D3DXVec3LengthSq(&DistanceAtoB);

	return Distance;
}
