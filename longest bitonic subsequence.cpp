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

vector<int> lid(vector<int> v)
{
	int n=v.size();
	vector<int> a(n,1);
	for(int i=n-2;i>=0;--i)
	{
		for(int j=n-1;j>i;--j)
		{
			if(v[j]<v[i])
				a[i]=max(a[i],a[j]+1);
		}
		
	}
	return a;
}

vector<int> lis(vector<int> v)
{
    int n=v.size();
    vector<int> a(n,1);
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(v[i]>v[j])
            {
                a[i]=max(a[i],a[j]+1);
            }
        }
    }
    return a;
}

int longestbitonicsubsequence(vector<int> v)
{
    int n=v.size();
    if(n==1)
        return 1;
    vector<int> b;
    b=v;
    v=lis(v);
    b=lid(b);
    int m=INT_MIN;
    for(int i=0;i<n;++i)
    {
        m=max(m,v[i]+b[i]-1);
    }
    return m;
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
    cout<<longestbitonicsubsequence(v);
}
