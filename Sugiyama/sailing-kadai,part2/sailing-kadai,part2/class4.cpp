#include<iostream>
using namespace std;

class STATUS {
private:
	int m_HP;
	int m_AT;
	int m_DF;
//public:
	STATUS(int, int, int);
	void Disp();
};

STATUS::STATUS(int c_HP, int c_AT, int c_DF)
{
	m_HP = c_HP;
	m_AT = c_AT;
	m_DF = c_DF;
}

void STATUS::Disp()
{
	cout << "HP: " << m_HP << endl;
	cout << "AT: " << m_AT << endl;
	cout << "DF: " << m_DF << endl;
}

void main() {


	STATUS status(10, 7, 4);

	status.Disp();


	return;
}
