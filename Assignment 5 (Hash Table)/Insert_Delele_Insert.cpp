/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <string>

using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE {
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, Giá trị khác: Node đang tồn tại giá trị
    int key;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i) {
    int h=HF(ht, key);
    return (h + i) % ht.M;
}
//###INSERT CODE HERE -
void CreateHashTable(HASHTABLE &ht) {
    cin >> ht.M;
    ht.table = new NODE[ht.M];
    for (int i = 0; i < ht.M; i++) {
        ht.table[i].flag = EMPTY; // 0
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        // 1: Insert
        // 0: Delete
        // If HashTable >= 70% -> Cannot insert
        int choose; // Insert or Delete
        cin >> choose;
        int key;
        cin >> key;
        if(choose == 1) // Insert 
        {
            // Check if key twice -> continue
            bool check = false;
            for(int j = 0; j < ht.M; j++) {
                if(ht.table[j].key == key) {
                    check = true;
                    break;
                }
            }
            if(check) {
                continue;
            }
            if(ht.n >= int(ht.M * LOAD)) {
                continue;
            }
            int index = HF(ht, key);
            int i = 0;
            while(ht.table[index].flag == OCCUPIED) {
                index = HF_LinearProbing(ht, key, i);
                i++;
            }
            ht.table[index].key = key;
            ht.table[index].flag = OCCUPIED;
            ht.n++;
        }
        else if(choose == 0) // Delete
        {
            int index = HF(ht, key);
            int i = 0;
            while(ht.table[index].flag != EMPTY && ht.table[index].key != key) {
                index = HF_LinearProbing(ht, key, i);
                i++;
            }
            if(ht.table[index].flag == OCCUPIED) {
                ht.table[index].flag = DELETED;
                ht.n--;
            }
        }
    }
}
void Traverse(HASHTABLE ht) {
    for (int i = 0; i < ht.M; i++) {
        cout << i << " --> ";
        if (ht.table[i].flag == OCCUPIED) {
            cout << ht.table[i].key;
        }
        else if(ht.table[i].flag == EMPTY) {
            cout << "EMPTY";
        }
        else {
            cout << "DELETED";
        }
        cout << endl;        
    }
}
void DeleteHashtable(HASHTABLE &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}
