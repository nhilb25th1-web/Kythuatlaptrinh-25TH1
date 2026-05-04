#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void tachHoTen() {
    cin.ignore();
    string s;
    cout << "Nhap ho va ten: ";
    getline(cin, s);
    stringstream ss (s);
    string word;
    string ho = "", ten = "", lot = "";
    ss >> ho;
    while (ss >> word) {
        if (ten != "") lot += " ";
        lot += ten;
        ten = word;
    }
    cout << "Ho: " << ho << endl;
    cout << "Ten lot: " << lot << endl;
    cout << "Ten: " << ten << endl;
}


void xoaKyTu() {
    cin.ignore();
    string s;
    char x;
    cout << "Nhap chuoi: ";
    getline(cin, s);
    cout << "Nhap ky tu can xoa: ";
    cin >> x;
    string result = "";
    for (char c : s) {
        if (c != x) result += c;
    }

    cout << "Chuoi sau khi xoa: " << result << endl;
}


void doiXung() {
    cin.ignore();
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);
    int l = 0, r = s.size() - 1;
    bool ok = true;
    while (l < r) {
        if (s[l] != s[r]) {
            ok = false;
            break;
        }
        l++; r--;
    }

    if (ok) cout << "Chuoi doi xung" << endl;
    else cout << "Chuoi khong doi xung" << endl;
}

void viTriCuoi() {
    cin.ignore();
    string X;
    char Y;
    cout << "Nhap chuoi X: ";
    getline(cin, X);
    cout << "Nhap ky tu Y: ";
    cin >> Y;
    int pos = -1;
    for (int i = 0; i < X.size(); i++) {
        if (X[i] == Y) pos = i;
    }
    if (pos == -1)
        cout << "Khong tim thay ky tu" << endl;
    else
        cout << "Vi tri cuoi cung: " << pos << endl;
}


int main() {
    int choice;

    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Tach ho, lot, ten" << endl;
        cout << "2. Xoa ky tu trong chuoi" << endl;
        cout << "3. Kiem tra chuoi doi xung" << endl;
        cout << "4. Tim vi tri xuat hien cuoi cung cua ky tu" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            tachHoTen();
            break;
        }
        case 2: {
            xoaKyTu();
            break;
        }
        case 3: {
            doiXung();
            break;
        }
        case 4: {
            viTriCuoi();
            break;
        }
        case 0: 
            cout << "Thoat chuong trinh" << endl; 
            break;
        default: 
            cout << "Lua chon khong hop le!" << endl;
        }

    } while (choice != 0);

    return 0;
}
