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

 //The most optimal way is to get the result in O(N) time and O(1) space.
//In this the maxval will store the max value till that index and minval will have the minimum value till that index.
//The logic is that minval will have minimum of running product and current value, so will always have running product having only odd number of -ve elements and when other negative element
//will come we will swap minval and maxval so that set of two negatives are formed in maxval which will be max value till than,this will make sure that at any time maxval is max.
//we also use the logic that if a>b than -a<-b -> the sole reason for swapping.


int maxProduct(vector<int>& nums)
{
    int n=nums.size();
        int minval=1,maxval=1,ans=-11;
        for(int i=0;i<n;i++){
            if(nums[i]<0)             //whenever -ve value comes in nums swap maxval and minval as if a>b than -a<-b
                swap(maxval,minval);
            maxval=max(maxval*nums[i],nums[i]);  //maxval will get the maximum of running product and the current value
            minval=min(minval*nums[i],nums[i]);  //minval will get the minimum of running product and current value
            ans=max(ans,maxval);                 //stores the maximum value at each step
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

	int n;
    cin>>n;
    vector<int> v(n);
    for(auto& i:v)
        cin>>i;
    cout<<maxProduct(v);
}
