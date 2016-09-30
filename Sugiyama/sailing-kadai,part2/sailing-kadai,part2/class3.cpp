#include<iostream>
using namespace std;


void main() {

	class STATUS {
	private:
		int m_HP;
		int m_AT;
		int m_DF;
	public:
		void print_menber(int status_hp, int status_at, int status_df)
		{
			status_hp = m_HP;
			status_at = m_AT;
			status_df = m_DF;
			cout << "HP = " << status_hp << "AT = " << status_at << "DF = " << status_df << endl;
		}
	};

	STATUS status;

	status.print_menber(10, 7, 4);

	return;
}
