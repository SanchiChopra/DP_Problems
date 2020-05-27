#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>lookup;
bool dividesum(int n, int arr[], int sum) {
    if(sum == 0) return true;
    if(n<0 || sum<0) return false;
    
    string key = to_string(n) + "|" + to_string(sum);
    if(lookup.find(key) != lookup.end())
        return lookup[key];
    bool include = dividesum(n-1,arr, sum-arr[n]);
    if(include) { 
        lookup[key] = true; 
        return true;  
    }
    
    bool exclude = dividesum(n-1,arr,sum);
    lookup[key] = exclude;
    return exclude;
}
bool subsetsum(int n, int arr[]) {
   int sum=0;
   for(int i=0; i<n; i++)
    sum += arr[i];
   return !(sum & 1) && dividesum(n-1,arr,sum/2);
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
        lookup.clear();
        if(subsetsum(n,arr) == true)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
	return 0;
}
