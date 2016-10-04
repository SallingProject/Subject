#include "SceneGame.h"
#include "SceneTitle.h"
#include <algorithm>
#include <random>
#include <conio.h>
namespace {
	std::string kStringNull = "null";
	std::string kExitKeyword = "exit";
	std::string kTitleKeyword = "title";
	const int kRange = 3;
	const int kRandamMin = 0;
	const int kRandamMax = 9;
}
SceneGame::SceneGame(SystemManager* manager) :
	IScene("Game", manager)
{
}


SceneGame::~SceneGame()
{
}


bool SceneGame::Initalize() {
	m_nextScene = "Title";
	GetManager()->AddScene(new SceneTitle(GetManager()));

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dice(kRandamMin, kRandamMax);

	std::vector<int> logList;
	int loop = 0;
	while (loop < kRange) {

		bool retry = false;
		const int value = dice(mt);
		
		for (auto index : logList) {
			if (index == value)
				retry = true;
		}

		if (retry)continue;

		logList.push_back(value);
		m_answer.push_back(value);
		loop += 1;
	}
	
	return true;
}


void SceneGame::Update() {
	std::cout << "Please enter the three numbers" << std::endl;
	std::cout << "commmand :" << kExitKeyword << " or " << kTitleKeyword << std::endl;
	std::string input = kStringNull;
	std::cin >> input;

	if (input == kExitKeyword) {
		GetManager()->IsEnd(true);
		return;
	}
	else if (input == kTitleKeyword) {
		GetManager()->SceneChanger(m_nextScene);
		return;
	}

	std::string error = CheckInputStrings(input);
	if (error != kStringNull) {
		std::cout << "Error：" << error << std::endl;
		getch();
		return;
	}

	bool isClear = false;
	int hit = 0;
	int i = 0;
	for (auto index : input) {
		int value = std::atoi(&index);
		if (m_answer[i] == value) {
			hit += 1;
		}
		i += 1;
	}
	
	if (hit == kRange) {
		isClear = true;
	}
	else {
		std::cout << "HIT :" << hit << std::endl;
	}


	if (isClear) {
		std::cout << "Clear!" << std::endl;
		getch();
		GetManager()->SceneChanger(m_nextScene);
	}
	getch();
}

std::string SceneGame::CheckInputStrings(std::string input) {

	std::string errorCode = kStringNull;
	if (input.size() < kRange || input.size() >kRange) {
		char buffer[256];
		sprintf(buffer, "%d", kRange);
		std::string num = buffer;
		errorCode = num +"個入力しろバーカ";
	}
	else if (!std::all_of(input.cbegin(), input.cend(), isdigit)) {
		errorCode = "数字を入力しろバーカ";
	}

	return errorCode;
}