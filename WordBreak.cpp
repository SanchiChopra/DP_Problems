#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>lookup;
bool wordbreak(vector<string> dict, string input) {
    int l = input.size();
    if(l == 0) return true;
    string key = to_string(l);
    if(lookup.find(key) != lookup.end())
        return lookup[key];
    lookup[key] = false;
    for(int i=1; i<=l; i++) {
        string prefix = input.substr(0,i);
        if((find(dict.begin(), dict.end(), prefix) != dict.end()) && (wordbreak(dict,input.substr(i))))
        {   
            lookup[key] = true;
            return lookup[key];
        }
    }
    return lookup[key];
}
int main()
 {
	int t,n,i;
	cin>>t;
	while(t--) {
	    cin>>n;
	    string x;
	    vector<string> dict(n);
	    for(i=0; i<n; i++) {
	        cin>>x;
	        dict[i] = x;
	    }
	    string input;
	    cin>>input;
	    lookup.clear();
	    bool ans = wordbreak(dict,input);
	    if(ans) cout<<"1"<<endl;
	    else cout<<"0"<<endl;
	}
	return 0;
}
