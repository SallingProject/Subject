#include <iostream>

using namespace std;

class Base {
public:
	virtual void base() {
		// �X�V����
		cout << "Base" << endl;
	}
};

class Derivation : public Base {
public:
	virtual void derivation() {
		// �X�V����
		cout << "Derivation" << endl;
	}
};

void main() {
	// Base data_01; ��������p
	Derivation data_02;

	// data_01.base(); ��������p
	data_02.derivation();

	return;
}