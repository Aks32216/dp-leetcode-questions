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

vector<int> NSR(vector<int> a,int n)
{
	vector<int> res;
	stack<pair<int,int> > s;
	for(int i=n-1;i>=0;--i)
	{
		if(s.empty())
			res.push_back(n);
		else if(s.top().first<a[i])
			res.push_back(s.top().second);
		else if(s.top().first>=a[i])
		{
			while(!s.empty() && s.top().first>=a[i])
				s.pop();
			if(s.empty())
				res.push_back(n);
			else
				res.push_back(s.top().second);
		}
		s.push({a[i],i});
	}
	reverse(res.begin(),res.end());
	return res;
}

vector<int> NSL(vector<int> a,int n)
{
	vector<int> res;
	stack<pair<int,int> > s;
	for(int i=0;i<n;++i)
	{
		if(s.empty())
			res.push_back(-1);
		else if(s.top().first<a[i])
			res.push_back(s.top().second);
		else if(s.top().first>=a[i])
		{
			while(!s.empty() && s.top().first>=a[i])
				s.pop();
			if(s.empty())
				res.push_back(-1);
			else
				res.push_back(s.top().second);
		}
		s.push({a[i],i});
	}
	return res;
}

int maxareahistogram(vector<int> a,int n)
{
	vector<int> nsl,nsr;
	nsl=NSL(a,n);
	nsr=NSR(a,n);

	int ans=1;
	for(int i=0;i<n;++i)
	{
		int length=nsr[i]-nsl[i]-1;
		ans=max(ans,length*a[i]);
	}
	return ans;
}

int maximalRectangle(vector<vector<char>>& matrix) 
{
    int n=matrix.size();
    int m=matrix[0].size();
    if(n==0 || m==0)
        return 0;
    bool ok=false;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(matrix[i][j]=='0')
                continue;
            else
            {
                ok=true;
                break;
            }
        }
        if(ok)
            break;
    }
    if(!ok)
        return 0;
    vector<int> res(m,0);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(matrix[i][j]=='0')
                res[j]=0;
            else
                res[j]+=1;
        }
        
        
        int temp=maxareahistogram(res,res.size());
        ans=max(temp,ans);
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
    if(n==0 || m==0)
    {
        cout<<"0\n";
        return 0;
    }
    vector<vector<char> > matrix(n,vector<char> (m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cin>>matrix[i][j];
    }
    cout<<maximalRectangle(matrix);
}
