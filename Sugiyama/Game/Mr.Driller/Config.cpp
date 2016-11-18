#include"Config.h"
#include"DxLib.h"
#include"Define.h"

Config::Config(ISceneChanger* changer):SceneTask(changer){

}


Config::~Config(){
	
}

void Config::Init() {
	mGraphicHandle = LoadGraph(CONFIG_PIC);
}
void Config::Update() {
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Menu);
	}

}

void Config::Render() {
	SceneTask::Render();
	DrawString(0, 0, "İ’è‰æ–Ê‚Å‚·B", GetColor(255, 255, 255));

}

void Config::Final() {
	SceneTask::Final();
}