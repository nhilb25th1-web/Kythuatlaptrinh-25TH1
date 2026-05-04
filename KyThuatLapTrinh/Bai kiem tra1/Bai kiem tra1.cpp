#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	cout << "Duyet mang bang con tro: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "*(p + i)" << *(p + i) << endl;
		cout << "p[i]" << p[i] << endl;
	}
	vector<int> v;
    int n, temp;
    cout << "Nhap so luong phan tu n: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu" << i << endl;
		cin >> i;
		v.push_back(temp);
	}
	cout << "Cac phan tu trong vector: ";
	for (int x : v) {
		cout << x << " ";
	}
	int value;
	cout << "Nhap phan tu muon them vao cuoi: ";
	cin >> value;
	v.push_back(value);
	if (!v.empty()) {
		v.pop_back();
		cout << "Da xoa phan tu cuoi cung: ";
	}
	cout << "\n Vector hien tai: ";
	for (int x : v) {
		cout << x << " ";
	}
	return 0;
}

