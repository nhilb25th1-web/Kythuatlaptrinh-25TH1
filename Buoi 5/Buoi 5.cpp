#include <iostream>
#include<string>
using namespace std;

struct Author {
	int id;
	string name;
	friend istream& operator>>(istream& in, Author& a) {
		cout << "Author information: " << endl;
		cout << "\t+ Id: ";
		in >> a.id;
		cout << "\t+ Name: ";
		in.ignore();
		getline(in, a.name);
		return in;
	}
};

struct Book {
	int id;
	string name;
	Author author;
	friend ostream& operator << (ostream& os, Book& b) {
		os << "Book information:" << endl;
		os << "\t+ Id: " << b.id << endl;
		os << "\t+ Name: " << b.name << endl;
		os << "\t+ Author name: " << b.author.name << endl;
		return os;
	}
	friend istream& operator >> (istream& in, Book& b) {
		cout << "Book information:" << endl;
		cout << "\t+ Id: ";
		cin >> b.id;
		cout << "\t+ Name: ";
		in.ignore();
		getline(in, b.name);
		return in;
	}
};

struct Node {
	Book data;
	Node* next;
	void Create(Book b) {
		data = b;
		next = nullptr;
	}
};


struct LinkedList {
    Node* head;
	void Show() {
		if (head == NULL) {
			cout << "No book available" << endl;
			return;
		}
		Node* item = head;
		while (item != NULL) {
			cout << item->data;
			item = item->next;
		}
	}
	void AddFirst(Node* p) {
		p->next = head;
		head = p;
	}
	bool Remove(int removeId) {
		if (head == NULL) {
			cout << "No book available" << endl;
			return true;
		}
		Node* item = head;
		if (item->data.id == removeId) { //Xoa dau danh sach
			head = item->next;
			delete item;
			return true;
		}
		while (item->next != NULL) {
			if (item->next->data.id == removeId) {
				Node* temp = item->next;
				item->next = item->next->next;
				delete temp;
				return true;
			}
			item = item->next;
		}
		return false;
	}
	bool Update(int updateId) {
		if (head == NULL) {
			cout << "No book available" << endl;
			return false;
		}
		Node* item = head;

		while (item != NULL) {
			if (item->data.id == updateId) {
				cin >> item->data;
				return true;
			}
			item = item->next;
		}
		return false;
	}
};


int main()
{
    LinkedList books = { NULL };
	do {
		system("cls");
		cout << "_______BOOK MANAGEMENT_______" << endl;
		cout << "1. Show all books" << endl;
		cout << "2. Add a book" << endl;
		cout << "3. Delete a book" << endl;
		cout << "4. Update a book" << endl;
		cout << "5. Find book" << endl;
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
			books.Show();
			break;
		}
		case 2: {
			Book b;
			cin >> b;
			Node* newNode = new Node;
			newNode->Create(b);
			books.AddFirst(newNode);
			break;
		}
		case 3: {
			int removeId;
			cout << "Enter book's id to remove: ";
			cin >> removeId;
			bool res = books.Remove(removeId);
			if (res)
				cout << "Remove book successfully" << endl;
			else
				cout << "Invalid book id" << endl;
			break;
		}
		case 4: {
			int updateId;
			cout << "Enter book's id to update: ";
			cin >> updateId;
			bool res = books.Update(updateId);
			if (res)
				cout << "Update book successfuly" << endl;
			else
				cout << "Invalid book id" << endl;
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			break;
		}
		case 7: {
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

