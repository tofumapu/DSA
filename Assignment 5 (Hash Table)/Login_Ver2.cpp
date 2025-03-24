#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> userPasswords; // Hash table lưu user và mật khẩu mới nhất

    // Đọc N cặp user-password
    for (int i = 0; i < n; i++) {
        string user, password;
        cin >> user >> password;
        userPasswords[user] = password; // Cập nhật mật khẩu mới nhất cho user
    }

    // Đọc M truy vấn và in kết quả
    for (int i = 0; i < m; i++) {
        string queryUser;
        cin >> queryUser;

        if (userPasswords.find(queryUser) != userPasswords.end()) {
            // Nếu tìm thấy user, in ra mật khẩu mới nhất
            cout << userPasswords[queryUser] << endl;
        } else {
            // Nếu không tìm thấy, in "Unregistered User."
            cout << "Unregistered User." << endl;
        }
    }

    return 0;
}
