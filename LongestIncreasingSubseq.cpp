#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>m;
int lis(int i, int n, int arr[], int prev) {
    if(i >= n) return 0;
    string key = to_string(i) + "|" + to_string(prev);
    if(m.find(key) != m.end())
        return m[key];
    if(m.find(key) == m.end()) {
        int exc = lis(i+1,n,arr,prev);
        int inc = 0;
        if(arr[i] > prev) {
            inc = 1 + lis(i+1,n,arr,arr[i]);
        }
        m[key] = max(inc,exc);
    }
    return m[key];
}
int main()
 {
	int t,n,i;
	cin>>t;
	while(t--) {
	    cin>>n;
	    int arr[n];
	    for(i=0; i<n; i++)
	        cin>>arr[i];
	    m.clear();
	    cout<<lis(0,n,arr,INT_MIN)<<endl;
	}
	return 0;
}
