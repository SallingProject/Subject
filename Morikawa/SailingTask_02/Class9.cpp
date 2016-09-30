#include <iostream> 
 
using namespace std; 
 
class SceneBase { 
public:  
	virtual void update() = 0;     // 更新処理 
	virtual void render() = 0;     // 描画処理  
	virtual void initialize() = 0; // 初期化 
}; 
 
class SceneGame : public SceneBase { 
public: 
	void update() {        // 更新処理 
		cout << "update" << endl; 
	} 
	void render() {        // 描画処理 
		cout << "render" << endl; 
	} 
	void initialize() {    // 初期化 
		cout << "initialize" << endl; 
	}  
}; 
 
void main() { 
	SceneBase* pBase; 
	SceneGame* pGame = new SceneGame; 
	 
	// アップキャストを行う 
	pBase = pGame; 
	 
	SceneGame Game; 
	 
	Game.update(); 
	Game.render(); 
	Game.initialize(); 
	 
	return; 
} 