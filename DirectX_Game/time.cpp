/******************************************************************
***
***		���ԏ���
***
***		time.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "time.h"
#include "number.h"
/******************************************************************
�R���X�g���N�^
*******************************************************************/
CTime::CTime()
{
	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < TIME_DIGIT; nCnt++)
	{
		//NULL������
		m_apNumber[nCnt] = NULL;
	}
	m_nTime = 60 * 60;
}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CTime :: ~CTime()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CTime::Initialize(void)
{
	Position = D3DXVECTOR3((float)(SCREEN_WIDTH / 2), 20.0f, 0.0f);

	int nTime = 0;

	nTime = m_nTime;

	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < TIME_DIGIT; nCnt++)
	{
		//�i���o�[�̐���
		m_apNumber[nCnt] = CNumber::Create(nCnt, Position);

		//�e���ɐ�����ݒ�
		m_apNumber[nCnt]->SetNumber(nTime % 10);
		nTime /= 10;
	}
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CTime::Uninitialize(void)
{
	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < TIME_DIGIT; nCnt++)
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
void CTime::Update(void)
{
	SubTime();
}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CTime::Draw(void)
{
	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < TIME_DIGIT; nCnt++)
	{
		if (m_apNumber[nCnt] != NULL)
		{
			//�i���o�[�̕`�揈��
			m_apNumber[nCnt]->Draw();
		}
	}
}

/******************************************************************
�I�u�W�F�N�g�����֐�
*******************************************************************/
CTime *CTime::Create(void)
{
	//�I�u�W�F�N�g�|�C���^
	CTime *pTime;

	//�C���X�^���X�̐���
	pTime = new CTime;

	//����������
	pTime->Initialize();

	pTime->SetObjType(OBJTYPE_TIME);

	return pTime;
}

/******************************************************************
���Z�����֐�
*******************************************************************/
void CTime::AddTime(void)
{
	int nTime = 0;
	int nAddTime = m_nTime;

	nAddTime /= 60;

	//���l�̉��Z
	nTime = nAddTime;

	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < TIME_DIGIT; nCnt++)
	{
		if (m_apNumber[nCnt] != NULL)
		{
			//�e���ɐ��l��ݒ�
			m_apNumber[nCnt]->SetNumber(nTime % 10);
			nTime /= 10;
		}
	}
	m_nTime++;
}

/******************************************************************
���Z�����֐�
*******************************************************************/
void CTime::SubTime(void)
{
	int nTime = 0;
	int nSubTime = m_nTime;

	nSubTime /= 60;

	//���l�̌��Z
	nTime = nSubTime;

	//�\���������J��Ԃ�
	for (int nCnt = 0; nCnt < TIME_DIGIT; nCnt++)
	{
		if (m_apNumber[nCnt] != NULL)
		{
			//�e���ɐ��l��ݒ�
			m_apNumber[nCnt]->SetNumber(nTime % 10);
			nTime /= 10;
		}
	}
	m_nTime--;
}

/******************************************************************
���Ԏ擾�����֐�
*******************************************************************/
int CTime::GetTime(void)
{
	return m_nTime;
}
