#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data;
    Node *left, *right;
    int size;

public:
    Node(int x)
    {
        left = right = 0;
        data = x;
        size = 0;
    };
    friend pair<int, bool> double_search(Node *root, int x);
    friend Node *insert_node(Node *root, int x);
    friend Node *findMostLeft(Node *root);
    friend Node *Delete_Node(Node *root, int x);
    friend void preOrder(Node *root);
    friend void deleteTree(Node *root)
    {
        if (root == nullptr)
            return;

        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

Node *insert_node(Node *root, int x)
{
    if (root == 0)
    {
        return new Node(x);
    }

    if (root->data < x)
    {
        root->right = insert_node(root->right, x);
    }
    else if (x < root->data)
    {
        root->left = insert_node(root->left, x);
    }
    root->size = (root->left != 0 ? root->left->size + 1 : 0) + (root->right != 0 ? root->right->size + 1 : 0);
    return root;
}
pair<int, bool> double_search(Node *root, int x)
{
    if (root == 0)
        return {0, false};
    int SL_node_con = (root->left == 0) ? 0 : root->left->size + 1;
    if (root->data == x)
        return {SL_node_con, true};
    else if (x < root->data)
    {
        return double_search(root->left, x);
    }
    else if (root->data < x)
    {
        pair<int, bool> kq = double_search(root->right, x);
        return {kq.first + SL_node_con + 1, kq.second};
    }
}
Node *findMostLeft(Node *root)
{
    if (root == 0)
        return NULL;
    Node *MostLeft = root;
    while (MostLeft->left != NULL)
    {
        MostLeft = MostLeft->left;
    }
    return MostLeft;
}
Node *Delete_Node(Node *root, int x)
{
    if (root == 0)
        return NULL;
    if (root->data < x)
    {
        root->right = Delete_Node(root->right, x);
    }
    else if (x < root->data)
    {
        root->left = Delete_Node(root->left, x);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return nullptr;
        }
        if (root->left == NULL && root->right != NULL || root->right == NULL && root->left != NULL)
        {
            Node *temp = (root->left != nullptr) ? root->left : root->right;
            delete root;
            return temp;
        }
        Node *mostLeft = findMostLeft(root->right);
        root->data = mostLeft->data;
        root->right = Delete_Node(root->right, mostLeft->data);
    }
    root->size = (root->left != 0 ? root->left->size + 1 : 0) + (root->right != 0 ? root->right->size + 1 : 0);
    return root;
}
void preOrder(Node *root)
{
    if (root == 0)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b;
    Node *root = nullptr;
    // vector<int> result;
    while (true)
    {
        cin >> a;
        if (a == 0)
            break;
        cin >> b;
        if (a == 1)
        {
            root = insert_node(root, b);
        }
        else if (a == 2)
        {
            // preOrder(root);
            pair<int, bool> index = double_search(root, b);

            if (!index.second)
            {
                // result.push_back(0);
                cout << 0 << "\n";
            }
            else
            {
                // result.push_back(index.first + 1);
                cout << index.first + 1 << "\n";
            }
        }
        else if (a == 3)
        {
            root = Delete_Node(root, b);
        }
    }
    // for (int res : result)
    //     cout << res << "\n";
    deleteTree(root);
    system("pause");
    return 0;
}
