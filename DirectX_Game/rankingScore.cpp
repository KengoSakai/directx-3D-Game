#include "rankingScore.h"
#include "file.h"

CRankingScore::CRankingScore()
{
	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		//NULL������
		m_apNumber[nCnt] = NULL;
	}

}

void CRankingScore::Initialize(void)
{
	int nScore;
	m_nScore = CFile::Load("score.bin", 1);

	nScore = m_nScore;
	
	Position = D3DXVECTOR3(400.0f, 300.0f, 0.0f);

	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		//�i���o�[�̐���
		m_apNumber[nCnt] = CNumber::Create(nCnt, Position);

		//�e���ɐ�����ݒ�
		m_apNumber[nCnt]->SetNumber(0);
	}

	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		if (m_apNumber[nCnt] != NULL)
		{
			//�e���ɐ��l��ݒ�
			m_apNumber[nCnt]->SetNumber(nScore % 10);
			nScore /= 10;
		}
	}
}

void CRankingScore::Uninitialize(void)
{
	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		//�i���o�[�̔j��
		if (m_apNumber[nCnt] != NULL)
		{
			m_apNumber[nCnt]->Uninit();
			delete m_apNumber[nCnt];
			m_apNumber[nCnt] = NULL;
		}
	}
	//�V�[���̔j��
	CScene::Release();
}

void CRankingScore::Update(void)
{

}

void CRankingScore::Draw(void)
{
	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		if (m_apNumber[nCnt] != NULL)
		{
			//�i���o�[�̕`�揈��
			m_apNumber[nCnt]->Draw();
		}
	}
}

CRankingScore *CRankingScore::Create(void)
{
	CRankingScore *pRankingScore;

	pRankingScore = new CRankingScore;

	pRankingScore->Initialize();
	pRankingScore->SetObjType(OBJTYPE_SCORE);
	return pRankingScore;
}
