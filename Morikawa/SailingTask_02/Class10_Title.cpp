#include "Class10_Title.h"
#include "Class10_Scene.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void Title::Initialize() { // �����̊J�n

	Title::Output();
	Title::Input();

	return;
}

void Title::Output() { // �^�C�g���\���Ɖ�ʐ���

	cout << " N U M E R O N" << endl << endl;

	cout << " �����_���ɐݒ肳�ꂽ�O���̐����𓖂Ă�" << endl;
	cout << " ��������������ꍇ��BLOW" << endl;
	cout << " �X�ɓ����ꏊ�̏ꍇ��HIT�ƕ\������邼" << endl;
	cout << " �ݒ肳�ꂽ�����ɓ��������͊܂܂Ȃ���" << endl << endl;
	cout << " Press any key...";

	return;
}

void Title::Input() { // �^�C�g������ڍs

	getch();
	system("cls");

	return;
}