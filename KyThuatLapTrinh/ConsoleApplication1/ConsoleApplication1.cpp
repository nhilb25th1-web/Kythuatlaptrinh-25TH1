#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Vehicle{
    int id;
    char type[30];
    string branch;
    double price;
    friend ostream& operator<<(ostream& os, const Vehicle& v) {
        os << "\t+ Id: " << v.id << endl;
        os << "\t+ Type: "  << v.type << endl;
        os << "\t+ Branch: " << v.branch << endl;
        os << "\t+ Price: " << v.price << endl;
        return os;
    }
    friend istream& operator>>(istream& in, Vehicle& v) {
        cout << "Input vehicle information: " << endl;
        cout << "\t+ Id: ";
        in >> v.id;
        in.ignore();
        cout << "\t+ Type: ";
        in.getline(v.type, 30);
        cout << "\t+ Branch: ";
        getline(in, v.branch);
        cout << "\t+ Price: ";
        in >> v.price;
        return in;
    }
};

struct Node {
    Vehicle data;
    Node* next;
    Node(Vehicle v) : data(v), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    void show() {
        if (head == NULL) {
            cout << "Emty list" << endl;
            return;
        }
        Node* item = head;
        while (item != NULL) {
            cout << item->data;
            item = item->next;
        }
    }
    void Add(Vehicle v) {
        Node* newNode = new Node(v);
        newNode->next = head;
        head = newNode;
    }
    Vehicle* Find(string branchName) {
        if(head == NULL) {
            cout << "No vehicle available" << endl;
            return NULL;
        }
        Node* item = head;
        while(item != NULL) {
            if(item->data.branch.find(branchName) != std::string::npos) {
                return& (item->data);
            }
            item = item->next;
        }
        return NULL;
    } 
    bool Remove(int removeId) {
        if(head == NULL) return false;
        if(head->data.id == removeId) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* item = head;
        while(item->next != NULL) {
            if(item->next->data.id == removeId) {
                Node* temp = item->next;
                item->next = temp->next;
                delete temp;
                return true;
            }
            item = item->next;
        }
        return false;
    }
    void SaveFile(string filename) {
        ofstream out(filename);
        Node* item = head;
        while(item != NULL) {
            out << item->data.id << endl;
            out << item->data.type << endl;
            out << item->data.branch << endl;
            out << item->data.price << endl;
            item = item->next;
        }
        out.close();
    }
    bool Update(int updateId) {
        if(head == NULL) {
            cout << "No vehicle available" << endl;
            return false;
        }
        Node* item = head;
        while(item != NULL) {
            if(item->data.id == updateId) {
                cin >> item->data;
                return true;
            }
            item = item->next;
        }
        return false;
    }
    void ReadFile(string filename) {
        ifstream in(filename);
        if(!in) {
            cout << "Cannot open file!"<< endl;
            return;
        }
        head = NULL;
        Vehicle v;
        while(in >> v.id) {
            in.ignore();
            in.getline(v.type, 30);
            getline(in, v.branch);
            in >> v.price;
            in.ignore();
            Add(v);
        }
        in.close();
    }
    
    void Statistics() {
        int toyota = 0, yamaha = 0;
        Node* item = head;
        while(item != NULL) {
            if(item->data.branch == "Toyota") toyota++;
            if(item->data.branch == "Yamaha") yamaha++;
            item = item->next;
        }

        cout << "Toyota: " << toyota << endl;
        cout << "Yamaha: " << yamaha << endl;
    }
};

int main()
{
    LinkedList list = { NULL };

    do{
        system("cls");

        cout << "--------VEHICLE MANAGEMENT--------" << endl;
        cout << "1.View vehicle list" << endl;
        cout << "2.Add a vehicle" << endl;
        cout << "3.Find a vehicle" << endl;
        cout << "4.Delete a vehicle by id" << endl;
        cout << "5.Save to file" << endl;
        cout << "6.Update vehicle" << endl;
        cout << "7.Read to file" << endl;
        cout << "8.Vehicle statistics by branch" << endl;
        cout << "0.Exit" << endl;
        cout << "_____________________" << endl;
        cout << "Your command: ";
        int cmd;
        cin >> cmd;
        switch(cmd) {
        case 1: {
            list.show();
            break;
        }
        case 2 : {
            Vehicle v;
            cin >> v;
            list.Add(v);
            cout << "Add a vehicle successfully" << endl;
            break;
        }

        case 3: {
            string branchName;
            cout << "Enter branch's to find: " ;
            cin.ignore();
            getline(cin, branchName);
            Vehicle* res = list.Find(branchName);
            if(res != NULL) {
                cout << *res << endl;
            }
            else {
                cout << "No vehicle with branch: " << branchName << endl;
            }
            break;
        }

        case 4: {
            int removeId;
            cout << "Enter vehicle's ID to remove: " ;
            cin >> removeId;
            bool res = list.Remove(removeId);
            if(res)
                cout << "Remove vehicle successfully" << endl;
            else
                cout << "Invalid vehicle id "<< endl;
            break;
        }

        case 5:
            list.SaveFile("vehicle.txt");
            cout << "Saved to file" << endl;
            break;

        case 6: {
            int updateId;
            cout << "Enter Id to update: " ;
            cin >> updateId;
            bool res = list.Update(updateId);
            if(res)
                cout << "Update vehicle successfully" << endl;
            else
                cout << "Invalid vehicle id" << endl;
            break;
        }

        case 7:
            list.ReadFile("vehicle.txt");
            cout << "Read from file successfully" << endl;
            break;

        case 8:
            list.Statistics();
            break;

        case 0:
            return 0;

        Default:
            cout << "Your command isn’t found.Try again... " << endl;
            break;
        }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    } while (true);
    return 0;
}

