#include <stdio.h>

/*******************************************************************

Chara1.c�ō쐬�����\���̌^�I�u�W�F�N�g�ƍ\���̌^��
�Ԃ�l�Ƃ���֐����쐬����B
�֐��̕Ԃ�l���g���ď�������main�֐����Ńf�[�^�����ׂĂ�\�����A
����������Ă��邩�m�F������B

*******************************************************************/


/*******************************************

�\���̕ϐ���: status
�����o��    : hp       ���C�t
              attack �@�U����
              defense  �h���

*******************************************/

struct status
{

	float hp;
	float attack;
	float defense;

};


/*�\���̂̃v���g�^�C�v�錾*/
struct status chara();


void main()
{

	/*�\���̂̒�`*/
	struct status data;


	/*�֐��̎Q��*/
	data = chara();


	/*�\��*/
	printf("HP: %f\n", data.hp);
	printf("ATK: %f\n", data.attack);
	printf("DEF: %f\n", data.defense);


	return;

}

/******************************

�\���̃^�O��: chara
����        : �Ȃ�
�߂�l      : data

******************************/

struct status chara()
{

	/* �\���̂̒�` */
	struct status data;

	data.hp = 10;
	data.attack = 6;
	data.defense = 4;

	return data;

}