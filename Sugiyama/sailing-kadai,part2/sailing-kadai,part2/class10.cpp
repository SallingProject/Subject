#include<iostream>
#include<time.h>
#include<conio.h>
using namespace std;

int Title();
void StartGame();


void main() {

	srand( (unsigned)time(NULL) );

	int TITLE = 0;
	int STRATGAME = 1;
	int END = 2;
	int D_flg = TITLE;
	
	while (D_flg != END) {

		if (D_flg == TITLE)
		{
			D_flg = Title();
		}
		if (D_flg == STRATGAME)
		{
			StartGame();
			D_flg = TITLE;
		}
	}
	
	return;

}

int Title() {

	int Ch;

	cout << "Game Start...'PUSH SPACE KEY'" << endl;
	cout << "Game End...'PUSH ESCAPE KEY'" << endl;

	do 
	{
		Ch = _getch();

	} while (Ch != 0x1b && Ch != 0x20);

	if(Ch == 0x20){

		return 1;
	}
	else if (Ch == 0x1b) {

		return 2;
	}

}

void StartGame() {

	int e_number[3] = { 0 };
	int p_number[3] = { 0 };

	int Rand;
	int p_all_number;

	int hit = 0;
	int brow = 0;

	do{


			Rand = rand() % 1000;
			e_number[0] = Rand / 100;
			e_number[1] = Rand % 100 / 10;
			e_number[2] = Rand % 10;
		

	} while (e_number[0] == e_number[1] || e_number[0] == e_number[2] || e_number[1] == e_number[2]);

		cout << e_number[0] << e_number[1] << e_number[2] << endl;

		do {

			do {

				cout << "３ケタの数字を決めてください。" << endl;
				cout << "つかえる数字は0～9　重複はできません。" << endl;

				cin >> p_all_number;

				p_number[0] = p_all_number / 100;
				p_number[1] = p_all_number % 100 / 10;
				p_number[2] = p_all_number % 10;

			} while (p_number[0] == p_number[1] || p_number[0] == p_number[2] || p_number[1] == p_number[2]);

			//cout << p_number[0] << p_number[1] << p_number[2] << endl;

			
			for (int i = 0; i < 3; i++) {

				if (p_number[i] == e_number[i])hit++;

			}

			if (p_number[0] == e_number[1])brow++;
			if (p_number[0] == e_number[2])brow++;
			if (p_number[1] == e_number[2])brow++;

			cout << "HIT:" << hit << " BROW:" << brow << endl;

		} while (hit != 3);


}
