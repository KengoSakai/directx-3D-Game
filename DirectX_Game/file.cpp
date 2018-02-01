/******************************************************************
***
***		�t�@�C������
***
***		file.cpp
***
***		author: Kengo Sakai
***
*******************************************************************/

/******************************************************************
�C���N���[�h�t�@�C��
*******************************************************************/
#include "file.h"

/******************************************************************
�t�@�C���Z�[�u�����֐�
*******************************************************************/
void CFile::Save(char *OpenFileName, int NumberData, int Score)
{
	FILE *pFile = NULL;

	pFile = fopen(OpenFileName, "wb");	//�t�@�C�����J��

	//�f�[�^������ꍇ
	if (pFile != NULL)
	{
		//���͂����l�����t�@�C���ɏ����o��
		fwrite(&NumberData, sizeof(int), 1, pFile);
		
		//���͂����X�e�[�^�X���t�@�C���ɏ����o��
		fwrite(&Score, sizeof(int), NumberData, pFile);
		
		//�t�@�C�������
		fclose(pFile);
	}

	//�f�[�^���Ȃ��ꍇ
	else
	{
		//�N�����ɕ\������^�C�g���ƃ��b�Z�[�W
		MessageBox(NULL, "�f�[�^���L�^�ł��܂���ł���", "�G���[���b�Z�[�W", MB_OK);					
	}
}

/******************************************************************
�t�@�C�����[�h�����֐�
*******************************************************************/
int CFile::Load(char *OpenFileName, int NumberData)
{
	//�t�@�C���|�C���^
	FILE *pFile=NULL;

	//�X�R�A�p�ϐ�
	int Score = 0;

	//�t�@�C�����J��
	pFile = fopen(OpenFileName, "rb");

	//�t�@�C���|�C���^��NULL�łȂ��ꍇ
	if (pFile != NULL)
	{
		//���͂���Ă����l�����t�@�C����ǂ݂���
		fread(&NumberData, sizeof(int), 1, pFile);	
		
		//���͂��ꂽ�X�e�[�^�X��ǂ݂���
		fread(&Score, sizeof(int), NumberData, pFile);
		
		//�t�@�C�������
		fclose(pFile);
	}

	//�t�@�C���|�C���^���ǂݍ��߂Ȃ������ꍇ
	else
	{
		//�N�����ɕ\������^�C�g���ƃ��b�Z�[�W
		MessageBox(NULL, "�f�[�^��ǂݍ��߂܂���ł���", "�G���[���b�Z�[�W", MB_OK);					
	}

	return Score;
}
