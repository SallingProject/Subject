#include<stdio.h>

#define MAX 10

/* �v���g�^�C�v�錾 */
int hoge(int);


void main() {

	/*�@�ϐ��@*/
	int score[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	/*�@�����@*/
	hoge(score[0]);

	return;
}
int hoge(int x) {

	if (x == 10)
	{
		printf("%d\n", x);
	}
	else
	{
		printf("%d\n", x);
		hoge(x + 1);	//�ċN�Ăяo��
	}
	return;
}