#include<stdio.h>

int hoge();

void main() {
	
	int score = 0;

	printf("初期化前：%d\n", score);

	score = hoge();

	printf("初期化後：%d\n", score);

	return;
}

int hoge() {
	
	int x = 10;

	return x;
}