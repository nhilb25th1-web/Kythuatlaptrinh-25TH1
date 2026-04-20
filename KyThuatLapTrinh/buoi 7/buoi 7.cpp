#include <iostream>
#include "Account.h"
#include "LinkedList.h"
#include "string"
using namespace std;

int main()
{
	LinkedList<Account> accounts = { NULL };
	do {
		system("cls");
		cout << "_______ACCOUNT MANAGEMENT_______" << endl;
		cout << "1. Show all account" << endl;
		cout << "2. Add a account" << endl;
		cout << "3. Delete a account" << endl;
		cout << "4. Update a account" << endl;
		cout << "5. Find account" << endl;
		cout << "6. Expore to file" << endl;
		cout << "7. Import to file" << endl;
		cout << "0. Exit" << endl;
		cout << "_______________________________" << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			accounts.Show();
			break;
		}
		case 2: {
			Account a;
			cin >> a;
			accounts.Add(a);
			break;
		}
		case 3: {
			int removeId;
			cout << "Enter account Id to remove: ";
			cin >> removeId;
			bool res = accounts.Remove(removeId);
			if (res)
				cout << " Remove account with id: " << removeId << endl;
			else
				cout << "Not found acccount id: " << removeId << endl;
			break;
		}
		case 4: {
			int updateId;
			cout << "Enter account Id to update: ";
			cin >> updateId;
			bool res = accounts.Update(updateId);
			if (res)
				cout << " Update account with id: " << updateId << endl;
			else
				cout << "Not found acccount id: " << updateId << endl;
			break;
		}
		case 5: {
			string userName;
			cout << "Enter account name: ";
			cin.ignore();
			getline(cin, userName);
			accounts.Find(userName);
			break;
		}
		case 6: {
			accounts.Export("25TH1.dla");
			cout << "Export successfully" << endl;
			break;
		}
		case 7: {
			accounts.Import("25TH1.dla");
			cout << "Import successfully" << endl;
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			cout << "Invalid choice, try again" << endl;
			break;
		}
		}
		system("pause");
		cout << "Press any key to continue...";



	} while (true);
}



