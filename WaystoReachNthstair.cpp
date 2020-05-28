#include<iostream>
using namespace std;
int dp[100000]={0};
int m=1000000007;
int no_of_ways(int n){
    if(dp[n]!=0)
    return dp[n];
    
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%m;
    }
    return dp[n];
}

int main()
 {
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<no_of_ways(n)<<endl;
	}
	return 0;
}
