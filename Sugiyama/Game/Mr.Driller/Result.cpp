#include "Result.h"
#include "DXlib.h"
#include "Define.h"

Result::Result(ISceneChanger* changer) :SceneTask(changer){
	
}


Result::~Result(){

}

void Result::Init() {
	mGraphicHandle = 0;
	mSoundPlayHandle = LoadSoundMem(RESULT_SOUND);
}

void Result::Final() {
	SceneTask::Final();
}

void Result::Render() {
	SceneTask::Render();
	DrawString(0, 20, "スペースキーを押すとメニュー画面に進みます。", GetColor(255, 255, 255));
}

void Result::Update() {

	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Menu);
	}
}
