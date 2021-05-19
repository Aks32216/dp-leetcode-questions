#include <bits/stdc++.h>
using namespace std;

int LCS(int n,int m,string a,string  b)
{
    int t[n+1][m+1];
    for(int i=0;i<n+1;++i)
        t[i][0]=0;
    for(int i=0;i<m+1;++i)
        t[0][i]=0;
    for(int i=1;i<n+1;++i)
    {
        for(int j=1;j<m+1;++j)
        {
            if(a[i-1]==b[j-1])
                t[i][j]=1+t[i-1][j-1];
            else
                t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return n+m-t[n][m];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string a,b;
    cin>>a>>b;
    cout<<LCS(a.length(),b.length(),a,b);
}