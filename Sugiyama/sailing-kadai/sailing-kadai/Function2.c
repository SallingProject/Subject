#include<stdio.h>

int hoge();

void main() {
	
	int score = 0;

	printf("‰Šú‰»‘OF%d\n", score);

	score = hoge();

	printf("‰Šú‰»ŒãF%d\n", score);

	return;
}

int hoge() {
	
	int x = 10;

	return x;
}