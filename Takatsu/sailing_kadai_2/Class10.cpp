#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;


/*******************************************************

C++�Ńk���������R���\�[����ʂō쐬���Ȃ����B
�ȉ��̗v�f�͕K���������Ȃ����B
�^�C�g����ʁA�Q�[�����
�Q�[���I����͕K���^�C�g����ʂɖ߂�Ȃ����B
�N����͕K���^�C�g����ʂɂ��Ȃ����B
�V�[���̑J�ڂɊւ��Ă͎������@�͖��Ȃ��B

*******************************************************/


int main()
{

	srand((unsigned)time(NULL));

	/* �ϐ��錾 */

	int p_1_digit, p_2_digit, p_3_digit;  //player1
	int e_1_digit, e_2_digit, e_3_digit;  //enemy
	int num;  //���͗p�ϐ�
	int HIT, BLOW; //���f�p�ϐ�
	int cnt = 0;
	int flg = 0;


	/* enemy��3���̐����̐ݒ� */

	e_1_digit = rand() % 10;
	do
	{
		e_2_digit = rand() % 10;
	} while (e_2_digit == e_1_digit);
	do
	{
		e_3_digit = rand() % 10;
	} while (e_3_digit == e_1_digit || e_3_digit == e_2_digit);


	do
	{

		/* �^�C�g����� */

		cout << "�k������" << endl;
		cout << "Press any key..." << endl;

		getch();
		system("cls"); //��ʑS����


		do
		{

			/* ���� */
			cout << "3���̐�������͂��Ă�������" << endl;
			cin >> num;

			/* 3���̐������ʂɕ����� */

			p_1_digit = num / 100;
			p_2_digit = num % 100 / 10;
			p_3_digit = num % 10;


			/* ��������������Ƃ�������x���͂��s�� */
			if (p_1_digit == p_2_digit || p_1_digit == p_3_digit || p_2_digit == p_3_digit)continue;


			/* HIT�̐��̌v�Z */

			HIT = 0; //HIT�̏�����

			if (p_1_digit == e_1_digit)HIT++;
			if (p_2_digit == e_2_digit)HIT++;
			if (p_3_digit == e_3_digit)HIT++;


			/* BLOW�̐��̌v�Z */

			BLOW = 0; //BLOW�̏�����

			if (p_1_digit == e_2_digit || p_1_digit == e_3_digit)BLOW++;
			if (p_2_digit == e_1_digit || p_2_digit == e_3_digit)BLOW++;
			if (p_3_digit == e_1_digit || p_3_digit == e_2_digit)BLOW++;


			/* ���ʂ̏o�� */

			cout << "HIT:" << HIT << endl;
			cout << "BLOW" << BLOW << endl;
			cnt++;


			if (HIT == 3)flg = 1;

		} while (flg == 0);


		/* RESULT��� */

		cout << "congratulation!!" << endl;
		cout << "Press any key..." << endl;

		getch();
		system("cls"); //��ʑS����

		cout << "RESULT" << endl;
		cout << "clear:" << cnt << endl;
		cout << "Back Title..." << endl;

		getch();
		system("cls"); //��ʑS����


	} while (flg == 1);


	return 0;

}