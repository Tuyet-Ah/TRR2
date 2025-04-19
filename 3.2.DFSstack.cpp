#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int n;
bool check[100]; // danh dau dinh ma tran
int a[100][100]; // matran do thi
void DFS(int u)
{
    stack<int> st;
    st.push(u);
    while(!st.empty())
    {
        int s = st.top();
        st.pop();
        if(!check[s])
        {
            cout <<s << " ";
            check[s] = true;
        }
        for(int v = n; v >= 1; v--)
        {
            if(a[s][v] == 1 && check[v] == false)
                st.push(v);
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n ;i++)
        for(int j = 1; j <= n ;j++)
            cin >> a[i][j];
    DFS(1);
}