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



/*int dp[1001][1001];

int solve(int i,int j,vector<int> v,int k)
{
    if(i>=j)
        return 0;
    if(v[j]-v[i]<=k)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=1+min(solve(i+1,j,v,k),solve(i,j-1,v,k));
    
}

int removals(vector<int> v,int k)
{
    memset(dp,-1,sizeof(dp));
    sort(v.begin(),v.end());
    if(v[v.size()-1]-v[0]<=k)
        return 0;
    return solve(0,v.size()-1,v,k);
}*/


/*int binarysearch(vector<int> a,int k,int val,int start,int end)
{
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==val)
			return mid;
		if(a[mid]<val)
			res=mid,start=mid+1;
		else if(a[mid]>val)
			end=mid-1;
    }
    return end;
}

int removals(vector<int> v,int k)
{
    int m=INT_MAX;
    int n=v.size();
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i)
    {
        int val=v[i]+k;
        int j=binarysearch(v,k,val,i+1,n-1);
        cout<<val<<" "<<j<<"\n";
        m=min(m,(n-(j-i+1)));
    }
    return m;
}*/

int removals(vector<int> v,int k)
{
    int m=INT_MAX;
    int n=v.size();
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i)
    {
        int val=v[i]+k;
        int j=lower_bound(v.begin(),v.end(),val)-v.begin();
        j--;
        cout<<val<<" "<<j<<"\n";
        m=min(m,(n-(j-i+1)));
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

	int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto& i:v)
        cin>>i;
    cout<<removals(v,k);
}
