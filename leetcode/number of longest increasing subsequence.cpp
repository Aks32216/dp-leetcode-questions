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

int findnoofLIS(vector<int> nums)
{
	int n=nums.size();
	if(n<=1)
		return n;
	vector<int> dp(n+1,1),count(n+1,1);

	dp[0]=1;
	int maxlen=1;
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(nums[j]<nums[i])
			{
				if(dp[i]==dp[j])
				{
					dp[i]=dp[j]+1;
					count[i]=count[j];
				}
				else if(dp[j]+1==dp[i])
				{
					count[i]+=count[j];
				}
			}
		}
		maxlen=max(maxlen,dp[i]);
	}
	int ans=0;
	for(int i=0;i<n;++i)
		if(dp[i]==maxlen)
			ans+=count[i];
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../output.txt","w",stdout);
	#endif

	BRAHAMASTRA

	int n;
	cin>>n;
	vector<int> v(n);
	for(auto& i:v)
		cin>>i;
	cout<<findnoofLIS(v)<<"\n";
}
