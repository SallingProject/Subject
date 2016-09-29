#include <iostream>

using namespace std;

class Base {
public:
	virtual void base() {
		// 更新処理
		cout << "Base" << endl;
	}
};

class Derivation : public Base {
public:
	virtual void derivation() {
		// 更新処理
		cout << "Derivation" << endl;
	}
};

void main() {
	// Base data_01; 挙動理解用
	Derivation data_02;

	// data_01.base(); 挙動理解用
	data_02.derivation();

	return;
}