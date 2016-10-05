#include <iostream>
using namespace std;


/***********************************************************

Class1.cpp/ Class2.cpp/ Class3.cppで作成したクラスの
それぞれのメンバ変数を初期化する引数ありコンストラクタを
作成しなさい。そしてその値を表示しなさい

***********************************************************/


class status {

	/* statusクラスは非公開 */

private:
	float hp;      //ライフ用変数
	float attack;  //攻撃力用変数
	float defense; //防御力用変数

public:
	status(float HP, float ATK, float DEF);      //コンストラクタ
	void show();   //表示用関数

};


status::status(float HP, float ATK, float DEF)
{

	/* 各変数の初期化 */

	hp = HP;
	attack = ATK;
	defense = DEF;

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

	status ob(10, 6, 4);
	ob.show();

	return;

}

