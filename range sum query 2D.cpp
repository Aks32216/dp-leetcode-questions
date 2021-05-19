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

vector<vector<int> > mat;
void prefix(vector<vector<int>>& matrix) 
{
	mat.resize(matrix.size(),vector<int>(matrix[0].size()+1,0));
	for(int i=0;i<matrix.size();++i)
	{
		for(int j=0;j<matrix[i].size();++j)
		{
			mat[i][j+1]+=mat[i][j]+matrix[i][j];
		}
	}

	for(int i=0;i<mat.size();++i)
	{
		for(int j=0;j<mat[i].size();++j)
			cout<<mat[i][j]<<" ";
		cout<<"\n";
	}

}

int sumRegion(int row1, int col1, int row2, int col2) 
{
	int sum=0;
	for(int i=row1;i<=row2;++i)
	{
		sum+=(mat[i][col2+1]-mat[i][col1]);
	}
	return sum;
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
    vector<vector<int> > v(n,vector<int>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cin>>v[i][j];
    }
    prefix(v);
    int  q,a,b,c,d;
    cin>>q;
    while(q--)
    {
    	cin>>a>>b>>c>>d;
    	cout<<sumRegion(a,b,c,d)<<"\n";
    }
}
