#ifndef _SCENE_H_
#define _SCENE_H_

/************************************
 全てのシーンの継承元となる抽象クラス
 ************************************/

class Scene {

public:
	virtual void Initialize() = 0; // 初期化処理
	virtual void Input() = 0;      // 入力処理
	virtual void Output() = 0;     // 出力処理
};

#endif // _SCENE_H_