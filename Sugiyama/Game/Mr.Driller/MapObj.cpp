#include <DxLib.h>
#include "MapObj.h"
#include "Game.h"
#include "DebugManager.h"

/*
* 初期化関数
* 変数の初期化と画像のロードを行う
*/
void MapObj::Initialize() {

	// 変数の初期化
	level = 1;
	airCount = -1;
	objectType = 0;
	objectBuffer = 0;
	airMeter = 6;
	airFlag = 0;
	actionFlag = false;
	color = GetColor(125, 125, 125);
	cameraPositionY = initCameraPosition = START_CAMERA;
	cameraPositionX = 300;
	playerMapX = 5;
	playerMapY = 25;
	mapFlag = false;
	playerX = CHAR_START_X;
	playerY = CHAR_START_Y;

	// 画像のロード
	LoadDivGraph(BLOCK_LIST, 15, 5, 3, 128, 128, blockList);
	LoadDivGraph(OBJECT_LIST, 8, 4, 2, 128, 128, objectList);

	susumu = LoadGraph(PLAYER_PIC);

	// マップの初期生成
	for (int y = 0; y < MAP_VERTICAL_NUM; y++) {	// 垂直方向

		if (y < START_BLOCK) {

			for (int x = 0; x < MAP_HORIZONTAL_NUM; x++) {

				if (x == 0 || x == 10) {
					mapData[x][y] = NO_DESTROY_OBJECT;
				}
				
				else {
					mapData[x][y] = BLANK;
				}
			}
		}
		else {
			if(mapCount <= 86)airCount++;
			
			MapCreate(y);

			if (airCount >= airMeter) {	// エアが出現したとき

				airCount = 0;	// 変数のリセット
			}
		}
	}
}

/*
* 終了処理関数
* メモリの解放を行う
*/
void MapObj::Finalize() {

	// 画像データの破棄
	for (int i = 0; i < BLOCKLIST_NUM; i++) {

		DeleteGraph(blockList[i]);
	}
	for (int i = 0; i < OBJECTLIST_NUM; i++) {

		DeleteGraph(objectList[i]);
	}
	DeleteGraph(susumu);
}

/*
* マップの生成関数
* 引数 : mapDataのｙ成分
* マップデータの生成を１列ずつ行う
*/


void MapObj::MapCreate(int y) {

	for (int x = 0; x < MAP_HORIZONTAL_NUM; x++) {		// 水平方向

		if (x == 0 || x == MAP_HORIZONTAL_NUM - 1) {

			mapData[x][y] = NO_DESTROY_OBJECT;
		}
		else if (mapCount >= 73 && mapCount <= 78) {
			mapData[x][y] = PERFECTMUSHIBA;
		}
		else if (mapCount >= 79 && mapCount <= 83) {
			mapData[x][y] = BLANK;
		}
		else if (mapCount == 84) {
			mapData[x][y] = PERFECTMUSHIBA;
		}
		else if (mapCount >= 85) {
			mapData[x][y] = AIR_CAPSULE;
		}
		else {
			mapData[x][y] = GetRand(OBJECT_TYPE_NUM) + 1;	// オブジェクトの決定
		}
	}

	if (airCount == airMeter && mapCount <= 72) {	// エアカプセルが出現するとき

		mapData[GetRand(MAP_HORIZONTAL_NUM - 3) + 1][y] = AIR_CAPSULE;
	}

	return;
}

