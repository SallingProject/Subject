#include <stdio.h>

// ���P��
// ���l���e�����Ȃǂ����̂܂�܎g�킸��
// �s�ς̐��l�Ȃ�萔�Ƃ��Ă����Ă����Ɖǐ��̌���ɂȂ���܂�
#define MAX 10

void main()
{
	//int data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	// ���P��
	int data[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i;

	/*for (i = 0; i < 10; i++)
	{
		printf("%d\n", data[i]);
	}*/

	for (i = 0; i < MAX; i++)
	{
		printf("%d\n", data[i]);
	}
	return;
}