#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> lookup;
int countop(int p, int q, string str1, string str2) {
    if(p == 0) return q;
    if(q == 0) return p;
    string key = to_string(p)+"|"+to_string(q);
    if(lookup.find(key) != lookup.end())
        return lookup[key];
    int count = 0;
    if(str1[p-1] == str2[q-1])
        count += countop(p-1, q-1, str1, str2);
    else
        count = 1+min(min(countop(p-1,q,str1,str2), countop(p,q-1,str1,str2)), countop(p-1,q-1,str1,str2));
    lookup[key] = count;
    return count;
}
int main()
 {
	int t,p,q;
	cin>>t;
	while(t--) {
	    cin>>p>>q;
	    string str1, str2;
	    cin>>str1>>str2;
	    lookup.clear();
	    cout<<countop(p,q,str1,str2)<<endl;
	}
	return 0;
}
