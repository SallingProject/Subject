#include<iostream>
using namespace std;

void main() {

	class STATUS {
	public:
		int HP;
		int AT;
		int DF;
		void print_menber(int status_hp, int status_at, int status_df)
		{
			HP = status_hp;
			AT = status_at;
			DF = status_df;
			cout << " HP = " << STATUS::HP << " AT = " << STATUS::AT << " DF = " << STATUS::DF << endl;
		}
	};

	STATUS status;

	status.print_menber(10, 7, 4);

	return;
}
