#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lookup[1001][1001];
int knapsack(int n, int w, int val[], int weights[]) {
    if(w == 0 || n<0) return 0;
    if(w<0) return INT_MIN;
    if(lookup[n][w])
        return lookup[n][w];
    int include = knapsack(n,w - weights[n],val,weights) + val[n];
    int exclude = knapsack(n-1,w,val,weights);
    lookup[n][w] = max(include, exclude);
    return lookup[n][w];
}
int main()
 {
	int t,n,w,i;
	cin>>t;
	while(t--) {
	    cin>>n>>w;
	    int val[n];
	    int weights[n];
	    for(i=0; i<n; i++)
	        cin>>val[i];
	    for(i=0; i<n; i++)
	        cin>>weights[i];
	    memset(lookup,0,sizeof(lookup));
	    cout<<knapsack(n-1,w,val,weights)<<endl;
	}
	return 0;
}
