/******************************************************************
***
***		�J��������
***
***		camera.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "scene.h"
#include "player.h"
#include "renderer.h"
#include "camera.h"
#include "light.h"
/******************************************************************
�R���X�g���N�^
*******************************************************************/
CCamera::CCamera()
{

}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CCamera::~CCamera()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
HRESULT CCamera::Init(void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pD3DDevice =  CManager::GetRenderer()->GetDevice();

	m_VecUp = D3DXVECTOR3(0.0f,1.0f,0.0f);		//�J�����̏�����̌���
	m_PosAt = D3DXVECTOR3(0.0f,0.0f,0.0f);		//�J�����̒����_
	m_PosView = D3DXVECTOR3(0.0f,50.0f,-300.0f);	//�J�����̈ʒu
	m_fRot = -90.0f;

	//�v���W�F�N�V�����}�g���N�X�����	
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection, D3DX_PI/3.0f, (float)SCREEN_WIDTH/SCREEN_HEIGHT,1.0f,3000.0f);

	//�f�o�C�X�Ƀv���W�F�N�V�����ϊ��s���ݒ�
	pD3DDevice->SetTransform(D3DTS_PROJECTION,&m_mtxProjection);

	D3DXMatrixLookAtLH(&m_MtxView, &m_PosView, &m_PosAt, &m_VecUp);
	pD3DDevice->SetTransform(D3DTS_VIEW,&m_MtxView);

	return S_OK;
}

/******************************************************************
�I�������֐�
*******************************************************************/
void CCamera::Uninit(void)
{

}

/******************************************************************
�X�V�����֐�
*******************************************************************/
void CCamera::Update (void)
{
	//�f�o�C�X�����擾
	LPDIRECT3DDEVICE9 pD3DDevice = CManager::GetRenderer()->GetDevice();

	if(CManager :: GetInputKeyboard()->GetKeyPress(DIK_LEFT))
	{
		m_fRot -= 1.0f;
	}

	if (CManager::GetInputKeyboard()->GetKeyPress(DIK_RIGHT))
	{
		m_fRot += 1.0f;
	}
	
	//�I�u�W�F�N�g���J��Ԃ�
	for (int nCntScene = 0; nCntScene < 100; nCntScene++)
	{
		//�I�u�W�F�N�g�̏��擾
		CScene *pScene;
		pScene = CScene::GetScene(nCntScene);

		//�I�u�W�F�N�g�̃|�C���^�[��NULL�łȂ��Ȃ�
		if (pScene != NULL)
		{
			//�I�u�W�F�N�g�̌^���擾
			CScene::OBJTYPE ObjType;
			ObjType = pScene->GetObjType();

			//�w�肵���I�u�W�F�N�g�Ȃ�
			if (ObjType == CScene::OBJTYPE_PLAYER)
			{
				//�I�u�W�F�N�g�|�C���^
				CPlayer *pPlayer = (CPlayer*)pScene;

				//�v���C���[�̍��W�擾���ĒǏ]
				m_PosView.z = pPlayer->GetPosition().z;
				m_PosView.x = pPlayer->GetPosition().x;
				m_PosView.y = pPlayer->GetPosition().y+20.0f;
				m_PosView.x += cosf(D3DXToRadian(m_fRot))*100.0f;
				m_PosView.z += sinf(D3DXToRadian(m_fRot))*100.0f;
		
				//�����_���v���C���[�̍��W�ɐݒ�
				m_PosAt = pPlayer->GetPosition();
			}
		}
	}
	//�s��ϊ�
	D3DXMatrixLookAtLH(&m_MtxView, &m_PosView, &m_PosAt, &m_VecUp);

	//�r���[�s��ɐݒ�
	pD3DDevice->SetTransform(D3DTS_VIEW,&m_MtxView);

	//CManager::GetLight()->SetCameraLight();
}
