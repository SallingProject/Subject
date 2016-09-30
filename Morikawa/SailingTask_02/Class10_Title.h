#ifndef _TITLE_H_
#define _TITLE_H_

#include "Class10_Scene.h"

/**************************************
 タイトルクラス
 タイトルの表記と次の画面への遷移はここ
 **************************************/

class Title : public Scene {

public:
	void Start();

	void Output();
	void Input();
};

#endif // _TITLE_H_