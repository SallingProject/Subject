#include "Title.h"
#include "DxLib.h"
#include "Define.h"


Title::Title(ISceneChanger* changer):SceneTask(changer){

}


Title::~Title()
{
}
void Title::Init() {
	mGraphicHandle = LoadGraph(TITLE_PIC);
	mSoundPlayHandle = LoadSoundMem(TITLE_SOUND);
}

void Title::Update(){
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Menu);
	}
}

void Title::Render() {

	//DrawTitleLogo();
	//DrawTitleNamucoLogo();
	SceneTask::Render();
	DrawString(0, 0, "タイトル画面です。", GetColor(255, 255, 255));

}
void Title::Final() {
	SceneTask::Final();
}


