#include<iostream>
using namespace std;

class SceneBase {

public:
	virtual void Update() = 0;
	virtual void DrawScreen() = 0;
	virtual void InitGame() = 0;
};

class SceneGame : public SceneBase {
public:
	void SceneBase::Update(){
		cout << "update" << endl;
	}
	void SceneBase::DrawScreen(){
		cout << "render" << endl;
	}
	void SceneBase::InitGame(){
		cout << "initalize" << endl;
	}
};

void main() {
	
	SceneBase* pBase = new SceneGame;
	

	pBase->Update();
	pBase->DrawScreen();
	pBase->InitGame();

	return;
}