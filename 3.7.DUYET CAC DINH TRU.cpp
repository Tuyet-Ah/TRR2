#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> path;
bool check[100];
int a[100][100];
void DFS(int u)
{
    check[u] = true;
    for(int v = 1; v <= n; v++)
    {
        if(a[u][v] == 1 && check[v] == false)
            DFS(v);
    }
}
void Duyet_tru()
{
    for(int u = 1; u <= n ; u++)
    {
        for(int i = 1; i <= n ; i++)
            check[i] = false;
        check[u] = true;
        int start = 1;
        if(u == 1)
            start = 2;
        DFS(start);
        bool ktra = false;
        for(int v = 1; v <= n; v++)
        {
            if(v!= u && !check[v])
            {
                ktra = true;
                break;
            }
        }
        if(ktra)
            path.push_back(u);
    }
    for(int x : path)
            cout << x <<" ";
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n ;i++)
        for(int j = 1; j <= n ;j++)
            cin >> a[i][j];
    Duyet_tru();
    
}