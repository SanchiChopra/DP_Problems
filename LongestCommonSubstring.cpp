#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>lookup;
int lcsubstring(int n,int m,string x, string y,int res) {
    if(n == 0 || m == 0) return res;
    string key = to_string(n) + "|" + to_string(m)+ "|"+ to_string(res);
    if(lookup.find(key) != lookup.end())
        return lookup[key];
    if(x[n-1] == y[m-1]) 
        res = lcsubstring(n-1,m-1,x,y,res+1);
    res = max(res, max(lcsubstring(n,m-1,x,y,0),lcsubstring(n-1,m,x,y,0))); 

    lookup[key] = res;
    return res;
}
int main()
 {
	int t,n,m,i;
	cin>>t;
	while(t--) {
	    cin>>n>>m;
	    string x,y;
	    cin>>x;
	    cin>>y;
	    lookup.clear();
	    cout<<lcsubstring(n,m,x,y,0)<<endl;
	}
	return 0;
}
