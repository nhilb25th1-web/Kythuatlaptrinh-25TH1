#include<string>
using namespace std;


struct Account {
	string lnk, usr, pwd, desc;
	friend ostream& operator << (ostream& os, Account& b) {
		os << "Account information:" << endl;
		os << "\t+ Link: " << b.lnk << endl;
		os << "\t+ User name: " << b.usr << endl;
		os << "\t+ Password: " << b.pwd << endl;
		os << "\t+ Description: " << b.desc << endl;
		return os;
	}
};
