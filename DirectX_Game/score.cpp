/******************************************************************
***
***		�X�R�A����
***
***		score.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "number.h"
#include "score.h"
#include "file.h"
/******************************************************************
�R���X�g���N�^
*******************************************************************/
CScore::CScore(OBJTYPE type)
{
	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		//NULL������
		m_apNumber[nCnt] = NULL;
	}

	if (type == OBJTYPE_SCORE)
	{
		//�ϐ�������
		Position = D3DXVECTOR3(300.0f, 30.0f, 0.0f);
		return;
	}

	else if (type == OBJTYPE_OTHERPLAYERSCORE)
	{
		//�ϐ�������
		Position = D3DXVECTOR3(1200.0f, 30.0f, 0.0f);
		return;
	}

	else
	{
		return;
	}
}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CScore :: ~CScore()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CScore::Initialize(void)
{
	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		//�i���o�[�̐���
		m_apNumber[nCnt] = CNumber::Create(nCnt, Position);

		//�����l��ݒ�
		m_nScore = 0;

		//�e���ɐ�����ݒ�
		m_apNumber[nCnt]->SetNumber(0);
	}
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CScore::Uninitialize(void)
{
	CFile::Save("score.bin",1,m_nScore);

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

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CScore::Update(void)
{

}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CScore::Draw(void)
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

/******************************************************************
�I�u�W�F�N�g���������֐�
*******************************************************************/
CScore *CScore::Create(OBJTYPE type)
{
	//�|�C���^�錾
	CScore *pScore;

	//�C���X�^���X����
	pScore = new CScore(type);

	//����������
	pScore->Initialize();

	pScore->SetObjType(type);

	return pScore;
}

/******************************************************************
�X�R�A���Z�����֐�
*******************************************************************/
void CScore::AddScore(int nValue)
{
	int nScore;

	//���l�̉��Z
	m_nScore += nValue;

	nScore = m_nScore;

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

/******************************************************************
�X�R�A���擾�����֐�
*******************************************************************/
int CScore::GetScore(void)
{
	return m_nScore;
}

