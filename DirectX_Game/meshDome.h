/******************************************************************
***
***		���b�V���h�[������
***
***		meshDome.h
***
***		author: Kengo Sakai
***
*******************************************************************/
#ifndef _MESHDOME_H_
#define _MESHDOME_H_
/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "scene.h"
/******************************************************************
�}�N����`
*******************************************************************/
class CRenderer;
/******************************************************************
�\���̂܂��̓N���X��`
*******************************************************************/
class CMeshDome : public CScene
{
public:
	CMeshDome();		//�R���X�g���N�^
	~CMeshDome();		//�f�X�g���N�^
	void Initialize(void);	//����������
	void Uninitialize(void);	//�I������
	void Update(void);	//�X�V����
	void Draw(void);	//�`�揈��
	static CMeshDome *Create(void);
private:
	void MakeVertex(void);
	void MakeIndex(void);
	void SetColor(void);
	 LPDIRECT3DTEXTURE9 pTexture;		//�e�N�X�`���|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//�o�b�t�@�|�C���^
	LPDIRECT3DINDEXBUFFER9 m_IndexBuff;	//�C���f�b�N�X�o�b�t�@�|�C���^
	D3DXCOLOR Color;
	D3DXVECTOR3 m_Pos;					//���W
	D3DXVECTOR3 m_Rot;					//�p�x
	D3DXVECTOR3 m_Scale;				//�p�x

	//�s��ݒ�
	D3DXMATRIX m_mtxWorld;							//���[���h�s��
	D3DXMATRIX m_mtxTrans;							//���s�s��
	D3DXMATRIX m_mtxRot;							//��]�s��
	D3DXMATRIX m_mtxScale;							//�g��E�k���s��

	static CRenderer *m_pRenderer;
};
/******************************************************************
�v���g�^�C�v�錾
*******************************************************************/

/******************************************************************
�O���[�o���ϐ�
*******************************************************************/

/******************************************************************/
#endif
