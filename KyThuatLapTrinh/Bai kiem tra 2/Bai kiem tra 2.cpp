#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node {
    Student data;
    Node* next;

    void Create(Student s) {
        data = s;
        next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    void Show() {
        if (head == NULL) {
            cout << "No student available" << endl;
            return;
        }
        Node* item = head;
        while (item != NULL) {
            cout << "ID: " << item->data.id << endl;
            cout << "Name: " << item->data.name << endl;
            cout << "Age: " << item->data.age << endl;
            cout << "Address: " << item->data.address << endl;
            cout << "----------------------" << endl;
            item = item->next;
        }
    }
    void AddFirst(Node* p) {
        p->next = head;
        head = p;
    }
    bool Remove(int removeId) {
        if (head == NULL) {
            cout << "No student available" << endl;
            return false;
        }

        Node* item = head;
        if (item->data.id == removeId) {
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
    Student* Find(int findId) {
        if (head == NULL) {
            cout << "No student available" << endl;
            return NULL;
        }

        Node* item = head;
        while (item != NULL) {
            if (item->data.id == findId) {
                return &(item->data);
            }
            item = item->next;
        }
        return NULL;
    }
    void LoadFromFile(const char* filename) {
        ifstream f(filename, ios::binary);
        if (!f) {
            cout << "Cannot open file!" << endl;
            return;
        }
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        Student s;
        while (f.read((char*)&s, sizeof(student))) {
            Node* p = new Node;
            p->Create(s);
            AddFirst(p);
        }

        f.close();
    }
};
int main()
{
    LinkedList list = {NULL};
	do {
		system("cls");
		cout << "____STUDENT MANAGEMENT_____" << endl;
		cout << "1. View student list" << endl;
		cout << "2. Add a student" << endl;
		cout << "3. Delete a student" << endl;
		cout << "4. Find student to by id " << endl;
		cout << "5. Load data from flie " << endl;
		cout << "0. Exit" << endl;
		cout << "_________________________" << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		switch (choice) {
        case 1: {
            students.Show();
            break;
        }

        case 2: {
            student s;
            cin >> s;
            Node* newNode = new Node;
            newNode->Create(s);
            students.AddFirst(newNode);
            break;
        }

        case 3: {
            int removeId;
            cout << "Enter student's id to remove: ";
            cin >> removeId;

            bool res = students.Remove(removeId);
            if (res)
                cout << "Remove student successfully" << endl;
            else
                cout << "Invalid student id" << endl;
            break;
        }
        case 4: {
            string name;
            cout << "Enter student's name to find: ";
            cin.ignore();
            getline(cin, name);
            Student* res = students.Find(name);
            if (res != NULL) {
                cout << *res;
            }
            else {
                cout << "No student with name: " << name << endl;
            }
            break;
        }
        case 5: {
            readFile(students, "students.dat");
            cout << "Data loaded successfully!" << endl;
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

    } while (true);
}