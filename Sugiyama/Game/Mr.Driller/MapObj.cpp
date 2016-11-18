#include <DxLib.h>
#include "MapObj.h"
#include "Game.h"
#include "DebugManager.h"

/*
* �������֐�
* �ϐ��̏������Ɖ摜�̃��[�h���s��
*/
void MapObj::Initialize() {

	// �ϐ��̏�����
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

	// �摜�̃��[�h
	LoadDivGraph(BLOCK_LIST, 15, 5, 3, 128, 128, blockList);
	LoadDivGraph(OBJECT_LIST, 8, 4, 2, 128, 128, objectList);

	susumu = LoadGraph(PLAYER_PIC);

	// �}�b�v�̏�������
	for (int y = 0; y < MAP_VERTICAL_NUM; y++) {	// ��������

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

			if (airCount >= airMeter) {	// �G�A���o�������Ƃ�

				airCount = 0;	// �ϐ��̃��Z�b�g
			}
		}
	}
}

/*
* �I�������֐�
* �������̉�����s��
*/
void MapObj::Finalize() {

	// �摜�f�[�^�̔j��
	for (int i = 0; i < BLOCKLIST_NUM; i++) {

		DeleteGraph(blockList[i]);
	}
	for (int i = 0; i < OBJECTLIST_NUM; i++) {

		DeleteGraph(objectList[i]);
	}
	DeleteGraph(susumu);
}

/*
* �}�b�v�̐����֐�
* ���� : mapData�̂�����
* �}�b�v�f�[�^�̐������P�񂸂s��
*/


void MapObj::MapCreate(int y) {

	for (int x = 0; x < MAP_HORIZONTAL_NUM; x++) {		// ��������

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
			mapData[x][y] = GetRand(OBJECT_TYPE_NUM) + 1;	// �I�u�W�F�N�g�̌���
		}
	}

	if (airCount == airMeter && mapCount <= 72) {	// �G�A�J�v�Z�����o������Ƃ�

		mapData[GetRand(MAP_HORIZONTAL_NUM - 3) + 1][y] = AIR_CAPSULE;
	}

	return;
}

