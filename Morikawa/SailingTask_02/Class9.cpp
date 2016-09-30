#include <iostream>

using namespace std;

class SceneBase {
public:
	virtual void update() = 0;     // �X�V����
	virtual void render() = 0;     // �`�揈�� 
	virtual void initialize() = 0; // ������
};

class SceneGame : public SceneBase {
public:
	virtual void update() {        // �X�V����
		cout << "update" << endl;
	}
	virtual void render() {        // �`�揈��
		cout << "render" << endl;
	}
	virtual void initialize() {    // ������
		cout << "initialize" << endl;
	}
};

/* ����m�F�p
void main() {
	SceneGame test;

	test.update();

	return;
} */