#include<string>
using namespace std;


struct Account {
	int id;
	string lnk[50], usr[50], pwd[50], desc[50];
	friend ostream& operator << (ostream& os, Account& b) {
		os << "Account information:" << endl;
		os << "\t+ Id: " << b.id << endl;
		os << "\t+ Link: " << b.lnk << endl;
		os << "\t+ User name: " << b.usr << endl;
		os << "\t+ Password: " << b.pwd << endl;
		os << "\t+ Description: " << b.desc << endl;
		return os;
	}
	friend istream& operator >> (istream& in, Account& b) {
		cout << "Account information:" << endl;
		cout << "\t+ Id: ";
		in >> b.id;
		cout << "\t+ Link: ";
		in.ignore();
		getline(in, b.lnk[50]);
		cout << "\t+ User name: ";
		in.ignore();
		getline(in, b.usr[50]);
		cout << "\t+ Password: ";
		getline(in, b.pwd[50]);
		cout << "\t+ Description: ";
		getline(in, b.desc[50]);
		return in;
	}
};
