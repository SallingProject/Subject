#include<iostream>
using namespace std;

class BASE {
public:
	virtual void Disp()
	{
		cout << "Base" << endl;
	}
};

void main() {

	BASE base;

	base.Disp();

	return;
}