/******************************************************************
***
***		�Q�[�W����
***
***		Gauge.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "gaugeMeter.h"
#include "input.h"
#include "gaugeBox.h"
#include "DebugFont.h"
/******************************************************************
�}�N����`
*******************************************************************/
#define NUM_LIFE (500.0f)

/******************************************************************
�\���̒�`�i�N���X�j
*******************************************************************/

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CGaugeMeter::CGaugeMeter()
{

}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CGaugeMeter::~CGaugeMeter()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CGaugeMeter::Initialize(float m_fLife)
{

	//���W�ݒ�
	Position.x = 420.0f;
	Position.y = 605.0f;
	Position.z = 0.0f;

	//���A����
	WidthHeight.x = NUM_Gauge - 40.0f;
	WidthHeight.y = 40.0f;
	WidthHeight.z = 0.0f;

	//���_�F�ݒ�
	Color.r = 0.0f;
	Color.g = 255.0f;
	Color.b = 0.0f;
	Color.a = 255.0f;

	//�̗͐ݒ�
	Life = m_fLife;
	LifeGauge = m_fLife;

	//�Q�[�W�����鑬�x
	GaugeRate = NUM_Gauge / m_fLife;

	//���_�쐬����
	CScene2D::Initialize();
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CGaugeMeter::Uninitialize(void)
{
	CScene2D::Uninitialize();
}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CGaugeMeter::Update(void)
{
	//���_�F��ݒ�
	CScene2D::SetColor(Color);

	//�̗͂������ȉ����R���̂P��葽���Ȃ�
	if (Life <= (LifeGauge / 2) && Life > (LifeGauge / 4))
	{
		Color.r = 255.0f;
	}

	//�̗͂��S���̂P�ȉ��Ȃ�
	else if (Life <= LifeGauge / 4)
	{
		Color.g = 0.0f;
	}

	else
	{

	}

	//�̗͂�0��葽���Ȃ�
	if (Life > 0)
	{
		//Life--;
		WidthHeight.x -= GaugeRate;
	}
}

/******************************************************************
�`�揈���֐�
*******************************************************************/
void CGaugeMeter::Draw(void)
{
	CScene2D::Draw();
	CManager::GetDebugFont()->AddDebugFont("PlayerLife:", Life, 0, 120);
}

/******************************************************************
�I�u�W�F�N�g�쐬�����֐�
*******************************************************************/
CGaugeMeter *CGaugeMeter::Create(float m_fLife)
{
	//�|�C���^
	CGaugeMeter *pGaugeMeter;

	//�������̊m�ہi�C���X�^���X�̐����j
	pGaugeMeter = new CGaugeMeter;

	//����������
	pGaugeMeter->Initialize(m_fLife);

	CManager::GetTextureManager()->LoadTexture(CTextureManager::TYPE_GAUGEMETER);
	
	//�I�u�W�F�N�g�̌^�o�^�֐��Ăяo��
	pGaugeMeter->SetObjType(OBJTYPE_GAUGE);

	//�e�N�X�`�������蓖�Ă�
	pGaugeMeter->BindTexture(CManager::GetTextureManager()->GetTexture(CTextureManager::TYPE_GAUGEMETER));

	return pGaugeMeter;

}

void CGaugeMeter::SubGauge(float SubLife)
{
	//Life -= SubLife;

	for (int count = 0; count < SubLife; count++)
	{
		WidthHeight.x -= GaugeRate;
		CScene2D::SetPosition();
	}
}

