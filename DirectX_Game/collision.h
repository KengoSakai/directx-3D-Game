#ifndef _COLLISION_H_
#define _COLLISION_H_
#include "main.h"
class CCollision
{
public:
	CCollision();
	~CCollision();
	static bool SphereCollision(D3DXVECTOR3 MyPos, D3DXVECTOR3 OtherPos);		//�~�̓����蔻��
	static bool CubeCollision(D3DXVECTOR3 MyPos, D3DXVECTOR3 OtherPos);		//�����̂̓����蔻��
	static float Distance(D3DXVECTOR3 MyPos, D3DXVECTOR3 OtherPos);			//�I�u�W�F�N�g����̋��������߂�

};
#endif
