#include <iostream>

using namespace std;

class status {
public:
	status(int num_01, int num_02, int num_03) {
		m_life = num_01; // コンストラクタ
		m_attack = num_02;
		m_deffence = num_03;
	}
	void print() { // 表示関数
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
	status player(10, 5, 3);

	player.print();

	return;
}