/******************************************************************
***
***		�V�F�[�_����
***
***		shader.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "camera.h"
/******************************************************************
�}�N����`
*******************************************************************/

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************/

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CShader::CShader()
{
	pPixelShader = NULL;
	pVertexShader = NULL;
	ShadersConstantTable = NULL;
}

/******************************************************************
�f�X�g���N�^
*******************************************************************/
CShader::~CShader()
{

}
/******************************************************************
�����������֐�
*******************************************************************/
void CShader::Initialize(void)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DVERTEXELEMENT9 VertexElem[3];
	IDirect3DVertexDeclaration9 *pDeclaration;
	D3DXMATRIX WorldMatrix;
	D3DXMATRIX ScaleMatrix;
	D3DXMATRIX ShadersMatrix;
	D3DXMATRIX TransMatrix;
	D3DXMATRIX RotationMatrix;
	D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Rot(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Scale(1.0f, 1.0f, 1.0f);

	D3DXMatrixRotationZ(&WorldMatrix, 180.0f);
	//�s��ϊ�
	D3DXMatrixIdentity(&WorldMatrix);	//�P�ʍs��
	D3DXMatrixRotationYawPitchRoll(&RotationMatrix,
		D3DXToRadian(Rot.y),
		D3DXToRadian(Rot.x),
		D3DXToRadian(Rot.z));	//��]�s��
	D3DXMatrixScaling(&ScaleMatrix, Scale.x, Scale.y, Scale.z);	//�g��s��
	D3DXMatrixTranslation(&TransMatrix, Pos.x, Pos.y, Pos.z);	//���s�s��

	D3DXMatrixMultiply(&WorldMatrix, &WorldMatrix, &ScaleMatrix);
	WorldMatrix = RotationMatrix *ScaleMatrix *  TransMatrix;

	ShadersMatrix = WorldMatrix;//* CManager::GetCamera()->GetViewMatrix() * CManager::GetCamera()->GetProjectionMatrix();

	//���_���W���̐錾
	VertexElem[0].Stream = 0;
	VertexElem[0].Offset = 0;
	VertexElem[0].Type = D3DDECLTYPE_FLOAT3;
	VertexElem[0].Method = D3DDECLMETHOD_DEFAULT;
	VertexElem[0].Usage = D3DDECLUSAGE_POSITION;
	VertexElem[0].UsageIndex = 0;

	//���_�J���[���̐錾
	VertexElem[1].Stream = 0;
	VertexElem[1].Offset = 12;
	VertexElem[1].Type = D3DDECLTYPE_D3DCOLOR;
	VertexElem[1].Method = D3DDECLMETHOD_DEFAULT;
	VertexElem[1].Usage = D3DDECLUSAGE_COLOR;
	VertexElem[1].UsageIndex = 0;

	//�I�[�錾
	VertexElem[2].Stream = 0xFF;
	VertexElem[2].Offset = 0;
	VertexElem[2].Type = D3DDECLTYPE_UNUSED;
	VertexElem[2].Method = 0;
	VertexElem[2].Usage = 0;
	VertexElem[2].UsageIndex = 0;

	pDevice->CreateVertexDeclaration(VertexElem, &pDeclaration);

	//���_�V�F�[�_�t�@�C�����R���p�C��
	D3DXCompileShaderFromFile(
		"VertexShader.hlsl",
		NULL,
		NULL,
		"main",
		"vs_3_0",
		0,
		&Code,		//�����p��
		&Error,
		&ShadersConstantTable);

	ShadersConstantTable->SetMatrix(pDevice, "WorldViewProjectionMatrix", &ShadersMatrix);

	//���_�V�F�[�_�𐶐�
	pDevice->CreateVertexShader((LPDWORD)Code->GetBufferPointer(), &pVertexShader);

	//�s�N�Z���V�F�[�_�t�@�C�����R���p�C��
	D3DXCompileShaderFromFile(
		"PixelShader3D.hlsl",
		NULL,
		NULL,
		"main",
		"ps_3_0",
		0,
		&Code,		//�����p��
		&Error,
		&ShadersConstantTable);

	//�s�N�Z���V�F�[�_�𐶐�
	pDevice->CreatePixelShader((LPDWORD)Code->GetBufferPointer(), &pPixelShader);
}

