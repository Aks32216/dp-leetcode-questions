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

 unordered_set<string> word_set;                                             

  // Return true if a match is found with multiple words starting from index idx till the end of the word.  
  bool recurse(const string& word, int idx, int num_components, vector<int>& cache) {               
    if (idx == word.length()) {
      // Making sure the word was composed of multiple components else every word
      // will match with itself.  
      return num_components > 1;                                                                    
    }
    // Memoization  
    if (cache[idx] != -1) {                                                                         
      return cache[idx] == 1;                                                                       
    }                                                                                               
    ostringstream s;                                                                                
    for (int i = idx; i < word.length(); i++) {                                                     
      s << word[i];                                                                                 
      if (word_set.count(s.str()) != 0) {
        // If the suffix matches then we have a match from idx till the end.  
        if (recurse(word, i + 1, num_components + 1, cache)) {                                      
          cache[idx] = 1;                                                                           
          return true;                                                                              
        }                                                                                           
      }                                                                                             
    }
    // No matches found for suffix from 'idx' till end.
    cache[idx] = 0;                                                                                 
    return false;                                                                                   
  }                                                                                                 
                                                                                                                                                                                                
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {                           
    word_set.insert(words.begin(), words.end());                                                    
                                                                                                    
    vector<string> result;                                                                          
    for (const auto& word : words) {
      // Initialize the cache with -1.  
      vector<int> cache(word.size(), -1);                                                           
      if (recurse(word, 0, 0, cache)) {                                                             
        result.push_back(word);                                                                     
      }                                                                                             
   }                                                                                                
                                                                                                    
    return result;                                                                                  
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
	vector<string> s(n);
	for(auto& i:s)
		cin>>i;
	cout<<"\n";
	vector<string> res;
	res=findAllConcatenatedWordsInADict(s);
	for(int i=0;i<res.size();++i)
		cout<<res[i]<<" ";
}
