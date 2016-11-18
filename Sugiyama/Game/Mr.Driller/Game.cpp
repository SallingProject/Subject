#include "DxLib.h"
#include "Game.h"
#include "Define.h"


Game::Game(ISceneChanger* changer) :SceneTask(changer) {

	mapCreateFlag = 0;

	return;
}


Game::~Game() {}

void Game::Init() {
	mSoundPlayHandle = LoadSoundMem(GAME_SOUND);
	// mGraphicHandle = LoadGraph(GAME_PIC); �w�i�̃��[�h
	map.Initialize();
}
void Game::Update() {

	
	if (map.ResaltFlag == 1) {
		mChangeScene->ChangeScene(eScene_Result);
	}

	// �}�b�v�֘A

	//map.ScrollScreen();
	map.MapUpdate();
	map.DestroyBlock();
	map.CharAlgorithm();
}
void Game::Render() {
	SceneTask::Render();
	map.MapRender();
	DrawString(0, 0, "L�L�[�łꂴ��Ɖ�ʂɐi�݂܂��B", GetColor(255, 255, 255));
}

void Game::Final() {
	SceneTask::Final();
	

}