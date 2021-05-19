#include <bits/stdc++.h>
using namespace std;

int maxnoofways(int n,int sum,vector<int> coin)
{
    int t[n+1][sum+1];
    for(int i=0;i<sum+1;++i)
        t[0][i]=0;
    for(int i=1;i<n+1;++i)
        t[i][0]=1;
    for(int i=1;i<n+1;++i)
    {
        for(int j=1;j<sum+1;++j)
        {
            if(coin[i-1]<=j)
                t[i][j]=(t[i][j-coin[i-1]] + t[i-1][j]);
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
    vector<int> coin(n);
    for(auto& i:coin)
        cin>>i;
    cin>>sum;
    cout<<maxnoofways(n,sum,coin);
}