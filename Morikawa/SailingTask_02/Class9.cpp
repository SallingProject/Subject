#include <iostream> 
 
using namespace std; 
 
class SceneBase { 
public:  
	virtual void update() = 0;     // �X�V���� 
	virtual void render() = 0;     // �`�揈��  
	virtual void initialize() = 0; // ������ 
}; 
 
class SceneGame : public SceneBase { 
public: 
	void update() {        // �X�V���� 
		cout << "update" << endl; 
	} 
	void render() {        // �`�揈�� 
		cout << "render" << endl; 
	} 
	void initialize() {    // ������ 
		cout << "initialize" << endl; 
	}  
}; 
 
void main() { 
	SceneBase* pBase; 
	SceneGame* pGame = new SceneGame; 
	 
	// �A�b�v�L���X�g���s�� 
	pBase = pGame; 
	 
	SceneGame Game; 
	 
	Game.update(); 
	Game.render(); 
	Game.initialize(); 
	 
	return; 
} 