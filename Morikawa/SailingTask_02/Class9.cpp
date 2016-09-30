#include <iostream>

using namespace std;

class SceneBase {
public:
	virtual void update() = 0;     // 更新処理
	virtual void render() = 0;     // 描画処理 
	virtual void initialize() = 0; // 初期化
};

class SceneGame : public SceneBase {
public:
	virtual void update() {        // 更新処理
		cout << "update" << endl;
	}
	virtual void render() {        // 描画処理
		cout << "render" << endl;
	}
	virtual void initialize() {    // 初期化
		cout << "initialize" << endl;
	}
};

/* 動作確認用
void main() {
	SceneGame test;

	test.update();

	return;
} */