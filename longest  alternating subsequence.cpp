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

/*int longestalternatingsubsequence(vector<int> a)
{
    int n=a.size();
    if(n==1)
        return 1;
    int dp[n][2];
    for(int i=0;i<n;++i)
        dp[i][0]=dp[i][1]=1;
    int m=INT_MIN;
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(a[i]>a[j] and dp[i][0]<dp[j][1]+1)
                dp[i][0]=dp[j][1]+1;
            else if(a[i]<a[j] and dp[i][1]<dp[j][0]+1)
                dp[i][1]=dp[j][0]+1;
        }
        m=max(m,max(dp[i][0],dp[i][1]));
    }
    return m;
}*/

int maxTurbulenceSize(vector<int>& a) 
{
    int n=a.size();
    if(n==1)
        return 1;
    int ma=1,mi=1;
    int m=INT_MIN;
    for(int i=1;i<n;++i)
    {
        if(a[i]>a[i-1])
            ma=mi+1;
        else if(a[i]<a[i-1])
            mi=ma+1;
        else
            continue;
    }
    return max(ma,mi);
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
    cout<<maxTurbulenceSize(v);
}
