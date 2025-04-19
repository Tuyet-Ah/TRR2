#include<iostream>
#include<vector>
using namespace std;
int n;
bool check[100]; // danh sach dinh ma tran
int a[100][100]; // ma tran do thi

void DFS(int u)
{
    cout << u <<" ";
    check[u] = true;
    for(int v = 1; v <= n; v++)
        if(a[u][v] == 1 && check[v] == false)
            DFS(v);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n ;j++)
            cin >> a[i][j];
    DFS(1);
}
