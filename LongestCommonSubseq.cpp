#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>lookup;
int lcs(int a, int b, string str1, string str2) {
    if(a == 0 || b == 0) return 0;
    string key = to_string(a) + "|" + to_string(b);
    if(lookup.find(key) != lookup.end())
        return lookup[key];
    int res;
    if(str1[a-1] == str2[b-1]) 
        res = 1 + lcs(a-1,b-1,str1,str2);
    else
        res = max(lcs(a,b-1,str1,str2), lcs(a-1,b,str1,str2));
    lookup[key] = res;
    return res;
}
int main()
 {
    int t,a,b,i;
    cin>>t;
    while(t--) {
        cin>>a>>b;
        string str1,str2;
        cin>>str1;
        cin>>str2;
        lookup.clear();
        cout<<lcs(a,b,str1,str2)<<endl;
    }
	return 0;
}
