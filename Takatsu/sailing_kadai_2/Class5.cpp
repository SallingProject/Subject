#include <iostream>

using namespace std;

/***********************************************************

�N���XBase�N���X���쐬���Ȃ����B�v���͈ȉ��̂��̂Ƃ���B
�X�V�������s�����z�֐��B���J���x���́u���J�v
���̊֐���Base�Əo�͂���悤�ɂ��Amain�֐��ŌĂяo���Ȃ����B

***********************************************************/


class Base {

public:
	virtual void show()
	{
		//�X�V����
		/* Base�̕\�� */
		cout << "Base" << endl;

	}

};


void main()
{

	Base data;

	data.show();

	return;
}