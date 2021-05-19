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

recursion with memoization

int dp[101][101];

bool solve(string a,string b,string c,int n,int m,int len)
{
	if(len==0)
		return 1;
	if(dp[n][m]!=-1)
		return dp[n][m];
	int x,y;
	x=y=0;
	if(n-1>=0 and a[n-1]==c[len-1])
		x=solve(a,b,c,n-1,m,len-1);
	if(m-1>=0 and b[m-1]==c[len-1])
		y=solve(a,b,c,n,m-1,len-1);
	return dp[n][m]=x || y;
}

bool isinterleave(string a,string b,string c)
{
	int n=a.length();
	int m=b.length();
	int len=c.length();

	if(n+m!=len)
		return false;
	memset(dp,-1,sizeof(dp));
	return solve(a,b,c,n,m,len);
}*/

bool isinterleave(string a,string b,string c)
{
	int n=a.length();
	int m=b.length();
	if(n+m!=c.length())
		return false;
	int t[n+1][m+1];
	memset(t,0,sizeof(t));
	for(int i=0;i<n+1;++i)
	{
		for(int j=0;j<m+1;++j)
		{
			if(i==0 and j==0)
				t[i][j]=true;
			else if(j==0)
			{
				if(a[i-1]==c[i-1])
					t[i][j]=t[i-1][j];
			}
			else if(i==0)
			{
				if(b[j-1]==c[j-1])
					t[i][j]=t[i][j-1];
			}
			else if(a[i-1]==c[j+i-1] and b[j-1]!=c[j+i-1])
				t[i][j]=t[i-1][j];
			else if(a[i-1]!=c[j+i-1] and b[j-1]==c[j+i-1])
				t[i][j]=t[i][j-1];
			else if(a[i-1]==c[j+i-1] and b[j-1]==c[j+i-1])
				t[i][j]=t[i-1][j] || t[i][j-1];
		}
	}
	return t[n][m];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../output.txt","w",stdout);
	#endif

	BRAHAMASTRA

	string a,b,c;
	cin>>a>>b>>c;
	cout<<isinterleave(a,b,c)<<"\n";
}
