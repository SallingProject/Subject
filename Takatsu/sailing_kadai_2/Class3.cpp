#include <iostream>
using namespace std;

/***************************************************************

Class1.cpp/ Class2.cpp�ō쐬�����N���X���g�p���܂��B
main�֐����ŃN���X�^�I�u�W�F�N�g���쐬���A
�����o�ϐ���\������֐����Ăяo���Ă��������B

***************************************************************/


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

	/* �֐��Ăяo�� */

	status ob;
	ob.show();

	return;

}