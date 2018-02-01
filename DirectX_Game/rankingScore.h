#ifndef _RANKINGSCORE_H_
#define _RANKINGSCORE_H_

#include "scene.h"
#include "number.h"

#define NUM_DIGIT (8)	//�\������

class CRankingScore : public CScene
{
public:
	~CRankingScore(){}
	void Initialize(void);
	void Uninitialize(void);
	void Update(void);
	void Draw(void);
	static CRankingScore *Create(void);
private:
	CRankingScore();
	CNumber * m_apNumber[NUM_DIGIT];			//�����ւ̃|�C���^
	D3DXVECTOR3 Position;					//�w�x���W
	int m_nScore;							//�X�R�A�̒l
};
#endif
