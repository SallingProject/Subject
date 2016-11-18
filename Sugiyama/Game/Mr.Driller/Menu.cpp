#include "Menu.h"
#include "DxLib.h"
#include "Define.h"

Menu::Menu(ISceneChanger* changer):SceneTask(changer){
}


Menu::~Menu()
{
}
void Menu::Init() {
	mGraphicHandle = LoadGraph(MENU_PIC);    //画像のロード
	mSoundPlayHandle = LoadSoundMem(MENU_SOUND);
}

//更新
void Menu::Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
		mChangeScene->ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) {//Cキーが押されていたら
		mChangeScene->ChangeScene(eScene_Config);//シーンを設定画面に変更
	}
	if (CheckHitKey(KEY_INPUT_A) != 0) {
		mChangeScene->ChangeScene(eScene_Title);
	}
}

//描画
void Menu::Render() {
	SceneTask::Render();//親クラスの描画メソッドを呼ぶ
	DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
	DrawString(0, 40, "Cキーを押すと　設定画面に進みます。", GetColor(255, 255, 255));
	DrawString(0, 60, "Aキーを押すと　タイトルに進みます。", GetColor(255, 255, 255));
}

void Menu::Final() {
	SceneTask::Final();
}