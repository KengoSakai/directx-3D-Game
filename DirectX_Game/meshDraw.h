/******************************************************************
***
***		���b�V���t�B�[���h�����i�w�b�_�[�j
***
***		MeshField.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _MESHDRAW_H_
#define _MESHDRAW_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "scene.h"
#include "textureManager.h"
/******************************************************************
�}�N����`
*******************************************************************/

/******************************************************************
�N���X��`
*******************************************************************/
class CMeshDraw : public CScene
{
public:
	CMeshDraw();		//�R���X�g���N�^
	~CMeshDraw() {}			//�f�X�g���N�^
	void Initialize(void);		//����������
	void Uninitialize(void);		//�I������
	void Update(void);		//�X�V����
	void Draw(void);		//�`�揈��
	void SetMatrix(void);	//�s��ݒ菈��
	void BindTexture(LPDIRECT3DTEXTURE9 pOrderTexture);				//�e�N�X�`���ǂݍ��ݏ���
private:
	void MakeVertex(void);	//���_�쐬����
	void MakeIndex(void);	//�C���f�b�N�X�o�b�t�@�ݒ菈��

	LPDIRECT3DTEXTURE9 pTexture;		//�e�N�X�`���|�C���^
	LPDIRECT3DVERTEXBUFFER9 pVertexBuffer;	//�o�b�t�@�|�C���^
	LPDIRECT3DINDEXBUFFER9 pIndexBuffer;	//�C���f�b�N�X�o�b�t�@�|�C���^
protected:
	D3DXVECTOR3 Position;		//���W
	D3DXVECTOR3 Rotate;			//�p�x
	D3DXVECTOR3 Scale;			//�g�嗦

	D3DXMATRIX RotateMatrix;
	D3DXMATRIX TranslationMatrix;
	D3DXMATRIX ScaleMatrix;
	D3DXMATRIX WorldMatrix;

};

#endif