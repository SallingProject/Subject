#include<stdio.h>

#define MAX 10

// �Ӗ��̂��閼�O�ɂ��悤
// ���Ƃ���loop�Ȃ�
// ���Ƃ͈����ɍő吔��ݒ�ł���΂���������
void hoge(int *, int );

void main() {
	
	/*�@�ϐ��@*/

	int score[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;

	/*�@�����@*/

	hoge(score, i);

	return;

}


void hoge(int *data, int x) {

	
	if (x < MAX)	//����������10�����̏ꍇ
	{	
		printf("%d\n", *data);	//data�̃|�C���^�̒��g��\��
		++data;					//�|�C���^��i�߂�B
		hoge(data, x + 1);		//�ċN�Ăяo��
	}
	// ����else�����͖��ʂȂ��ق����킩��₷��
	else
	{
		return;
	}
	
}