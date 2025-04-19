#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int n, s, t;
int a[100][100];
bool check[100];
int truoc[100];
void DFS(int u)
{
    check[u] = true;
    for(int v = 1; v <= n;v++)
    {
        if(a[u][v] == 1 && check[v] == false)
        {
            truoc[v] = u;
            DFS(v);  
        }          
    }
}
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    check[u] = true;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(int v = 1; v <= n; v++)
        {
            if(a[s][v] == 1 && !check[v])
            {
                q.push(v);
                check[v] = true;
                truoc[v] = s;
            }
        }
    }
}

void path()
{
    for(int i = 1; i <= n ;i++)
    {
        check[i] = false;
        truoc[i] = 0;
    }
    DFS(s);   
    if(truoc[t] == 0)
        cout << "no path" << endl;
    else
    {
        cout << "DFS path: " << t << " ";
        int u = truoc[t];
        while(u != s)
        {
            cout << u << " ";
            u = truoc[u];
        }
        cout << s << endl;
    }
    for(int i = 1; i <= n ;i++)
    {
        check[i] = false;
        truoc[i] = 0;
    }
    BFS(s);
    if(truoc[t] == 0)
        cout << "no path" << endl;
    else
    {
        cout << "BFS path: " << t << " ";
        int u = truoc[t];
        while(u != s)
        {
            cout << u << " ";
            u = truoc[u];
        }
        cout << s << endl;
    }

}

int main()
{
    cin >> n >> s >> t;
    for(int i = 1 ; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    path();
}