#include<iostream>
using namespace std;



void main() {

	class STATUS {
		private:
			int m_HP;
			int m_AT;
			int m_DF;
		public:
			void m_print_menber(int status_hp, int status_at, int status_df)
			{
				m_HP = status_hp;
				m_AT = status_at;
				m_DF = status_df;
				cout << " HP = " << STATUS::m_HP << " AT = " << STATUS::m_AT << " DF = " << STATUS::m_DF << endl;
			}
	};

	STATUS status;

	status.m_print_menber(10, 7, 4);

	return;
}
