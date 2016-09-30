#ifndef _GAME_H_
#define _GAME_H_

#include "Class10_Scene.h"

/**************************************
 �Q�[���N���X
 �v���C���[���s���Q�[���{�̂͂���ōs��
 **************************************/

class Game : public Scene {

public:
	void Start();

	void Initialize();
	void Input();
	void Output();

	void Check(int number);
	void End();

private:
	int ans[3];
	int cnt;
	int hit;
	int blow;
	int number;
	int flg;
};

#endif // _GAME_H_