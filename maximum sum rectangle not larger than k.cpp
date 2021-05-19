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

int check(vector<int> a,int k)
{
	int res=INT_MIN;
	for(int i=0;i<a.size();++i)
	{
		int s=a[i];
		for(int j=i+1;j<a.size();++j)
		{
			if(s<=k)
				res=max(res,s);
			s+=a[j];
		}
		if(s<=k)
			res=max(res,s);
	}
	return res;

}

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

	int n=matrix.size();
	if(n==0)
		return 0;
	int m=matrix[0].size();
	if(m==0)
		return 0;

	int res=INT_MIN;

	for(int i=0;i<m;++i)
	{
		vector<int> v(n,0);
		for(int j=i;j<m;++j)
		{
			for(int s=0;s<n;++s)
				v[s]+=matrix[s][j];
			int val=check(v,k);
			res=max(res,val);
		}
	}
	return res;


}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../output.txt","w",stdout);
	#endif

	BRAHAMASTRA

	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> > v(n,vector<int>(m));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			cin>>v[i][j];
	}
	cout<<maxSumSubmatrix(v,k)<<"\n";
}
