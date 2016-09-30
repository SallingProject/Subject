class SceneBase {
public:
	virtual void update() = 0; // 更新処理
	virtual void drawing() = 0; // 描画処理 
	virtual void reset() = 0; // 初期化
};