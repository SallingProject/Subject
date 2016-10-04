#include "SystemManager.h"
#include "IScene.h"


SystemManager::SystemManager()
{
	m_pScene = nullptr;
	m_isEnd = false;
	m_state = EState::Initialize;
	m_sceneMap.clear();
}


SystemManager::~SystemManager()
{
	if (m_pScene != nullptr) {
		delete m_pScene;
		m_pScene = nullptr;
	}

	m_sceneMap.clear();
}


void SystemManager::Initialize(IScene* scene) {
	if (m_pScene == nullptr) {
		m_pScene = scene;
	}
	
}

void SystemManager::SceneInitalize() {
	if (m_state != EState::Initialize)return;

	bool result = false;
	if (m_pScene != nullptr) {
		result = m_pScene->Initalize();
	}
	
	if (result) {
		m_state = EState::Update;
	}
	else {
		m_state = EState::Error;
		std::cout << "ƒGƒ‰[" << std::endl;
		IsEnd(true);
	}
}

void SystemManager::SceneUpdate() {
	if (m_state != EState::Update)return;

	system("cls");
	if (m_pScene != nullptr) {
		m_pScene->Update();
	}
	if (m_state == EState::Update) {
		m_state = EState::Update;
	}
}

void SystemManager::SceneChanger(std::string sceneName) {
	m_state = EState::Change;
	
	if (!FindScene(sceneName))return;
	if (m_pScene != nullptr) {
		m_sceneMap.erase(m_pScene->GetName());
		delete m_pScene;
		m_pScene = nullptr;
	}

	m_pScene = m_sceneMap[sceneName];
	
	m_state = EState::Initialize;
}

void SystemManager::AddScene(IScene* scene) {
	if (FindScene(scene->GetName()))return;

	m_sceneMap.insert(std::make_pair(scene->GetName(), scene));
}

bool SystemManager::FindScene(std::string name) {
	auto find = m_sceneMap.find(name);

	if (find == m_sceneMap.end())return false;
	
	return true;
}

void SystemManager::IsEnd(bool isEnd) {
	m_isEnd = isEnd;
	if (m_isEnd) {
		m_state = EState::End;
	}
}

bool SystemManager::IsEnd()const {
	return m_isEnd;
}