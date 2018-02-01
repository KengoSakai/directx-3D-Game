/******************************************************************
***
***		3D���f������
***
***		model.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _MODEL_H_
#define _MODEL_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "scene.h"
#include "modelManager.h"
#include "textureManager.h"
/******************************************************************
�}�N����`
*******************************************************************/

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
class CModel : public CScene
{
public:
	CModel();					//�R���X�g���N�^
	~CModel();					//�f�X�g���N�^
	void Initialize(void);
	void Uninitialize(void);	//�I������
	void Update(void);
	void Draw(void);			//�`�揈��
	void DrawShadow(void);
	void BindBuff(LPD3DXBUFFER pOrderMatBuff);						//�o�b�t�@���ǂݍ��ݏ���
	void BindMesh(LPD3DXMESH pOrderMesh);
	void BindMaterials(DWORD OrderNumMaterials);					//�v�f���ǂݍ��ݏ���
	void BindTexture(LPDIRECT3DTEXTURE9 pOrderTexture);
	void SetMatrix(void);

private:
	LPD3DXMESH pMesh;			//���b�V��
	LPD3DXBUFFER pMaterialBuffer;	//�o�b�t�@�|�C���^
	DWORD NumMaterials;	//�v�f��
	LPDIRECT3DTEXTURE9 pTexture;		//�e�N�X�`���|�C���^
	void SetModel(void);

protected:
	//���W���
	D3DXVECTOR3 Position;
	D3DXVECTOR3 Rotate;
	D3DXVECTOR3 Scale;
	D3DXVECTOR3 Vector;

	D3DXMATRIX RotateMatrix;
	D3DXMATRIX TranslationMatrix;
	D3DXMATRIX InverseMatrix;
	D3DXMATRIX ScaleMatrix;
	D3DXMATRIX WorldMatrix;
	D3DXMATRIX ShadowMatrix;

};
#endif