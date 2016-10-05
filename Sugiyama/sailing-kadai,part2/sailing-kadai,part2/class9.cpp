#include<iostream>
using namespace std;

class SceneBase {

public:
	virtual void Update() {
		cout << "sss" << endl;
	}

	virtual void DrawScreen() = 0;
	virtual void InitGame() = 0;
};

class SceneGame : public SceneBase {
public:
	void Update() override {
		//SceneBase::Update();
		cout << "update" << endl;
	}
	void SceneBase::DrawScreen() override{
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