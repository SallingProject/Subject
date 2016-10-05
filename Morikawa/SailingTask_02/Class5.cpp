#include <iostream>

using namespace std;

class Base {
public:
	virtual void update() {
		// XVˆ—
		cout << "Base" << endl;
	}
};

void main() {
	Base data;

	data.update();

	return;
}