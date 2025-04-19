#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int n;
int a[100][100];
bool check[100];
void DFS(int u)
{
   check[u] = true;
   for(int v = 1; v <=n ; v++)
        if(a[u][v] == 1 && check[v] == false)
            DFS(v);
}
bool strongly_connect()
{
    for(int u = 1; u <= n ;u++)
    {
        for(int i = 1; i <= n; i++)
            check[i] = false;
        DFS(u);
        for(int v = 1; v <= n ;v++)
        {
            if(!check[v])
                return false;
        }
    }
    return true;
}
int main()
{
    cin >> n;
    for(int i = 1; i<= n; i++)
        for(int j = 1; j <=n ;j++)
            cin >> a[i][j];
    if(strongly_connect())
        cout << "strongly connected" << endl;
    else
        cout<<"not strongly connected" << endl;
    
}