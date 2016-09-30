#include <iostream>

using namespace std;

/***********************************************************

クラスSceneBaseを実装しなさい。要件は以下のものとする。
更新処理を行う関数、描画処理を行う関数、初期化を行う関数
を作成しアクセスレベルは「公開」とする。
それぞれのメンバ関数は純粋仮想関数とする。
コンソール画面は不要。

***********************************************************/


class SceneBase {

	/* アクセスレベル 公開 */
public:
	virtual void update() = 0;      //更新処理
	virtual void render() = 0;      //描画処理
	virtual void initialize() = 0;  //初期化

};


void main()
{

	return;

}