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

/*int res = -1e7;
int dp[502][502];
int solve(vector<int>&a,vector<int>&b,int i,int j,int n,int m)
{
        // base case
	if(i >= n || j >= m)
		return -1e9;

	if(dp[i][j]!=-1)
		return dp[i][j];
	int r1 = -1e9;
	int r2 = -1e9;
	int r3 = -1e9;
	int r4 = -1e9;
        //either you dont take the current ith index
	r1 = solve(a,b,i+1,j,n,m) ;
        //either you dont take the jth index
	r2 = solve(a,b,i,j+1,n,m);
        //dont take both ith and jth index
	r3 = solve(a,b,i+1,j+1,n,m) ;
        // if on adding ith jth multiplication gives -ve value make it 0 else add total upto r3
	r4 = a[i]*b[j] + (r3<0? 0: r3);
        //take max of all the paths
	dp[i][j] =  max(r1,max(r2,max(r3,r4)));
	return dp[i][j];

}
int maxDotProduct(vector<int>& a, vector<int>&b) {
	int n = a.size();
	int m = b.size();
	memset(dp , -1,sizeof(dp));
	return solve(a,b,0,0,n,m);
}*/

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
	int n=nums1.size();
	int m=nums2.size();
	vector<vector<int> > dp(n+1,vector<int>(m+1,-100000));
	
	for(int i=1;i<m+1;++i)
	{
		dp[1][i]=max(nums1[0]*nums2[i-1],dp[1][i-1]);
	}
	for(int i=1;i<n+1;++i)
	{
		dp[i][1]=max(nums1[i-1]*nums2[0],dp[i-1][1]);
	}
	
	int ans=-1000;
	
	for(int i=2;i<n+1;++i)
	{
		for(int j=2;j<m+1;++j)
		{
			dp[i][j]=max(nums1[i-1]*nums2[j-1],max(nums1[i-1]*nums2[j-1]+dp[i-1][j-1],max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]))));
			ans=max(ans,dp[i][j]);
		}
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../output.txt","w",stdout);
	#endif

	BRAHAMASTRA

	int n,m;
	cin>>n>>m;
	vi a(n),b(m);
	for(auto& i:a)
		cin>>i;
	for(auto& i:b)
		cin>>i;
	cout<<maxDotProduct(a,b);
}
