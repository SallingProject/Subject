#include<stdio.h>


// ���P�O
//void main(){
//
//	/* �ϐ��錾 */
//	int score[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i;  
//
//	/* ���� */
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", score[i]);
//	}
//
//	return;
//}

// ���P��
// �z��̍ő吔�⃋�[�v�̉񐔂Ȃǂ͒��ڐ��l���e�������g���̂ł͂Ȃ�
// �萔���`���Ĉ������ق����R�[�h�̉ǐ����������( �M�[�L)�m
#define MAX 10
void main() {
	
	/* �ϐ��錾 */
	int score[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	/* ���� */
	for (int i = 0; i < MAX; ++i) 
	{
		printf("%d\n", score[i]);
	}

	return;
}