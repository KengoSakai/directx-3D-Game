
class CDebugFont
{
public:
	CDebugFont();							//�R���X�g���N�^
	~CDebugFont();	//�f�X�g���N�^
	void Initialize(void);
	void Uninitialize(void);
	void AddDebugFont( char *AddDebugFont, float ObjectValue,int PositionX , int PositionY);	//�f�o�b�O�\���ǉ�����

private:
	LPD3DXFONT pDebugFont;				//�f�o�b�O�\���C���^�[�t�F�[�X
};
