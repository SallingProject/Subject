#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;


/*******************************************************

C++でヌメロンをコンソール画面で作成しなさい。
以下の要素は必ず実装しなさい。
タイトル画面、ゲーム画面
ゲーム終了後は必ずタイトル画面に戻りなさい。
起動後は必ずタイトル画面にしなさい。
シーンの遷移に関しては実装方法は問わない。

*******************************************************/


int main()
{

	srand((unsigned)time(NULL));

	/* 変数宣言 */

	int p_1_digit, p_2_digit, p_3_digit;  //player1
	int e_1_digit, e_2_digit, e_3_digit;  //enemy
	int num;  //入力用変数
	int HIT, BLOW; //判断用変数
	int cnt = 0;
	int flg = 0;


	/* enemyの3桁の数字の設定 */

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

		/* タイトル画面 */

		cout << "ヌメロン" << endl;
		cout << "Press any key..." << endl;

		getch();
		system("cls"); //画面全消去


		do
		{

			/* 入力 */
			cout << "3桁の数字を入力してください" << endl;
			cin >> num;

			/* 3桁の数字を位に分ける */

			p_1_digit = num / 100;
			p_2_digit = num % 100 / 10;
			p_3_digit = num % 10;


			/* 同じ数字があるときもう一度入力を行う */
			if (p_1_digit == p_2_digit || p_1_digit == p_3_digit || p_2_digit == p_3_digit)continue;


			/* HITの数の計算 */

			HIT = 0; //HITの初期化

			if (p_1_digit == e_1_digit)HIT++;
			if (p_2_digit == e_2_digit)HIT++;
			if (p_3_digit == e_3_digit)HIT++;


			/* BLOWの数の計算 */

			BLOW = 0; //BLOWの初期化

			if (p_1_digit == e_2_digit || p_1_digit == e_3_digit)BLOW++;
			if (p_2_digit == e_1_digit || p_2_digit == e_3_digit)BLOW++;
			if (p_3_digit == e_1_digit || p_3_digit == e_2_digit)BLOW++;


			/* 結果の出力 */

			cout << "HIT:" << HIT << endl;
			cout << "BLOW" << BLOW << endl;
			cnt++;


			if (HIT == 3)flg = 1;

		} while (flg == 0);


		/* RESULT画面 */

		cout << "congratulation!!" << endl;
		cout << "Press any key..." << endl;

		getch();
		system("cls"); //画面全消去

		cout << "RESULT" << endl;
		cout << "clear:" << cnt << endl;
		cout << "Back Title..." << endl;

		getch();
		system("cls"); //画面全消去


	} while (flg == 1);


	return 0;

}