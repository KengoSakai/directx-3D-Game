/******************************************************************
***
***		����
***
***		.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "titleLogo.h"

CTitleLogo::CTitleLogo()
{

}


void CTitleLogo::Initialize(void)
{
	Position = D3DXVECTOR3(400.0f, 100.0f, 0.0f);
	WidthHeight = D3DXVECTOR3(500.0f, 200.0f, 0.0f);
	CScene2D::Initialize();
}

void CTitleLogo::Uninitialize(void)
{
	CScene2D::Uninitialize();
}

void CTitleLogo::Update(void)
{
}

void CTitleLogo::Draw(void)
{
	CScene2D::Draw();
}

/******************************************************************
�I�u�W�F�N�g���������֐�
*******************************************************************/
CTitleLogo *CTitleLogo::Create(void)
{
	//�|�C���^�錾
	CTitleLogo *pTitleLogo;

	//�C���X�^���X����
	pTitleLogo = new CTitleLogo;

	//����������
	pTitleLogo->Initialize();

	pTitleLogo->SetObjType(OBJTYPE_TITLELOGO);
	
	CManager::GetTextureManager()->LoadTexture(CTextureManager::TYPE_TITLELOGO);

	pTitleLogo->BindTexture(CManager::GetTextureManager()->GetTexture(CTextureManager::TYPE_TITLELOGO));

	return pTitleLogo;
}
