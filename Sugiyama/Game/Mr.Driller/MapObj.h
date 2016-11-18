#ifndef _MAPOBJ_H_
#define _MAPOBJ_H_

#include "Define.h"

typedef enum Obj {
	BLANK = 0,				//空白,
	RED = 1,				//赤ブロック
	GREEN = 2,				//緑ブロック
	BLUE = 3,				//青ブロック
	YELLOW = 4,				//黄ブロック
	MUSHIBA = 5,			//×ブロック
	AIR_CAPSULE = 6,		// エアカプセル
	PLAYER = 9,				//プレイヤー
	CHILDMUSHIBA = 10,		//×ブロック第二形態
	ADULTMUSHIBA = 11,		//×ブロック第三形態
	GRANDMUSHIBA = 12,		//×ブロック第四形態
	PERFECTMUSHIBA = 13,    //×ブロック最終形態
	NO_DESTROY_OBJECT = 99,	// 破壊不可オブジェクト
} Obj;

enum Vect {
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3,
	NONE = 4,
};

struct BlockDrect {
	bool LEFT;
	bool RIGHT;
	bool UP;
	bool DOWN;
};

struct AroundBlock {
	int LEFTOBJ;
	int RIGHTOBJ;
	int UPOBJ;
	int DOWNOBJ;
	int LEFTUPOBJ;
	int RIGHTUPOBJ;
};



class MapObj {
public:
	void Initialize();				// 初期化
	void Finalize();				// 終了処理
	void MapCreate(int);			// マップの生成
	void MapRender();				// マップの描画
	void ObjectAlgorithm();			// オブジェクトの挙動
	void ScrollScreen();			// 画面のスクロール
	void MapUpdate();				// マップデータの更新
	void DestroyBlock();			// ブロックの破壊
	void SameChecker(int, int);
	void AroundChecker(int, int);	// 周辺が同じか
	void CharAlgorithm();			// プレイヤーの挙動
	void BlockTypeChecker(int, int);//周辺のオブジェクトの種類の確認
	int  AroundSameBlockAllDestroy(int,int);
	int ResaltFlag;
private:
	int level;						// ステージレベル
	int blockList[BLOCKLIST_NUM];	// ブロック画像
	int objectList[OBJECTLIST_NUM];	// オブジェクト画像
	int mapData[MAP_HORIZONTAL_NUM][MAP_VERTICAL_NUM];// マップ情報
	int objectType;					// オブジェクトの種類
	int objectBuffer;				// オブジェクトの種類を一時的に格納
	int color;						// 文字色 White (255, 255, 255)
	int error;						// 返り値
	int cameraPositionX;			// カメラポジション
	int cameraPositionY;			// カメラポジション
	int airCount;					// エアの出現までのカウント
	int airMeter;					// エア出現の間隔
	int airFlag;					// エアの存在を格納
	int mouseX;						// マウスのX座標
	int mouseY;						// マウスのY座標
	int mouseInputData;				// マウスの入力状況
	int susumu;                     // 画像入れる用変数
	int playerX;                    // キャラクターのX座標
	int playerY;                    // キャラクターのY座標
	int initCameraPosition;			// 初期のカメラ位置
	int playerMapX;                 //mapDataのX成分
	int playerMapY;					//mapDataのY成分
	bool actionFlag;				// 掘ってる最中
	bool downActoinFlag = false;
	bool mapFlag;
	int blockBuffer;
	int playerVector = DOWN;
	int i = 390;
	int j = 868;
	int mapCount = 0;
	BlockDrect same;				// 上下左右が同じか
	BlockDrect check;				// 上下左右に何かあるか
	AroundBlock happy;
	
	

};

#endif // !_MAPOBJ_H_