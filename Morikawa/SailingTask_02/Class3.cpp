#include <iostream>

using namespace std;

class status {
public:
	status() {
		m_life = 10; // �R���X�g���N�^
		m_attack = 5;
		m_deffence = 3;
	}
	void print() { // �\���֐�
		cout << "HP :" << m_life << endl;
		cout << "ATK:" << m_attack << endl;
		cout << "DEF:" << m_deffence << endl;
	}
private:
	int m_life;
	int m_attack;
	int m_deffence;
};

void main() {
	status player;

	player.print();

	return;
}
