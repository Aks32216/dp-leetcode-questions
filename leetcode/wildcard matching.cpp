#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
 
using namespace std;
#define set_precision cout << fixed << setprecision(10)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define replb(i, a, b) for (ll i = a; i >= b; i--)
#define repl(i, a, b) for (ll i = a; i < b; i++)
#define repit(arr) for (auto it = arr.begin(); it != arr.end(); 
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<long long int>
#define Vi vector<vector<int>>
#define vpi vector<pair<int,int> >
#define seti set<int>
#define setl set<ll>
#define dseti set<int, greater<int>>
#define dsetl set<ll, greater<ll>>
#define mseti multiset<int>
#define msetl multiset<ll>
#define dmseti multiset<int, greater<int>>
#define dmsetl multiset<ll, greater<ll>>
#define sortA(arr) sort(arr.begin(), arr.end())
#define dsortA(arr) sort(arr.begin(), arr.end(), greater<int>())
#define ssort(arr) stable_sort(arr.begin(), arr.end())
#define search(arr, c) binary_search(arr.begin(), arr.end(), c)
#define pb push_back
#define ll long long
#define cl_bf cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define castl static_cast<ll>
#define BRAHAMASTRA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull unsigned long long int

/*

recursive with memoization appraoch

int dp[1000][1000];

bool solve(int i,int j,string s,string p)
{
    if(i>=s.length() && j>=p.length())
        return 1;
    if(i>=s.length())
    {
        for(int k=0;k<j;++k)
            if(p[k]!='*')
                return 0;
        return 1;
    }
    if(j>=p.length())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
        
    bool match=(i<s.length() && (s[i]==p[j] or p[j]=='?'));
    if(match)
        return dp[i][j]=solve(i+1,j+1,s,p);
    if(j<p.length() && p[j]=='*')
        return dp[i][j]=(solve(i+1,j,s,p) or solve(i,j+1,s,p));
    return dp[i][j]=0;
}

bool ismatch(string s,string p)
{
    memset(dp,-1,sizeof(dp));
    return solve(0,0,s,p);
}*/

bool ismatch(string s,string p)
{
    int n=s.length();
    int m=p.length();
    bool dp[n+1][m+1];
    memset(dp,false,sizeof(dp));
    dp[0][0]=false;
    for(int i=1;i<m+1;++i)
    {
        if(p[i-1]=='*')
            dp[0][i]=true;
        else
            break;
    }
    for(int i=1;i<n+1;++i)
    {
        for(int j=1;j<m+1;++j)
        {
            if(p[j-1]!='*')
            {
                if(p[j-1]=='?' || p[j-1]==s[i-1])
                    dp[i][j]=dp[i-1][j-1];
            }
            else
                dp[i][j]=dp[i-1] or dp[i][j-1];
        }
    }
    return dp[n][m];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../output.txt","w",stdout);
	#endif

	BRAHAMASTRA

	string s,p;
    cin>>s>>p;
    cout<<ismatch(s,p)<<"\n";
}
