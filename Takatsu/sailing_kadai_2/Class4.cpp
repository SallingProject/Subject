#include <iostream>
using namespace std;


/***********************************************************

Class1.cpp/ Class2.cpp/ Class3.cpp�ō쐬�����N���X��
���ꂼ��̃����o�ϐ��������������������R���X�g���N�^��
�쐬���Ȃ����B�����Ă��̒l��\�����Ȃ���

***********************************************************/


class status {

	/* status�N���X�͔���J */

private:
	float hp;      //���C�t�p�ϐ�
	float attack;  //�U���͗p�ϐ�
	float defense; //�h��͗p�ϐ�

public:
	status(float HP, float ATK, float DEF);      //�R���X�g���N�^
	void show();   //�\���p�֐�

};


status::status(float HP, float ATK, float DEF)
{

	/* �e�ϐ��̏����� */

	hp = HP;
	attack = ATK;
	defense = DEF;

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

	status ob(10, 6, 4);
	ob.show();

	return;

}

