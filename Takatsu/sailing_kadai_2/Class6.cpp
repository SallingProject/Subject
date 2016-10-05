#include <iostream>

using namespace std;

/**************************************************************

Class5.cppで作成したBaseクラスを継承し、
Derivationクラスを作成しなさい。そのときBaseクラスの
更新処理関数をオーバーライドしてDerivationと出力するようにし、
main関数で呼び出しなさい。

**************************************************************/


class Base {

public:
	virtual void show()
	{
		//更新処理
		/* Baseの表示 */
		cout << "Base" << endl;

	}

};


class Derivation : public Base {

public:
	void show()
	{

		/* Derivationと出力 */
		cout << "Derivation" << endl;

	}

};

void main()
{

	Derivation data;

	data.show();

	return;
}