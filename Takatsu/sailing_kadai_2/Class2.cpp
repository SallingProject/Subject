#include <iostream>
using namespace std;


/***********************************************************

Class1.cpp�ō쐬�����N���X�Ƀ����o�֐���ǉ����Ă��������B
�v���͈ȉ��̒ʂ�ł��B
�֐��̃A�N�Z�X���x���́u���J�v�ɂ��Ă��������B
�@Class1.cpp�̒�`���������o�ϐ���\������֐�
�R���\�[���ł̏o�͕͂s�v�ł��B

***********************************************************/


class status {

	/* status�N���X�͔���J */
private:
	float hp;      //���C�t�p�ϐ�
	float attack;  //�U���͗p�ϐ�
	float defense; //�h��͗p�ϐ�

public:
	status();      //�R���X�g���N�^
	void show();   //�\���p�֐�

};


status::status()
{

	/* �e�ϐ��̏����� */
	hp = 10;
	attack = 6;
	defense = 4;

}


void status::show()
{

	/* �\�� */
	cout << hp << endl;
	cout << attack << endl;
	cout << defense << endl;

}


void main()
{

	return;

}