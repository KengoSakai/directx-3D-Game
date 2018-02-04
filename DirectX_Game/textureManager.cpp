/******************************************************************
***
***		�e�N�X�`���Ǘ�����
***
***		textureManager.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "manager.h"
#include "renderer.h"
#include "textureManager.h"

/******************************************************************
�R���X�g���N�^
*******************************************************************/
CTextureManager::CTextureManager()
{
	for (int nCnt = 0; nCnt < TYPE_MAX; nCnt++)
	{
		//���X�g�̏�����
		pTextureList[nCnt] = NULL;

		//�|�C���^�̏�����
		pTexture[nCnt] = NULL;
	}
}

/******************************************************************
����������
*******************************************************************/
void CTextureManager::Initialize(void)
{
	//�e�N�X�`�����X�g
	pTextureList[TYPE_MINIMAPPLAYER] = "data/TEXTURE/particle002.png";
	pTextureList[TYPE_PARTICLE] = "data/TEXTURE/particle002.png";
	pTextureList[TYPE_SKY] = "data/TEXTURE/sky001.jpg";
	pTextureList[TYPE_FIELD] = "data/TEXTURE/field000.png";
	pTextureList[TYPE_GAUGEMETER] = "data/TEXTURE/gauge001.png";
	pTextureList[TYPE_GAUGEBOX] = "data/TEXTURE/gauge002.png";
	pTextureList[TYPE_NUMBER] = "data/TEXTURE/score_000.png";
	pTextureList[TYPE_STARTBUTTON] = "data/TEXTURE/startButton000.png";
	pTextureList[TYPE_TREE] = "data/TEXTURE/Tree.jpg";
	pTextureList[TYPE_TITLELOGO] = "data/TEXTURE/TitleLogo.png";
}

/******************************************************************
�I�������֐�
******************************************************************/
void CTextureManager::Uninitialize(void)
{
	for (int TextureCount = 0; TextureCount < TYPE_MAX; TextureCount++)
	{
		if (pTexture[TextureCount] != NULL)
		{
			//�e�N�X�`���C���^�[�t�F�[�X�̊J��
			pTexture[TextureCount]->Release();
			pTexture[TextureCount] = NULL;
		}
	}
}

/******************************************************************
�e�N�X�`���ǂݍ��ݏ����֐�
******************************************************************/
void CTextureManager::LoadTexture(TEXTURE_TYPE TextureType)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//��x�ł��ǂݍ��܂ꂽ��
	if (pTexture[TextureType] == NULL)
	{
		// �e�N�X�`���̐���
		if (FAILED(D3DXCreateTextureFromFile(pDevice, pTextureList[TextureType], &pTexture[TextureType])))	//�G���[�̏ꍇ
		{
			pTexture[TextureType] = NULL;

			MessageBox(NULL, "�摜��ǂݍ��߂܂���ł���", "�G���[���b�Z�[�W", MB_OK);					//�N�����ɕ\������^�C�g���ƃ��b�Z�[�W
			PostQuitMessage(0);
		}
	}
}

/******************************************************************
�e�N�X�`���擾�����֐�
******************************************************************/
LPDIRECT3DTEXTURE9 CTextureManager::GetTexture(TEXTURE_TYPE TextureType)
{
	return pTexture[TextureType];
}


