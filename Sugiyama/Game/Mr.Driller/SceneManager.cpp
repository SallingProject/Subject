#include "SceneManager.h"
#include "DxLib.h"
#include "Config.h"
#include "Game.h"
#include "Title.h"
#include "Menu.h"

SceneManager::SceneManager():mNextScene(eScene_NULL) {

	mScene = (IScene*) new Game(this);
}

void SceneManager::Init() {

	mScene->Init();
}

void SceneManager::Final() {
	mScene->Final();

}

void SceneManager::Update() {

	if (mNextScene != eScene_NULL) {
		mScene->Final();
		delete mScene;

		switch (mNextScene) {
		case eScene_Menu:
			mScene = (IScene*) new Menu(this);
			break;

		case eScene_Game:
			mScene = (IScene*) new Game(this);
			break;

		case eScene_Config:
			mScene = (IScene*) new Config(this);
			break;

		case eScene_Title:
			mScene = (IScene*) new Title(this);
			break;

		case eScene_Result:
			mScene = (IScene*) new Result(this);
			break;
		}

		
		mNextScene = eScene_NULL;
		
		mScene->Init();

	}
	mScene->Update();
}
void SceneManager::Render() {
	mScene->Render();
}

void SceneManager::ChangeScene(eScene NextScene) {
	mNextScene = NextScene;
}

SceneManager::~SceneManager(){
}