//�I������
void CShader::Uninitialize(void)
{
	//�s�N�Z���V�F�[�_�̊J��
	if (pPixelShader != NULL)
	{
		pPixelShader->Release();
		pPixelShader = NULL;
	}

	//���_�V�F�[�_�̊J��
	if (pPixelShader != NULL)
	{
		pPixelShader->Release();
		pPixelShader = NULL;
	}

	if (ShadersConstantTable != NULL)
	{
		ShadersConstantTable->Release();
		ShadersConstantTable = NULL;
	}
}

//�V�F�[�_�J�n�֐�
void CShader::BeginShader(void)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//���_�V�F�[�_��ݒ�
	pDevice->SetVertexShader(pVertexShader);

	//�s�N�Z���V�F�[�_��ݒ�
	pDevice->SetPixelShader(pPixelShader);
}

//�V�F�[�_�I������
void CShader::EndShader(void)
{

}

//�A�Z���u���V�F�[�_�[����
void CShader::AssembleShader(void)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

//	IDirect3DVertexShader9 *pVertexShaderHandler;	//���_�V�F�[�_�n���h��
	IDirect3DPixelShader9 *pPixelShaderHandler;		//�s�N�Z���V�F�[�_�n���h��
	ID3DXBuffer *pShader;							//�V�F�[�_���ߊi�[�o�b�t�@
	ID3DXBuffer *pError;							//�R���p�C���G���[���i�[�o�b�t�@

													//���_�V�F�[�_�z��̒�`�B
	const char VertexShader[] =
		"vs_1_1 \n"
		"dcl_position v0 \n"
		"dcl_color v1 \n"
		"m4x4 oPos, v0, c0 \n"
		"add oD0, v1, c4 \n";

	//�s�N�Z���V�F�[�_�z��̒�`
	const char PixelShader[] =
		"ps_1_1\n"
		"def c0 , 0.2989f , 0.5866f , 0.1145f , 1.0f \n"	//�ʓx�Z�o�W��
		"tex t0 \n"											//�e�N�X�`��0�Ԏg�p
		"dp3 r0 , t0 , c0  \n"								//�ʓxY�Z�o�ir.a�Ɋi�[�����j
		"mov r1 , r0.a \n"									//r0�̊e������Y�Ŗ��߂�
		"lrp r0 , c1 , t0 , r1 \n";						//���`��ԁiv0+c1*(Y-v0)�j

														//���_�V�F�[�_�̃R���p�C������
	D3DXAssembleShader(
		VertexShader,			//���ߔz��ւ̃|�C���^
		sizeof(VertexShader) - 1,	//���ߕ������i-1��NULL�������Ȃ����߁j
		0,					//�v���v���Z�b�T��`
		NULL,				//�C���N���[�h���ߎw��
		0,					//�R���p�C���I�v�V����
		&pShader,			//�V�F�[�_�o�b�t�@
		&pError				//�R���p�C���G���[�o�b�t�@
	);

	//���_�V�F�[�_�̐���
	//pDevice->CreateVertexShader((DWORD*)pShader->GetBufferPointer(),&pVertexShaderHandler);

	//���_�V�F�[�_�ɐ؂�ւ�
	//pDevice->SetVertexShader(pVertexShaderHandler);

	//�s�N�Z���V�F�[�_�̃R���p�C������
	D3DXAssembleShader(
		PixelShader,			//���ߔz��ւ̃|�C���^
		sizeof(PixelShader) - 1,	//���ߕ������i-1��NULL�������Ȃ����߁j
		0,					//�v���v���Z�b�T��`
		NULL,				//�C���N���[�h���ߎw��
		0,					//�R���p�C���I�v�V����
		&pShader,			//�V�F�[�_�o�b�t�@
		&pError				//�R���p�C���G���[�o�b�t�@
	);

	//�s�N�Z���V�F�[�_�̐���
	pDevice->CreatePixelShader((DWORD*)pShader->GetBufferPointer(), &pPixelShaderHandler);

	//�s�N�Z���V�F�[�_�ɐ؂�ւ�
	pDevice->SetPixelShader(pPixelShaderHandler);

	//�V�F�[�_���߃o�b�t�@�̊J��
	if (pShader != NULL)
	{
		pShader->Release();
		pShader = NULL;
	}

	//�G���[�o�b�t�@�̊J��
	if (pError != NULL)
	{
		pError->Release();
		pError = NULL;
	}
}
