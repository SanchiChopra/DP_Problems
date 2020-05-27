#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int kadane(int n, int a[]) {
    if(n == 1) return a[0];
    int max_so_far = a[0];
    int max_ending_here = 0;
    for(int i=0; i<n; i++) {
        max_ending_here = max_ending_here + a[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main()
 {
	int t,n,i;
	cin>>t;
	while(t--) {
	    cin>>n;
	    int a[n];
	    for(i=0; i<n; i++)
	        cin>>a[i];
	    cout<<kadane(n,a)<<endl;
	}
	return 0;
}
