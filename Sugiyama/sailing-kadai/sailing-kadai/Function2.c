#include<stdio.h>

int hoge();

void main() {
	
	int score = 0;

	printf("�������O�F%d\n", score);

	score = hoge();

	printf("��������F%d\n", score);

	return;
}

int hoge() {
	
	int x = 10;

	return x;
}