#include <iostream>

using namespace std;

/***********************************************************

クラスBaseクラスを作成しなさい。要件は以下のものとする。
更新処理を行う仮想関数。公開レベルは「公開」
その関数でBaseと出力するようにし、main関数で呼び出しなさい。

***********************************************************/


class Base {

public:
	virtual void show()
	{
		//更新処理
		/* Baseの表示 */
		cout << "Base" << endl;

	}

};


void main()
{

	Base data;

	data.show();

	return;
}