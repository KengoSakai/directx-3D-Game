#ifndef _ENEMYMODEL_H_
#define _ENEMYMODEL_H_

#include "model.h"

class CEnemyModel : public CModel
{
public:
	~CEnemyModel() {}	//�f�X�g���N�^
	void Initialize(void);
	void Uninitialize(void);
	void Update(void);
	void Draw(void);
	static CEnemyModel *Create(void);
	D3DXVECTOR3 GetPosition(void) { return Position; }
	void HitObject(void);
private:
	CEnemyModel();	//�R���X�g���N�^
	int Count;
protected:
};
#endif