/*
* マップの描画関数
* マップの描画を行う
*/
void MapObj::MapRender() {

	for (int x = 0; x < MAP_HORIZONTAL_NUM; x++) {		// 水平方向
		for (int y = 0; y < MAP_VERTICAL_NUM; y++) {	// 垂直方向

			switch (mapData[x][y]) {// オブジェクトの判別
			case BLANK:			// 空
			case PLAYER:		// プレイヤー
				objectType = BLANK_TYPE;
				break;
			case RED:			// 通常ブロック
			case GREEN:
			case BLUE:
			case YELLOW:
				objectBuffer = mapData[x][y];
				objectType = BLOCK_TYPE;
				break;

			case MUSHIBA:		// ×ブロック
			case CHILDMUSHIBA:
			case ADULTMUSHIBA:
			case GRANDMUSHIBA:
			case PERFECTMUSHIBA:
				objectBuffer = 0;
				objectType = OBJECT_TYPE;
				break;

			case AIR_CAPSULE:	// エアカプセル
				objectBuffer = 1;
				objectType = OBJECT_TYPE;
				break;
			case NO_DESTROY_OBJECT:	// 破壊不可オブジェクト
				objectBuffer = 2;
				objectType = OBJECT_TYPE;
				break;
			default:
				break;
			}

			switch (objectType) {
			case BLOCK_TYPE:	// 通常ブロック
				DrawRotaGraph(	// 描画
					(x * OBJECT_SIZE) + OBJECT_SIZE / 2 + cameraPositionX,
					(y * OBJECT_SIZE) + OBJECT_SIZE / 2 - cameraPositionY,
					OBJECT_DRAWSIZE, 0, blockList[objectBuffer], true);
				break;

			case OBJECT_TYPE:	// その他オブジェクト
				DrawRotaGraph(	// 描画
					(x * OBJECT_SIZE) + OBJECT_SIZE / 2 + cameraPositionX,
					(y * OBJECT_SIZE) + OBJECT_SIZE / 2 - cameraPositionY,
					OBJECT_DRAWSIZE, 0, objectList[objectBuffer], true);
				break;
			}

			DrawFormatString(
				(x * OBJECT_SIZE) + OBJECT_SIZE / 2 + cameraPositionX,
				(y * OBJECT_SIZE) + OBJECT_SIZE / 2 - cameraPositionY,
				color, "%d", mapData[x][y]);
		}
	}

	// キャラクターの描画
	DrawRotaGraph(playerX, playerY, OBJECT_DRAWSIZE_256, 0, susumu, true);
	return;
}

/*
* オブジェクトの挙動関数
* オブジェクトの落下や合体を行う
*/
void MapObj::ObjectAlgorithm() {
	
	return;
}

/*
* 画面のスクロール関数
* キャラクターのｙ座標に応じて画面をスクロールする
*/
void MapObj::ScrollScreen() {

	if (CheckHitKey(KEY_INPUT_UP) == 1) {	// ↑

		cameraPositionY -= CAMERA_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1) {	// ↓

		cameraPositionY += CAMERA_SPEED;
	}
	return;
}

/*
* マップデータの更新関数
* キャラクターのｙ座標値に対してマップ配列を更新する
*/

