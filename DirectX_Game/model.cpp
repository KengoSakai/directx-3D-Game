/******************************************************************
***
***		3D���f������
***
***		model.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "light.h"
/******************************************************************
�}�N����`
*******************************************************************/

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CModel::CModel()
{

}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CModel::~CModel()
{

}

/******************************************************************
�����������֐�
*******************************************************************/
void CModel::Initialize(void)
{
	pTexture = NULL;
	pMesh = NULL;
	pMaterialBuffer = NULL;
	NumMaterials = 0;
	Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	Scale = D3DXVECTOR3(1.0f,1.0f,1.0f);
	Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	Vector = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

/******************************************************************
���f���I�������֐�
*******************************************************************/
void CModel::Uninitialize(void)
{
	CScene::Release();
}

/******************************************************************
���f���X�V�����֐�
*******************************************************************/
void CModel::Update(void)
{

}

/******************************************************************
���f���`�揈���֐�
*******************************************************************/
void CModel::Draw(void)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	CManager::GetLight()->SetModelLight();
	D3DMATERIAL9 Matdef;

	pDevice->GetMaterial(&Matdef);
	D3DXMATERIAL* pMat = (D3DXMATERIAL*)pMaterialBuffer->GetBufferPointer();

	//�}�e���A�������J��Ԃ�
	for(DWORD count = 0 ; count < NumMaterials ; count++ )
	{
		//���f�����Z�b�g
		pDevice->SetMaterial(&pMat[count].MatD3D);
		pDevice->SetTexture(0,pTexture);

		//�`��֐��Ăяo��
		pMesh->DrawSubset(count);
	}
	pDevice->SetMaterial(&Matdef);
	DrawShadow();
}

void CModel::SetMatrix(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pD3DDevice =  CManager::GetRenderer()->GetDevice();

	//�P�ʍs��
	D3DXMatrixIdentity(&WorldMatrix);
	
	//�g��s��
	D3DXMatrixScaling(&ScaleMatrix,Scale.x,Scale.y,Scale.z);
	
	//���s�s��
	D3DXMatrixTranslation(&TranslationMatrix,Position.x, Position.y, Position.z);
	
	//��]�s��
	D3DXMatrixRotationYawPitchRoll(&RotateMatrix,
		D3DXToRadian(Rotate.y),
		D3DXToRadian(Rotate.x),
		D3DXToRadian(Rotate.z));

	//���[���h�ϊ�
	WorldMatrix = ScaleMatrix * RotateMatrix * TranslationMatrix;

	//���[���h���W�ɐݒ�
	pD3DDevice->SetTransform(D3DTS_WORLD,&WorldMatrix);

}
/******************************************************************
�}�e���A���o�b�t�@���ǂݍ��ݏ����֐�
*******************************************************************/
void CModel::BindBuff(LPD3DXBUFFER pOrderMatBuff)
{
	pMaterialBuffer = pOrderMatBuff;
}

/******************************************************************
�v�f�����ǂݍ��ݏ����֐�
*******************************************************************/
void CModel::BindMaterials(DWORD OrderNumMaterials)
{
	NumMaterials = OrderNumMaterials;
}

/******************************************************************
���b�V�����ǂݍ��ݏ����֐�
*******************************************************************/
void CModel::BindMesh(LPD3DXMESH pOrderMesh)
{
	pMesh = pOrderMesh;
}

/******************************************************************
�e�N�X�`���ǂݍ��ݏ����֐�
*******************************************************************/
void CModel :: BindTexture(LPDIRECT3DTEXTURE9 pOrderTexture)
{
	pTexture = pOrderTexture;
}

void CModel::DrawShadow(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pD3DDevice = CManager::GetRenderer()->GetDevice();
	D3DXVECTOR3 LightVector;
	D3DXVECTOR3 Light;
	D3DXMatrixIdentity(&ShadowMatrix);
	LightVector = Position - CManager::GetLight()->GetPosition();

	ShadowMatrix._21 = -LightVector.x/ LightVector.y;
	ShadowMatrix._22 = 0.0f;
	ShadowMatrix._23 = -LightVector.z / LightVector.y;
	ShadowMatrix._42 = 0.5f;
	WorldMatrix = WorldMatrix * ShadowMatrix;

	//���[���h���W�ɐݒ�
	pD3DDevice->SetTransform(D3DTS_WORLD, &WorldMatrix);

	CManager::GetLight()->SetShadowLight();
	
	D3DMATERIAL9 Matdef;

	pD3DDevice->GetMaterial(&Matdef);
	D3DXMATERIAL* pMat = (D3DXMATERIAL*)pMaterialBuffer->GetBufferPointer();

	//�}�e���A�������J��Ԃ�
	for (DWORD count = 0; count < NumMaterials; count++)
	{
		//���f�����Z�b�g
		pD3DDevice->SetMaterial(&pMat[count].MatD3D);
		//pDevice->SetTexture(0,pTexture);//m_pTexture[nCnt]);
		pD3DDevice->SetTexture(0, NULL);//m_pTexture[nCnt]);

									 //�`��֐��Ăяo��
		pMesh->DrawSubset(count);
	}
	pD3DDevice->SetMaterial(&Matdef);
}

void CModel::SetModel(void)
{

}