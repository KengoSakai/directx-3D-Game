#ifndef _BULLET_H_
#define _BULLET_H_
#include "scene3D.h"

class CRenderer;
class CBullet : public CScene3D
{
public:
	~CBullet(){}
	void Initialize(D3DXVECTOR3 OrderPosition, D3DXVECTOR3 OrderVector);
	void Uninitialize(void);
	void Update(void);
	void Draw(void);
	static CBullet *Create(D3DXVECTOR3 OrderPosition, D3DXVECTOR3 OrderVector);
private:
	CBullet();
	void HitObject(void);
	//Ã“Iƒƒ“ƒo[•Ï”
	static CRenderer *m_pRenderer;
};
#endif
