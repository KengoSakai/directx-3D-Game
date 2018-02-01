/******************************************************************
***
***		�p�[�e�B�N���r���{�[�h����
***
***		particleBillboard.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _PARTICLEBILLBORD_H_
#define _PARTICLEBILLBORD_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "particleManager.h"
#include "textureManager.h"
/******************************************************************
�}�N����`
*******************************************************************/


/******************************************************************
�\���̒�`
*******************************************************************/
class CParticleBillboard : public CParticleManager
{
public:
	CParticleBillboard();				//�R���X�g���N�^
	~CParticleBillboard();			//�f�X�g���N�^
	void Initialize(void);	//����������
	void Uninitialize(void);		//�I������
	void Update(void);		//�X�V����
	void Draw(void);		//�`�揈��
	void SetBillboard(void);
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);	//�e�N�X�`���ǂݍ��ݏ���	
	void SetColor(D3DXCOLOR Color);

	LPDIRECT3DTEXTURE9 pTexture;		//�e�N�X�`���|�C���^

private:
	void MakeVertex(void);							//���_�쐬����

	LPDIRECT3DTEXTURE9 m_pTexture;		//�e�N�X�`���|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//�o�b�t�@�|�C���^
protected:
	void SetRotate(D3DXVECTOR3 Position,float Size);

	D3DXMATRIX RotateMatrix;
	D3DXMATRIX TranslationMatrix;
	D3DXMATRIX InverseMatrix;
	D3DXMATRIX ScaleMatrix;
	D3DXMATRIX WorldMatrix;

	D3DXCOLOR Color;
	float Velocity;
	float Size;
	D3DXVECTOR3 Rotate;
	D3DXVECTOR3 Scale;
	D3DXVECTOR3 Normal;
	D3DXVECTOR3 Position;
	D3DXVECTOR3 EmitterPosition;
};

/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************/
#endif
