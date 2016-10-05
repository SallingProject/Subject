#include "SceneTitle.h"
#include "SceneGame.h"

namespace {
	const std::string kStartKeyWord = "start";
	const std::string kExitKeyWord = "exit";
	const std::string kStringNull = "null";
}

SceneTitle::SceneTitle(SystemManager* manager):
	IScene("Title",manager)
{
}


SceneTitle::~SceneTitle()
{
}


bool SceneTitle::Initalize() {

	m_nextScene = "Game";
	GetManager()->AddScene(new SceneGame(GetManager()));
	
	return true;
}


void SceneTitle::Update() {

	std::cout << "Numeron" << std::endl;
	std::cout << "Pleace input command " << std::endl;
	std::cout << "command : start or exit" << std::endl;
	std::string input = kStringNull;
	std::cin >> input;

	if (input == kStartKeyWord) {
		GetManager()->SceneChanger(m_nextScene);
	}
	else if (input == kExitKeyWord) {
		GetManager()->IsEnd(true);
	}
}
