#include <fstream>
template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
struct LinkedList {
	Node<T>* head;
	void Show();
	void Add(T item);
	bool Remove(int id);
	bool Update(int id);
	void Find(string userName);
	void Export(string fileName);
	void Import(string fileName);
};

template <typename T>
void LinkedList<T>::Export(string fileName) {
	ofstream outFile(fileName, ios::binary);
	if (!outFile) {
		cout << "Error opening file for writing" << endl;
		return;
	}
	Node<T>* item = head;
	while (item != NULL) {
		outFile.write(reinterpret_cast<char*>(&item->data), sizeof(T));
		item = item->next;
	}
	outFile.close();
}

template <typename T>
void LinkedList<T>::Import(string fileName) {
	ifstream inFile(fileName, ios::binary);
	if (!inFile) {
		cout << "Error opening file for reading" << endl;
		return;
	}
	Node<T>* item = head;
	while (item != NULL) {
		Node<T>* temp = item;
		item = item->next;
		delete temp;
	}
	T item;
	while(inFile.read(reinterpret_cast<char*>(&item), sizeof(T))) {
		Add(item);
	}
	inFile.close();
}

template <typename T>
void LinkedList<T>::Find(string userName) {
	if (!head) {
		cout << "No account available" << endl;
		return;
	}
	Node<T>* item = head;
	while (item != NULL) {
		if (item->data.usr == userName) {
			cout << item->data << endl;
			return;
		}
		item = item->next;
	}
	cout << "No account found" << endl;
}

template <typename T>
void LinkedList<T>::Show() {
	if (head == NULL) {
			cout << "No account available" << endl;
			return;
	}
	Node<T>* item = head;
	while (item != NULL) {
			cout << item->data;
			item = item->next;
	}
}


template<typename T> 
void LinkedList<T>::Add(T item) {
	Node<T>* newNode = new Node<T>;
	newNode->data = item;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node<T>* item = head;
		while (item->next != nullptr) {
			item = item->next;
		}
		item->next = newNode;
	}
}
template <typename T>
bool LinkedList<T>::Remove(int  id) {
	if (!head) {
		cout << "No account available" << endl;
	}
	Node<T>* item = head;
	if (item->data.id == id) {
		head = item->next;
		delete item;
		return true;
	}
	while (item->next != nullptr) {
		if (item->next->data.id == id) {
			Node<T>* temp = item->next;
			item->next = item->next->next;
			delete temp;
			return true;
		}
		item = item->next;
	}
	return false;
}


template <typename T>
bool LinkedList<T>::Update(int  id) {
	if (!head) {
		cout << "No account available" << endl;
		return false;
	}
	Node<T>* item = head;
	while (item != NULL) {
		if (item->data.id == id) {
			cin >> item->data;
			return true;
		}
		item = item->next;
	}
	return false;
};
	
