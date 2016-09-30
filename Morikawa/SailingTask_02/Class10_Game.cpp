#include "Class10_Game.h"
#include "Class10_Scene.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void Game::Start() { // �����̊J�n
	
	Game::Initialize();
	
	while (flg == 0) {
		Game::Input();
		Game::Output();
		Game::End();
	}

	return;
}

void Game::Initialize() { // �����̐ݒ�Ƃ��̑�������

	int answer;
	
	do {
		answer = rand() % 1000;
		ans[0] = answer % 10;
		ans[1] = answer % 100 / 10;
		ans[2] = answer / 100;
	} while (ans[0] == ans[1] || ans[1] == ans[2] || ans[2] == ans[0]);

	// cout << ans[0] << ans[1] << ans[2] << endl;
	// cout << answer << endl; ����m�F�p

	cnt = 0;
	hit = 0;
	blow = 0;
	number = 0;
	flg = 0;

	return;
}

void Game::Input() { // �����̓���

	int number = 0;

	cout << "�O���̐�������͂��Ă������� : ";
	cin >> number;

	// cout << number << endl; ����m�F�p

	Game::Check(number);

	return;
}

void Game::Check(int number) { // �����Ƃ̏Ƃ炵���킹

	int num[3] = { 0 };

	hit = 0;
	blow = 0;

	num[2] = number % 10;
	num[1] = number % 100 / 10;
	num[0] = number / 100;

	// cout << num[0] << num[1] << num[2] << endl; ����m�F�p

	for (int i = 0; i < 3; i++) {

		if (num[i] == ans[i]) {
			hit++;
		}
	}

	if (num[0] == ans[1]) {
		blow++;
	}
	if (num[1] == ans[2]) {
		blow++;
	}
	if (num[2] == ans[0]) {
		blow++;
	}
}

void Game::Output() { // ��ʕ\��

	cout << "HIT :" << hit << endl;
	cout << "BLOW:" << blow << endl;

	return;
}

void Game::End() { // �I������
	
	if (hit == 3) {
		cout << endl << "�����I�I" << endl;
		cout << "�𓚉񐔂�" << cnt << "��ł����I";

		flg = 1;
	}
}