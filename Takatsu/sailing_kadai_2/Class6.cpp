#include <iostream>

using namespace std;

/**************************************************************

Class5.cpp�ō쐬����Base�N���X���p�����A
Derivation�N���X���쐬���Ȃ����B���̂Ƃ�Base�N���X��
�X�V�����֐����I�[�o�[���C�h����Derivation�Əo�͂���悤�ɂ��A
main�֐��ŌĂяo���Ȃ����B

**************************************************************/


class Base {

public:
	virtual void show()
	{
		//�X�V����
		/* Base�̕\�� */
		cout << "Base" << endl;

	}

};


class Derivation : public Base {

public:
	void show()
	{

		/* Derivation�Əo�� */
		cout << "Derivation" << endl;

	}

};

void main()
{

	Derivation data;

	data.show();

	return;
}