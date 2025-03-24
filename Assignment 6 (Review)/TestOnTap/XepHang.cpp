#include <iostream>
using namespace std;
#include <stack>

int Check_Near(stack<int> s, int a[], int i)
{
    int index1, index2;
    index2 = s.top();
    s.pop();
    int count = 0;
    while (!s.empty() && a[s.top()] < a[i])
    {
        index1 = s.top();
        if (index2 - index1 == 1)
            count++;
        index2 = index1;
        s.pop();
    }
    return count;
}

int XepHang(int a[], int n)
{
    int count = 0;
    stack<int> s;
    int index[n];
    for (int i = 0; i < n; i++)
    {
        index[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int Dem_Pop = 0;
        while (!s.empty() && a[s.top()] <= a[i])
        {
            if (Dem_Pop == 0)
                index[s.top()] += 1;
            else
                index[s.top()] += Dem_Pop;
            if (a[s.top()] == a[i])
                index[s.top()] += 1;
            Dem_Pop++;
            s.pop();
        }
        if (!s.empty())
        {
            if (Dem_Pop == 0)
                index[s.top()]++;
            else
                index[s.top()] += Dem_Pop;
        }
        for (int i = 0; i < n; i++)
            cout << index[i] << " ";
        cout << endl;
        s.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        count += index[i];
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << XepHang(a, n);
    system("pause");
    return 0;
}