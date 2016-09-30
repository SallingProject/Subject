#include "Class10_Title.h"
#include "Class10_Scene.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void Title::Initialize() { // 処理の開始

	Title::Output();
	Title::Input();

	return;
}

void Title::Output() { // タイトル表示と画面説明

	cout << " N U M E R O N" << endl << endl;

	cout << " ランダムに設定された三桁の数字を当てろ" << endl;
	cout << " 同じ数字がある場合はBLOW" << endl;
	cout << " 更に同じ場所の場合はHITと表示されるぞ" << endl;
	cout << " 設定された数字に同じ数字は含まないぞ" << endl << endl;
	cout << " Press any key...";

	return;
}

void Title::Input() { // タイトルから移行

	getch();
	system("cls");

	return;
}