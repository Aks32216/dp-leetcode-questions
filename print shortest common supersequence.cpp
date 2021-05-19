#include <bits/stdc++.h>
using namespace std;

string scs(int n,int m,string a,string b)
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
                t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }
    string res;
    int i=n,j=m;
    while(i!=0 && j!=0)
    {
        if(a[i-1]==b[j-1])
        {
            res+=a[i-1];
            i--;
            j--;
        }
        else if(t[i-1][j]>t[i][j-1])
        {
            res+=a[i-1];
            i--;
        }
        else
        {
            res+=b[j-1];
            j--;
        }
        
    }
    while(i!=0)
        res+=a[i-1],i--;
    while(j!=0)
        res+=b[j-1],j--;
    reverse(res.begin(),res.end());
    return res;
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
    cout<<scs(a.length(),b.length(),a,b);
}