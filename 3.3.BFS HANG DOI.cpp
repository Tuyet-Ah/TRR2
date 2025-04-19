#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool check[100];
int n;
int a[100][100];
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    check[u] = true;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        cout << s <<" ";
        for(int v = 1; v <= n; v++)
        {
            if(a[s][v] == 1 && !check[v])
            {
                q.push(v);
                check[v] = true;
            }
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n ;i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    BFS(1);
}