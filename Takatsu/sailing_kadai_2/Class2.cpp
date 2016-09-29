#include <iostream>
using namespace std;


/***********************************************************

Class1.cppで作成したクラスにメンバ関数を追加してください。
要件は以下の通りです。
関数のアクセスレベルは「公開」にしてください。
①Class1.cppの定義したメンバ変数を表示する関数
コンソールでの出力は不要です。

***********************************************************/


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

	return;

}