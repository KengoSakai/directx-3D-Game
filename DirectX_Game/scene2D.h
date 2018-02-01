/******************************************************************
***
***		�V�[���QD����
***
***		scene2D.h
***
***		author: Kengo Sakai
***
*******************************************************************/

#ifndef _SCENE2D_H_
#define _SCENE2D_H_
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
class CScene2D : public CScene
{
public:
	CScene2D ();			//�R���X�g���N�^
	~CScene2D ();			//�f�X�g���N�^
	void Initialize(void);	//����������
	void Uninitialize(void);		//�I������
	void Update(void);
	void Draw (void);		//�`�揈��
	
	void SetTexPos(D3DXVECTOR3 TexPos , D3DXVECTOR3 TexWh);			//�e�N�X�`�����W�ݒ菈��
	void SetColor (D3DXCOLOR OrderColor);								//���_�F�ݒ菈��
	void SetPosition(void);
	void BindTexture (LPDIRECT3DTEXTURE9 pOrderTexture);				//�e�N�X�`���ǂݍ��ݏ���
private:
	LPDIRECT3DTEXTURE9 m_pTexture;		//�e�N�X�`���|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//�o�b�t�@�|�C���^

protected:
	D3DXVECTOR3 Position;
	D3DXVECTOR3 WidthHeight;
	D3DXVECTOR3 Rotate;
	D3DXVECTOR3 Scale;
	D3DXVECTOR3 Vector;
	D3DXCOLOR Color;
};

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

#endif
