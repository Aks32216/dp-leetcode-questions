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

LIS approach:

int maxEnvelopes(vector<vector<int>>& envelopes) {
	int n=envelopes.size();
	vector<int> ans(n,1);
	int m=INT_MIN;
	if(n==1 || n==0)
		return 1;
	sort(envelopes.begin(),envelopes.end());
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1])
			{
				ans[i]=max(ans[i],ans[j]+1);
			}
		}
		m=max(m,ans[i]);
	}
	return m;

}*/

// binary search approach

static bool cmp(vector<int>v1,vector<int>v2)
{
	return v1[0]==v2[0]?v1[1]>v2[1]:v1[0]<v2[0];
}
int maxEnvelopes(vector<vector<int>>& nums)
{
	sort(nums.begin(),nums.end(),cmp);

	set<int>s;
	for(int i=0;i<nums.size();i++)
	{
		auto it=s.lower_bound(nums[i][1]);
		if(it!=s.end())
		{
			s.erase(it);
		}
		s.insert(nums[i][1]);
		for(auto i:s)
			cout<<i<<" ";
		cout<<"\n";
	}
	return s.size();
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
	vector<vector<int> > v(n,vector<int>(2));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<2;++j)
			cin>>v[i][j];
	}
	cout<<maxEnvelopes(v)<<"\n";
}
