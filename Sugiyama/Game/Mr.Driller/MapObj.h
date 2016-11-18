#ifndef _MAPOBJ_H_
#define _MAPOBJ_H_

#include "Define.h"

typedef enum Obj {
	BLANK = 0,				//��,
	RED = 1,				//�ԃu���b�N
	GREEN = 2,				//�΃u���b�N
	BLUE = 3,				//�u���b�N
	YELLOW = 4,				//���u���b�N
	MUSHIBA = 5,			//�~�u���b�N
	AIR_CAPSULE = 6,		// �G�A�J�v�Z��
	PLAYER = 9,				//�v���C���[
	CHILDMUSHIBA = 10,		//�~�u���b�N���`��
	ADULTMUSHIBA = 11,		//�~�u���b�N��O�`��
	GRANDMUSHIBA = 12,		//�~�u���b�N��l�`��
	PERFECTMUSHIBA = 13,    //�~�u���b�N�ŏI�`��
	NO_DESTROY_OBJECT = 99,	// �j��s�I�u�W�F�N�g
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
	void Initialize();				// ������
	void Finalize();				// �I������
	void MapCreate(int);			// �}�b�v�̐���
	void MapRender();				// �}�b�v�̕`��
	void ObjectAlgorithm();			// �I�u�W�F�N�g�̋���
	void ScrollScreen();			// ��ʂ̃X�N���[��
	void MapUpdate();				// �}�b�v�f�[�^�̍X�V
	void DestroyBlock();			// �u���b�N�̔j��
	void SameChecker(int, int);
	void AroundChecker(int, int);	// ���ӂ�������
	void CharAlgorithm();			// �v���C���[�̋���
	void BlockTypeChecker(int, int);//���ӂ̃I�u�W�F�N�g�̎�ނ̊m�F
	int  AroundSameBlockAllDestroy(int,int);
	int ResaltFlag;
private:
	int level;						// �X�e�[�W���x��
	int blockList[BLOCKLIST_NUM];	// �u���b�N�摜
	int objectList[OBJECTLIST_NUM];	// �I�u�W�F�N�g�摜
	int mapData[MAP_HORIZONTAL_NUM][MAP_VERTICAL_NUM];// �}�b�v���
	int objectType;					// �I�u�W�F�N�g�̎��
	int objectBuffer;				// �I�u�W�F�N�g�̎�ނ��ꎞ�I�Ɋi�[
	int color;						// �����F White (255, 255, 255)
	int error;						// �Ԃ�l
	int cameraPositionX;			// �J�����|�W�V����
	int cameraPositionY;			// �J�����|�W�V����
	int airCount;					// �G�A�̏o���܂ł̃J�E���g
	int airMeter;					// �G�A�o���̊Ԋu
	int airFlag;					// �G�A�̑��݂��i�[
	int mouseX;						// �}�E�X��X���W
	int mouseY;						// �}�E�X��Y���W
	int mouseInputData;				// �}�E�X�̓��͏�
	int susumu;                     // �摜�����p�ϐ�
	int playerX;                    // �L�����N�^�[��X���W
	int playerY;                    // �L�����N�^�[��Y���W
	int initCameraPosition;			// �����̃J�����ʒu
	int playerMapX;                 //mapData��X����
	int playerMapY;					//mapData��Y����
	bool actionFlag;				// �@���Ă�Œ�
	bool downActoinFlag = false;
	bool mapFlag;
	int blockBuffer;
	int playerVector = DOWN;
	int i = 390;
	int j = 868;
	int mapCount = 0;
	BlockDrect same;				// �㉺���E��������
	BlockDrect check;				// �㉺���E�ɉ������邩
	AroundBlock happy;
	
	

};

#endif // !_MAPOBJ_H_