void MapObj::MapUpdate() {
	
	char StrBuf[128], StrBuf2[32];
	/*
	int MouseX, MouseY;
	int StringCr, BoxCr;

	// マウスを表示状態にする
	SetMouseDispFlag(TRUE);

	// 白色の値を取得
	StringCr = GetColor(255, 255, 255);

	// 黒の値を取得
	BoxCr = GetColor(0, 0, 0);


		// マウスの位置を取得
		GetMousePoint(&MouseX, &MouseY);

		// 表示する文字列を作成

			lstrcpy(StrBuf, "座標 Ｘ"); // 文字列"座標 Ｘ"をStrBufにコピー
			itoa(MouseX, StrBuf2, 10); // MouseXの値を文字列にしてStrBuf2に格納
			lstrcat(StrBuf, StrBuf2); // StrBufの内容にStrBuf2の内容を付け足す
			lstrcat(StrBuf, "　Ｙ "); // StrBufの内容に文字列"Ｙ"を付け足す
			itoa(MouseY, StrBuf2, 10); // MouseYの値を文字列にしてStrBuf2に格納
			



		// 座標文字列を描く
		DrawString(50, 50, StrBuf, StringCr);
		*/



		lstrcpy(StrBuf, "深さ "); // 文字列"座標 Ｘ"をStrBufにコピー
		itoa(mapCount, StrBuf2, 10); // MouseXの値を文字列にしてStrBuf2に格納
		lstrcat(StrBuf, StrBuf2); // StrBufの内容にStrBuf2の内容を付け足す
		lstrcat(StrBuf, " M "); // StrBufの内容に文字列"Ｙ"を付け足す
		


		DrawString(100, 100, StrBuf, GetColor(255, 255, 255));
		

	if (cameraPositionY >= initCameraPosition + OBJECT_SIZE) {	// カメラ位置が1オブジェクト分移動したとき
		mapCount++;
		for (int y = 0; y < MAP_VERTICAL_NUM; y++) {	// 垂直方向
			for (int x = 0; x < MAP_HORIZONTAL_NUM; x++) {		// 水平方向

				if (y < MAP_VERTICAL_NUM - 1) {

					mapData[x][y] = mapData[x][y + 1];	// マップデータの1つ上に格納
				}

			}

			if (y == MAP_VERTICAL_NUM - 1) {	// MapDataの最下層

				airCount++;
				MapCreate(y);



				if (airCount >= airMeter) {	// エアが出現したとき

					airCount = 0;	// 変数のリセット
				}
			}
		}

		cameraPositionY = initCameraPosition;	// カメラポジションのリセット
	}


	for (int y = 0; y < MAP_VERTICAL_NUM; y++) {	// 垂直方向
		for (int x = 0; x < MAP_HORIZONTAL_NUM; x++) {		// 水平方向			
			if (playerX >= (x * OBJECT_SIZE) + cameraPositionX && playerX < (x * OBJECT_SIZE) + cameraPositionX + OBJECT_SIZE &&
				playerY >= (y * OBJECT_SIZE) && playerY < (y * OBJECT_SIZE) + OBJECT_SIZE) {


				mapData[x][y + 20] = PLAYER;

				if (mapData[x][y + 19] == PLAYER)
				{
					mapData[x][y + 19] = BLANK;
				}
				if (mapData[x - 1][y + 20] == PLAYER) {
					mapData[x - 1][y + 20] = BLANK;
				}
				if (mapData[x + 1][y + 20] == PLAYER) {
					mapData[x + 1][y + 20] = BLANK;
				}

				if (x != playerMapX && y != playerMapY) {

					mapData[playerMapX][playerMapY] = BLANK;
					mapFlag = true;
				}
			}

			if (mapFlag == true) {

				playerMapX = x;
				playerMapY = y + 20;
				mapFlag = false;

			}
		}
	}

	
	return;
}

/*
* ブロックの破壊関数
* デバッグモードとしてクリックでブロックを破壊する
*/
void MapObj::DestroyBlock() {
	
	return;
}

/*
* 周辺確認関数
* 配列内での自身の周辺を確認する
* 引数：配列の列　配列の行
*/
void MapObj::AroundChecker(int x, int y) {

	// 構造体オブジェクトのリセット
	check.RIGHT = false;
	check.LEFT = false;
	check.UP = false;
	check.DOWN = false;

	// 周辺にオブジェクトが存在するならTRUE
	if (mapData[x + 1][y] != BLANK) check.RIGHT = true;
	if (mapData[x - 1][y] != BLANK) check.LEFT = true;
	if (mapData[x][y + 1] != BLANK) check.DOWN = true;
	if (mapData[x][y - 1] != BLANK) check.UP = true;

	return;
}

/********************************************************
* 関数名 : BlockTypeChecker
* 機能   : 周辺のオブジェクトを判定し、構造体に格納する
* 引数   :
* 返り値 :
*******************************************************/
void MapObj::BlockTypeChecker(int x, int y) {


	happy.LEFTOBJ = mapData[x - 1][y];
	happy.RIGHTOBJ = mapData[x + 1][y];
	happy.UPOBJ = mapData[x][y - 1];
	happy.DOWNOBJ = mapData[x][y + 1];
	happy.LEFTUPOBJ = mapData[x - 1][y - 1];
	happy.RIGHTUPOBJ = mapData[x + 1][y - 1];

	return;
}

