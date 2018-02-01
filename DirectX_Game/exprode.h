/******************************************************************
***
***		爆破処理
***
***		exprode.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _EXPRODE_H_
#define _EXPRODE_H_
/******************************************************************
インクルードファイル
*******************************************************************/
#include "particleBillboard.h"
/******************************************************************
クラス宣言
*******************************************************************/
class CExprode : public CParticleBillboard
{
public:
	~CExprode(){}
	void Initialize(void);
	void Uninitialize(void);
	void Update(void);
	void Draw(void);
	static CExprode *Create(D3DXVECTOR3 OrderPosition);
private:
	CExprode();
};
#endif
