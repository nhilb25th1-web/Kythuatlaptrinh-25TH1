template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
struct LinkedList {
	Node<T>* head;
	void Show();
};

template <typename T>
void LinkedList<T>::Show() {
	Node<T>* head;
		if (head == NULL) {
			cout << "No account available" << endl;
			return;
		}
		Node* item = head;
		while (item != NULL) {
			cout << item->data;
			item = item->next;
	    }
}
