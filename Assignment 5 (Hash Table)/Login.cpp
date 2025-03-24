#include <iostream>
#include <string>
using namespace std;

struct PASS_NODE {
    string pass;
    PASS_NODE* pNext;
};

struct USER_NODE {
    string user;
    PASS_NODE* passHead;
    USER_NODE* pNext;
};

const int TABLE_SIZE = 100;
USER_NODE* H[TABLE_SIZE];

int HF(const string& user) {
    int hash = 0;
    for (char c : user) {
        hash = (hash * 31 + c) % TABLE_SIZE;
    }
    return hash;
}

void InsertUser(const string& user, const string& pass) {
    int index = HF(user);
    USER_NODE* newUser = new USER_NODE;
    newUser->user = user;
    newUser->passHead = new PASS_NODE{pass, nullptr};
    newUser->pNext = H[index];
    H[index] = newUser;
}

void AddPassword(USER_NODE* userNode, const string& pass) {
    PASS_NODE* newPass = new PASS_NODE{pass, userNode->passHead};
    userNode->passHead = newPass;
}

void ProcessQueries(int m) {
    cin.ignore();
    cin.ignore();
    // Đọc M truy vấn
    for (int i = 0; i < m; i++) {
        string user;
        getline(cin, user);

        int index = HF(user);
        USER_NODE* p = H[index];
        while (p != NULL) {
            if (p->user == user) {
                if (p->passHead != NULL) {
                    cout << p->passHead->pass << endl;
                } else {
                    cout << "Unregistered User." << endl;
                }
                goto nextQuery;
            }
            p = p->pNext;
        }
        cout << "Unregistered User." << endl;
    nextQuery:;
    }
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        H[i] = nullptr;
    }

    // Read n users and passwords
    for (int i = 0; i < n; i++) {
        string user, pass;
        cin >> user >> pass;

        int index = HF(user);
        USER_NODE* p = H[index];
        while (p != NULL) {
            if (p->user == user) {
                AddPassword(p, pass);
                goto nextInput;
            }
            p = p->pNext;
        }

        InsertUser(user, pass);

    nextInput:;
    }

    ProcessQueries(m);

    return 0;
}