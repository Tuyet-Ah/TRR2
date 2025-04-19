#include<iostream>
#include<vector>
using namespace std;
int n;
int a[100][100];
bool check[100];
void DFS(int u)
{
    check[u] = true;
    for(int v = 1 ; v <= n; v++)
        if(a[u][v] == 1 && !check[v])
            DFS(v);
}

void Duyet_cau()
{
    for(int u = 1; u <= n; u++)
    {
        for(int v = u + 1; v <= n ;v++)
        {
            if(a[u][v] == 1)
            {
                a[u][v] = a[v][u] = 0;
                for(int i = 1; i <= n ;i++)
                    check[i] = false;
                DFS(1);
                int cnt = 0;
                for(int i = 1; i <= n ;i++)
                    if(check[i])
                        cnt++;
                if(cnt < n)
                    cout << u <<" "<< v <<endl;
                a[u][v] = a[v][u] = 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i<= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    Duyet_cau();
}