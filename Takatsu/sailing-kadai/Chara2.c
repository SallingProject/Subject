#include <stdio.h>

/**************************************************************

Chara1.c�ō쐬�����\���̌^�I�u�W�F�N�g�ƍ\���̌^��
�����Ƃ���֐����쐬����B�֐������ō\���̂̊e��f�[�^��
��������main�֐����Ńf�[�^�����ׂĂ�\�����A
����������Ă��邩�m�F������B


**************************************************************/


/*******************************************

�\���̕ϐ���: status
�����o��    : hp       ���C�t
              attack �@�U����
              defense  �h���

*******************************************/

typedef struct
{

	float hp;
	float attack;
	float defense;

}status;


/*�\���̂̃v���g�^�C�v�錾*/
void hoge(status *data);


int main()
{

	/*�\���̂̒�`*/
	 status data;


	 /*�֐��̎Q��*/
	 hoge(&data);

	 /*�\��*/
	 printf("HP: %f\n", data.hp);
	 printf("ATK: %f\n", data.attack);
	 printf("DEF: %f\n", data.defense);

	return 0;

}

/******************************

�\���̃^�O��: hoge
����        : data

******************************/

void  hoge(status *data)
{

	data->hp = 10;
	data->attack = 6;
	data->defense = 4;



	return;

}