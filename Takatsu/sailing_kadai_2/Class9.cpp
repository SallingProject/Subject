#include <iostream>

using namespace std;

/***********************************************************************

Class7.cppで作成した、SceneBaseを継承しクラス
SceneGameを実装しなさい。要件は以下のものとする。
更新処理を行う関数、描画処理を行う関数、初期化を行う関数
を作成しアクセスレベルは「公開」とする。
それぞれのメンバ関数をオーバーライドする
メインには基底クラスのオブジェクトを作り、
派生クラスを基底クラスにアップキャストする
更新処理関数はupdate、描画処理はrender、
初期化initializeと出力しなさい。
初期化関数は必ず1度しか呼ばれないものとする。
コンソール画面はページの都合上割愛。

***********************************************************************/


class SceneBase {

	/* アクセスレベル 公開 */
public:
	virtual void update() = 0;      //更新処理
	virtual void render() = 0;      //描画処理
	virtual void initialize() = 0;  //初期化

};


class SceneGame :public SceneBase {

public:
	void update()
	{

		/* updateと表示 */

		cout << "update" << endl;

	}

	void render()
	{

		/* renderと表示 */

		cout << "render" << endl;

	}

	void initialize()
	{

		/* initializeと表示 */

		cout << "initialize" << endl;

	}

};


void main()
{
	/* 基底クラスのオブジェクト */
	SceneBase *pBase = new SceneGame;


	pBase->update();
	pBase->render();
	pBase->initialize();

	return;

}