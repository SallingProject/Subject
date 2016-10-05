#include<iostream>
using namespace std;

class BASE {

	public:
		virtual void Update()
		{
			cout << "Base" << endl;

		}
};

class DERIVATION : public BASE{

	public:
		virtual void Update()
		{
			cout << "Derivation" << endl;
		}

};

void main() {

	DERIVATION Derivation;

	Derivation.Update();

	return;
}