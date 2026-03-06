#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector <float> diemthi;
	diemthi.push_back(10);
	diemthi.push_back(4);
	diemthi.push_back(6);
	diemthi.pop_back();
	for (int i = 0; i < diemthi.size(); i++) {
		cout << diemthi[i] << endl;
	}
	
}
