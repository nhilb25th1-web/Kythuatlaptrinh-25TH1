#include <iostream>
#include <string>
using namespace std;


int demSoTu(string s) {
    int dem = 0;
    bool trongTu = false;

    for (char c : s) {
        if (c != ' ' && trongTu == false) {
            dem++;
            trongTu = true;
        }
        else if (c == ' ') {
            trongTu = false;
        }
    }
    return dem;
}


string vietHoaDauTu(string s) {
    bool vietHoa = true;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' && vietHoa) {
            s[i] = toupper(s[i]);
            vietHoa = false;
        }
        else if (s[i] == ' ') {
            vietHoa = true;
        }
        else {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}

int main() {
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);
    cout << "So tu trong chuoi: " << demSoTu(s) << endl;
    cout << "Chuoi viet hoa dau tu: " << vietHoaDauTu(s) << endl;
    return 0;
}