/******************************************************************
***
***		��������
***
***		number.h
***
***		author: Kengo Sakai
***		date:2017/01/23
***
*******************************************************************/
#ifndef _NUMBER_H_
#define _NUMBER_H

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "main.h"
class CRenderer;
/******************************************************************
�}�N����`
*******************************************************************/

/******************************************************************
�\���̂������̓N���X��`
*******************************************************************/
class CNumber
{
public:
	CNumber();								//�R���X�g���N�^
	~CNumber();								//�f�X�g���N�^
	HRESULT Init(int Digit,D3DXVECTOR3 OrderPosition);			//����������
	void Uninit (void);						//�I������
	void Update (void);						//�X�V����
	void Draw (void);						//�`�揈��
	void SetNumber(int nNumber);			//�����Z�b�g����
	void SetMatrix(void);					//�s��ݒ菈��
	static CNumber *Create(int Digit,D3DXVECTOR3 OrderPosition);	//�쐬����

private:
	LPDIRECT3DTEXTURE9 pTexture;	//�e�N�X�`���i�[�ϐ�
	LPDIRECT3DVERTEXBUFFER9 pVtxBuff;		//�o�b�t�@�̃|�C���^
	void MakeVertex(int Digit);

	D3DXVECTOR3 Position;						//�p�[�e�B�N����XY���W
	D3DXVECTOR3 Rot;					//�p�x
	D3DXVECTOR3 Scale;				//�p�x
	
	D3DXMATRIX mtxWorld;							//���[���h�s��
	D3DXMATRIX mtxTrans;							//���s�s��
	D3DXMATRIX mtxRot;							//��]�s��
	D3DXMATRIX mtxScale;							//�g��s��
	D3DXMATRIX mtxInverse;						//�t�s��

	static CRenderer *pRenderer;
	
};
/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************/
#endif