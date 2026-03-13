#include<iostream>
#include<vector>
using namespace std;
struct Person {
	int id;
	string name;
	int age;
	string address;
};
void ViewPersonList(vector<Person> p) {
	if (p.size() == 0)
		cout << "An empty list" << endl;
	else {
		for (int i = 0; i < p.size(); i++) {
			cout << "Person " << (i + 1) << endl;
			cout << "\t+ Id: " << p[i].id << endl;
			cout << "\t+ Name: " << p[i].name << endl;
			cout << "\t+ Age: " << p[i].age << endl;
			cout << "\t+ Address: " << p[i].address << endl;
		}
	}
}
int main() {
	vector<Person> list;
	do {
		system("cls");
		cout << "___ HUMAN RESOURCE______" << endl;
		cout << "1. View person list" << endl;
		cout << "2. Add a person" << endl;
		cout << "3. Remove a person" << endl;
		cout << "4. Find a person" << endl;
		cout << "5. Exporrt to file" << endl;
		cout << "6. Import from file" << endl;
		cout << "0. Exit" << endl;
		cout << "_________________________" << endl;
		cout << "Your command: ";
		int cmd;
		cin >> cmd;
		switch (cmd)
		{
		case 1: {
			ViewPersonList(list);
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			break;
		}
		case 0: {
			return 0;
		}
		default:
			cout << "Your command isn't found. Try again..." << endl;
			break;
		}
		cout << "Press Enter to continue...";
		cin.ignore();
		cin.get();
	} while (true);
	return 0;
}