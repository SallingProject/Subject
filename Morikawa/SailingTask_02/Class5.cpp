#include <iostream>

using namespace std;

class Base {
public:
	virtual void update() {
		// �X�V����
		cout << "Base" << endl;
	}
};

void main() {
	Base data;

	data.update();

	return;
}