/*************************************************************************************
* 関数名 : SameChecker
* 機能　 : 引数のオブジェクトの周辺に同じオブジェクトがあるかを確認し構造体に格納する
* 引数　 : MapData内の x と y
* 返り値 : 上下左右をbool型で持つ構造体
*************************************************************************************/
void MapObj::SameChecker(int x, int y) {

	// 構造体オブジェクトのリセット
	same.RIGHT = false;
	same.LEFT = false;
	same.UP = false;
	same.DOWN = false;

	// 同じオブジェクトが存在するならTRUE
	if (mapData[x][y] == mapData[x + 1][y]) {
		same.RIGHT = true;
		mapData[x + 1][y] = BLANK;
	}
	if (mapData[x][y] == mapData[x - 1][y]) {
		same.LEFT = true;
		mapData[x - 1][y] = BLANK;
	}
	if (mapData[x][y] == mapData[x][y + 1])
	{
		same.DOWN = true;
		mapData[x][y + 1] = BLANK;
	}
	if (mapData[x][y] == mapData[x][y - 1]) {
		same.UP = true;
		mapData[x][y - 1] = BLANK;
	}

}

int MapObj::AroundSameBlockAllDestroy(int type, int BlockType) {

	switch (type) {
	case DOWN:
		for (int k = 2; k < 8; k++) {
			if (BlockType == mapData[playerMapX][playerMapY + k]) {
				mapData[playerMapX][playerMapY + k] = BLANK;

			}
			else {
				break;
			}
		}
		break;
	case UP:
		for (int k = 2; k < 10; k++) {
			if (BlockType == mapData[playerMapX][playerMapY - k]) {
				mapData[playerMapX][playerMapY - k] = BLANK;
			}
			else {
				break;
			}
		}
		break;
	case RIGHT:
		for (int k = 2; k < 10; k++) {
			if (BlockType == mapData[playerMapX + k][playerMapY]) {
				mapData[playerMapX + k][playerMapY] = BLANK;

			}
			else {
				break;
			}
		}
		break;
	case LEFT:
		for (int k = 2; k < 10; k++) {
			if (BlockType == mapData[playerMapX - k][playerMapY]) {
				mapData[playerMapX - k][playerMapY] = BLANK;
			}
			else {
				break;
			}
		}
		break;

	}
	return 0;

}
/***************************************
* 関数名 : CharAlgorithm
* 機能　 : キャラクターの挙動を全て行う
* 引数　 : なし
* 返り値 : なし
***************************************/
void MapObj::CharAlgorithm() {

	
	//周辺のオブジェクトデータを取得
	BlockTypeChecker(playerMapX, playerMapY);

	downActoinFlag = false;

	if (happy.DOWNOBJ == BLANK || happy.DOWNOBJ == AIR_CAPSULE) {
		if (mapData[playerMapX - 1][playerMapY + 1] != BLANK &&
			mapData[playerMapX - 1][playerMapY + 1] != AIR_CAPSULE &&
			mapData[playerMapX - 1][playerMapY + 1] != NO_DESTROY_OBJECT) {
				playerX = i + (60 * (playerMapX - 1));
		}
		if(	mapData[playerMapX + 1][playerMapY + 1] != BLANK &&
			mapData[playerMapX + 1][playerMapY + 1] != AIR_CAPSULE &&
			mapData[playerMapX + 1][playerMapY + 1] != NO_DESTROY_OBJECT) {

			playerX = j - (60 * (9 - playerMapX));
		}
		downActoinFlag = true;
		cameraPositionY += 6;
	}
	else {
		downActoinFlag = false;
	}
	if (downActoinFlag == false) {
		// 左に移動
		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {

			if (mapData[playerMapX - 1][playerMapY] != BLANK && mapData[playerMapX - 1][playerMapY] != AIR_CAPSULE && mapData[playerMapX - 1][playerMapY] != NO_DESTROY_OBJECT) {

				if (playerX >= i + (60 * (playerMapX - 1))) {
					playerX -= CHAR_SPEED;
				}
			}
			else if (playerX >= i) {
				playerX -= CHAR_SPEED;
			}
			playerVector = LEFT;
		}


		// 右に移動
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {

			if (mapData[playerMapX + 1][playerMapY] != BLANK && mapData[playerMapX + 1][playerMapY] != AIR_CAPSULE && mapData[playerMapX + 1][playerMapY] != NO_DESTROY_OBJECT) {

				if (playerX <= j - (60 * (9 - playerMapX))) {
					playerX += CHAR_SPEED;
				}
			}
			else if (playerX <= j) {
				playerX += CHAR_SPEED;
			}
			playerVector = RIGHT;
		}


		// 下を向く
		if (CheckHitKey(KEY_INPUT_DOWN) == 1) {

			playerVector = DOWN;
		}
		if (CheckHitKey(KEY_INPUT_UP) == 1) {

			playerVector = UP;
		}

		if (mapCount >= 100) {
			ResaltFlag = 1;
		}
		// 掘る
		if (CheckHitKey(KEY_INPUT_SPACE) == 1) {

			if (actionFlag == false) {
				actionFlag = true;
				
				//キャラクターが向いている方向を掘る
				switch (playerVector) {

				case LEFT:

					switch (happy.LEFTOBJ) {

					case RED:
					case GREEN:
					case BLUE:
					case YELLOW:
						AroundSameBlockAllDestroy(LEFT, happy.LEFTOBJ);

					case PERFECTMUSHIBA:
						mapData[playerMapX - 1][playerMapY] = BLANK;
						break;

					case MUSHIBA:
						mapData[playerMapX - 1][playerMapY] = CHILDMUSHIBA;
						break;

					case CHILDMUSHIBA:
					case ADULTMUSHIBA:
					case GRANDMUSHIBA:
						mapData[playerMapX - 1][playerMapY]++;
						break;

					default:
						break;
					}
					break;

				case RIGHT:
					switch (happy.RIGHTOBJ) {

					case RED:
					case GREEN:
					case BLUE:
					case YELLOW:
						AroundSameBlockAllDestroy(RIGHT, happy.RIGHTOBJ);
						
					case PERFECTMUSHIBA:
						mapData[playerMapX + 1][playerMapY] = BLANK;
						break;

					case MUSHIBA:
						mapData[playerMapX + 1][playerMapY] = CHILDMUSHIBA;
						break;

					case CHILDMUSHIBA:
					case ADULTMUSHIBA:
					case GRANDMUSHIBA:
						mapData[playerMapX + 1][playerMapY]++;
						break;


					default:
						break;
					}
					break;

				case UP:

					switch (happy.UPOBJ) {

					case RED:
					case GREEN:
					case BLUE:
					case YELLOW:
						AroundSameBlockAllDestroy(UP, happy.UPOBJ);
						
					case PERFECTMUSHIBA:
						mapData[playerMapX][playerMapY - 1] = BLANK;
						break;

					case MUSHIBA:
						mapData[playerMapX][playerMapY - 1] = CHILDMUSHIBA;
						break;

					case CHILDMUSHIBA:
					case ADULTMUSHIBA:
					case GRANDMUSHIBA:
						mapData[playerMapX][playerMapY - 1]++;
						break;

					default:
						break;
					}
					break;

				case DOWN:

					switch (happy.DOWNOBJ) {

					case RED:
					case GREEN:
					case BLUE:
					case YELLOW:
						AroundSameBlockAllDestroy(DOWN, happy.DOWNOBJ);
					
					case PERFECTMUSHIBA:
						mapData[playerMapX][playerMapY + 1] = BLANK;
						break;

					case MUSHIBA:
						mapData[playerMapX][playerMapY + 1] = CHILDMUSHIBA;
						break;

					case CHILDMUSHIBA:
					case ADULTMUSHIBA:
					case GRANDMUSHIBA:
						mapData[playerMapX][playerMapY + 1]++;
						break;

					default:
						break;
					}
					break;
				}
			}

		}

		else {

			actionFlag = false;
		}
	}
}