#include <iostream>
using namespace std;

/***************************************************************

Class1.cpp/ Class2.cppで作成したクラスを使用します。
main関数側でクラス型オブジェクトを作成し、
メンバ変数を表示する関数を呼び出してください。

***************************************************************/


class status {

	/* statusクラスは非公開 */

private:
	float hp;      //ライフ用変数
	float attack;  //攻撃力用変数
	float defense; //防御力用変数

public:
	status();      //コンストラクタ
	void show();   //表示用関数

};


status::status()
{

	/* 各変数の初期化 */

	hp = 10;
	attack = 6;
	defense = 4;

}


void status::show()
{

	/* 表示 */

	cout << hp << endl;
	cout << attack << endl;
	cout << defense << endl;

}


void main()
{

	/* 関数呼び出し */

	status ob;
	ob.show();

	return;

}