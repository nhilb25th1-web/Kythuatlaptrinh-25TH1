#include<iostream>
#include<vector>
using namespace std;

int main() {
	int a = 5;
	int* p = &a;
	a += 6;
	a = *p + 2;
	cout << *p;
	/*vector <float> diemthi;
	diemthi.push_back(10);
	diemthi.push_back(8);
	diemthi.push_back(6);
	diemthi.pop_back();
	for (int i = 0; i < diemthi.size(); i++) {
		cout << diemthi[i] << endl;
	}*/
	
}
