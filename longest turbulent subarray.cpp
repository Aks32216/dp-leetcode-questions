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

/*int maxTurbulenceSize(vector<int>& A) 
{
    int n = A.size();
     if(n==1)
         return 1;
      vector<int> S1(n,0);
      vector<int> S2(n,0);
      int res =0;
      S1[0]=1;
      S2[0]=1;
      for(int i=1;i<n;i++){
         if(A[i]<A[i-1])
             S1[i]=S2[i-1]+1;
          else S1[i]=1;
        if(A[i]>A[i-1])
            S2[i]=S1[i-1]+1;
          else
              S2[i]=1;
        res =max(res, max(S1[i],S2[i]));
    }
        return res;
}*/

int maxTurbulenceSize(vector<int>& a) 
{
    int n=a.size();
    if(n==1)
        return 1;
    if(n==2)
    {
        if(a[0]==a[1])
            return 1;
        else
            return 2;
    }
    vector<int> dp1(n,1),dp2(n,1);
    int  m=INT_MIN;
    for(int i=1;i<n;++i)
    {
        if(i%2==0)
        {
            if(a[i]<a[i-1])
                dp1[i]=dp1[i-1]+dp1[i];
        }
        else
        {
            if(a[i]>a[i-1])
                dp1[i]=dp1[i-1]+dp1[i];
        }
        m=max(m,dp1[i]);
    }
    for(int i=1;i<n;++i)
    {
        if(i%2==0)
        {
            if(a[i]>a[i-1])
                dp2[i]=dp2[i-1]+dp2[i];
        }
        else
        {
            if(a[i]<a[i-1])
                dp2[i]=dp2[i-1]+dp2[i];
        }
        m=max(m,dp2[i]);
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
	vi v(n);
	for(auto& i:v)
		cin>>i;
	cout<<maxTurbulenceSize(v);
}