/*
* �}�b�v�̕`��֐�
* �}�b�v�̕`����s��
*/
void MapObj::MapRender() {

	for (int x = 0; x < MAP_HORIZONTAL_NUM; x++) {		// ��������
		for (int y = 0; y < MAP_VERTICAL_NUM; y++) {	// ��������

			switch (mapData[x][y]) {// �I�u�W�F�N�g�̔���
			case BLANK:			// ��
			case PLAYER:		// �v���C���[
				objectType = BLANK_TYPE;
				break;
			case RED:			// �ʏ�u���b�N
			case GREEN:
			case BLUE:
			case YELLOW:
				objectBuffer = mapData[x][y];
				objectType = BLOCK_TYPE;
				break;

			case MUSHIBA:		// �~�u���b�N
			case CHILDMUSHIBA:
			case ADULTMUSHIBA:
			case GRANDMUSHIBA:
			case PERFECTMUSHIBA:
				objectBuffer = 0;
				objectType = OBJECT_TYPE;
				break;

			case AIR_CAPSULE:	// �G�A�J�v�Z��
				objectBuffer = 1;
				objectType = OBJECT_TYPE;
				break;
			case NO_DESTROY_OBJECT:	// �j��s�I�u�W�F�N�g
				objectBuffer = 2;
				objectType = OBJECT_TYPE;
				break;
			default:
				break;
			}

			switch (objectType) {
			case BLOCK_TYPE:	// �ʏ�u���b�N
				DrawRotaGraph(	// �`��
					(x * OBJECT_SIZE) + OBJECT_SIZE / 2 + cameraPositionX,
					(y * OBJECT_SIZE) + OBJECT_SIZE / 2 - cameraPositionY,
					OBJECT_DRAWSIZE, 0, blockList[objectBuffer], true);
				break;

			case OBJECT_TYPE:	// ���̑��I�u�W�F�N�g
				DrawRotaGraph(	// �`��
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

	// �L�����N�^�[�̕`��
	DrawRotaGraph(playerX, playerY, OBJECT_DRAWSIZE_256, 0, susumu, true);
	return;
}

/*
* �I�u�W�F�N�g�̋����֐�
* �I�u�W�F�N�g�̗����⍇�̂��s��
*/
void MapObj::ObjectAlgorithm() {
	
	return;
}

/*
* ��ʂ̃X�N���[���֐�
* �L�����N�^�[�̂����W�ɉ����ĉ�ʂ��X�N���[������
*/
void MapObj::ScrollScreen() {

	if (CheckHitKey(KEY_INPUT_UP) == 1) {	// ��

		cameraPositionY -= CAMERA_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1) {	// ��

		cameraPositionY += CAMERA_SPEED;
	}
	return;
}

/*
* �}�b�v�f�[�^�̍X�V�֐�
* �L�����N�^�[�̂����W�l�ɑ΂��ă}�b�v�z����X�V����
*/

void MapObj::MapUpdate() {
	
	char StrBuf[128], StrBuf2[32];
	/*
	int MouseX, MouseY;
	int StringCr, BoxCr;

	// �}�E�X��\����Ԃɂ���
	SetMouseDispFlag(TRUE);

	// ���F�̒l���擾
	StringCr = GetColor(255, 255, 255);

	// ���̒l���擾
	BoxCr = GetColor(0, 0, 0);


		// �}�E�X�̈ʒu���擾
		GetMousePoint(&MouseX, &MouseY);

		// �\�����镶������쐬

			lstrcpy(StrBuf, "���W �w"); // ������"���W �w"��StrBuf�ɃR�s�[
			itoa(MouseX, StrBuf2, 10); // MouseX�̒l�𕶎���ɂ���StrBuf2�Ɋi�[
			lstrcat(StrBuf, StrBuf2); // StrBuf�̓��e��StrBuf2�̓��e��t������
			lstrcat(StrBuf, "�@�x "); // StrBuf�̓��e�ɕ�����"�x"��t������
			itoa(MouseY, StrBuf2, 10); // MouseY�̒l�𕶎���ɂ���StrBuf2�Ɋi�[
			



		// ���W�������`��
		DrawString(50, 50, StrBuf, StringCr);
		*/



		lstrcpy(StrBuf, "�[�� "); // ������"���W �w"��StrBuf�ɃR�s�[
		itoa(mapCount, StrBuf2, 10); // MouseX�̒l�𕶎���ɂ���StrBuf2�Ɋi�[
		lstrcat(StrBuf, StrBuf2); // StrBuf�̓��e��StrBuf2�̓��e��t������
		lstrcat(StrBuf, " M "); // StrBuf�̓��e�ɕ�����"�x"��t������
		


		DrawString(100, 100, StrBuf, GetColor(255, 255, 255));
		

	if (cameraPositionY >= initCameraPosition + OBJECT_SIZE) {	// �J�����ʒu��1�I�u�W�F�N�g���ړ������Ƃ�
		mapCount++;
		for (int y = 0; y < MAP_VERTICAL_NUM; y++) {	// ��������
			for (int x = 0; x < MAP_HORIZONTAL_NUM; x++) {		// ��������

				if (y < MAP_VERTICAL_NUM - 1) {

					mapData[x][y] = mapData[x][y + 1];	// �}�b�v�f�[�^��1��Ɋi�[
				}

			}

			if (y == MAP_VERTICAL_NUM - 1) {	// MapData�̍ŉ��w

				airCount++;
				MapCreate(y);



				if (airCount >= airMeter) {	// �G�A���o�������Ƃ�

					airCount = 0;	// �ϐ��̃��Z�b�g
				}
			}
		}

		cameraPositionY = initCameraPosition;	// �J�����|�W�V�����̃��Z�b�g
	}


	for (int y = 0; y < MAP_VERTICAL_NUM; y++) {	// ��������
		for (int x = 0; x < MAP_HORIZONTAL_NUM; x++) {		// ��������			
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
* �u���b�N�̔j��֐�
* �f�o�b�O���[�h�Ƃ��ăN���b�N�Ńu���b�N��j�󂷂�
*/
void MapObj::DestroyBlock() {
	
	return;
}

/*
* ���ӊm�F�֐�
* �z����ł̎��g�̎��ӂ��m�F����
* �����F�z��̗�@�z��̍s
*/
void MapObj::AroundChecker(int x, int y) {

	// �\���̃I�u�W�F�N�g�̃��Z�b�g
	check.RIGHT = false;
	check.LEFT = false;
	check.UP = false;
	check.DOWN = false;

	// ���ӂɃI�u�W�F�N�g�����݂���Ȃ�TRUE
	if (mapData[x + 1][y] != BLANK) check.RIGHT = true;
	if (mapData[x - 1][y] != BLANK) check.LEFT = true;
	if (mapData[x][y + 1] != BLANK) check.DOWN = true;
	if (mapData[x][y - 1] != BLANK) check.UP = true;

	return;
}

/********************************************************
* �֐��� : BlockTypeChecker
* �@�\   : ���ӂ̃I�u�W�F�N�g�𔻒肵�A�\���̂Ɋi�[����
* ����   :
* �Ԃ�l :
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
* �֐��� : SameChecker
* �@�\�@ : �����̃I�u�W�F�N�g�̎��ӂɓ����I�u�W�F�N�g�����邩���m�F���\���̂Ɋi�[����
* �����@ : MapData���� x �� y
* �Ԃ�l : �㉺���E��bool�^�Ŏ��\����
*************************************************************************************/
void MapObj::SameChecker(int x, int y) {

	// �\���̃I�u�W�F�N�g�̃��Z�b�g
	same.RIGHT = false;
	same.LEFT = false;
	same.UP = false;
	same.DOWN = false;

	// �����I�u�W�F�N�g�����݂���Ȃ�TRUE
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
* �֐��� : CharAlgorithm
* �@�\�@ : �L�����N�^�[�̋�����S�čs��
* �����@ : �Ȃ�
* �Ԃ�l : �Ȃ�
***************************************/
void MapObj::CharAlgorithm() {

	
	//���ӂ̃I�u�W�F�N�g�f�[�^���擾
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
		// ���Ɉړ�
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


		// �E�Ɉړ�
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


		// ��������
		if (CheckHitKey(KEY_INPUT_DOWN) == 1) {

			playerVector = DOWN;
		}
		if (CheckHitKey(KEY_INPUT_UP) == 1) {

			playerVector = UP;
		}

		if (mapCount >= 100) {
			ResaltFlag = 1;
		}
		// �@��
		if (CheckHitKey(KEY_INPUT_SPACE) == 1) {

			if (actionFlag == false) {
				actionFlag = true;
				
				//�L�����N�^�[�������Ă���������@��
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