/******************************************************************
***
***		3D�`�揈��
***
***		scene3D.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _SCENE3D_H_
#define _SCENE3D_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "scene.h"
#include "textureManager.h"
/******************************************************************
�}�N����`
*******************************************************************/

/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
class CScene3D : public CScene
{
public:
	CScene3D();				//�R���X�g���N�^
	~CScene3D();			//�f�X�g���N�^
	void Initialize (void);							//����������
	void Uninitialize(void);								//�I������
	void Update(void);								//�X�V����
	void Draw(void);								//�`�揈��
	
	void BindTexture(LPDIRECT3DTEXTURE9 pOrderTexture);	//�e�N�X�`���ǂݍ��ݏ���	
	void SetPos(D3DXVECTOR3 OrderPosition);		//���W�ݒ菈��
	void SetMatrix(void);			//�s��ݒ菈��
	void SetBillboard(void);
	LPDIRECT3DTEXTURE9 pTexture;		//�e�N�X�`���|�C���^

private:
	void MakeVertex(void);							//���_�쐬����
													//���W���
	
	LPDIRECT3DTEXTURE9 m_pTexture;		//�e�N�X�`���|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//�o�b�t�@�|�C���^
protected:

	D3DXVECTOR3 Position;
	D3DXVECTOR3 Rotate;
	D3DXVECTOR3 Scale;
	D3DXVECTOR3 Vector;
	D3DXCOLOR Color;
	float Size;

	D3DXMATRIX RotateMatrix;
	D3DXMATRIX TranslationMatrix;
	D3DXMATRIX InverseMatrix;
	D3DXMATRIX ScaleMatrix;
	D3DXMATRIX WorldMatrix;
	D3DXMATRIX ShadowMatrix;

};

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************/
#endif