/*
���̖��̐����́A�֐��ɔz��̐擪�̃A�h���X�������Ƃ��ēn���A�ċN�Ăт������g���ĂЂƂÂA�h���X�����炵��
�\������̂��Ǝv���܂������A�|�C���^�ϐ��ň����錾�����ꍇ�A�ċN�Ăт��������܂������܂���ł����B
���ׂ�̂̓v���C�h�������Ă���Ȃ������̂ŁA�\����ς��܂����B
*/

#include<stdio.h>

#define MAX 10


void main() {
	
	/*�@�ϐ��@*/

	int score[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;

	/*�@�����@*/

LABEL:

	if (i == MAX - 1)
	{
		printf("%d\n", score[i]);
	}
	else
	{
		printf("%d\n", score[i]);
		i++;
		goto LABEL; // L,22�@LABEL�փW�����v
	}

	return;

}