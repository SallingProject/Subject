#include<stdio.h>

/* �v���g�^�C�v�錾 */
void hoge(int*);

void main() {

	/* �@�ϐ��@*/
	int score = 0;

	/*�@�����@*/
	printf("�������O�F%d\n", score);

	hoge(&score);	//�Q�Ɠn��

	printf("��������F%d\n", score);

	return;
}
void hoge(int* x) {

	*x = 10;

	return;
}
