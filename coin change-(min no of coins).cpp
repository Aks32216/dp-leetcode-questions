#include <bits/stdc++.h>
using namespace std;

int minnoofcoin(int n,int sum,vector<int> coin)
{
    int t[n+1][sum+1];
    for(int i=0;i<sum+1;++i)
        t[0][i]=INT_MAX-1;
    for(int i=1;i<n+1;++i)
        t[i][0]=0;
    for(int i=1,j=1;j<sum+1;++j)
    {
        if(j%coin[0])
            t[i][j]=j/coin[0];
        else
            t[i][j]=INT_MAX-1;
    }
    for(int i=2;i<n+1;++i)
    {
        for(int j=1;j<sum+1;++j)
        {
            if(coin[i-1]<=j)
                t[i][j]=min(1+t[i][j-coin[i-1]],t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,sum;
    cin>>n;
    std::vector<int> coin(n);
    for(auto& i:coin)
        cin>>i;
    cin>>sum;
    cout<<minnoofcoin(n,sum,coin);
}