#include<iostream>
using namespace std;

//Using Recursion
int ways(int n) {
    if(n == 0) {
        return 1;
    }
    if(n<0) {
        return 0;
    }

    int ans = ways(n-1) + ways(n-2) + ways(n-3);
    return ans;
}

//O( k^n )
int ways2(int n, int k) {
    if(n == 0) {
        return 1;
    }
    if(n<0) {
        return 0;
    }
    int ans = 0;
    for(int i=1; i<=k; i++) {
        ans = ways2(n-i, k);
    }
    return ans;
}

//Using Bottom-Up approach of the order O(nk)
int ways_BU(int n, int k) {
    int *dp = new int [n];
    dp[0] = 1;
    for(int step=1; step<=n; step++) {
        dp[step] = 0;
        for(int j=1; j<=k; j++) {
            if(step-j>=0) {
                dp[step] += dp[step-j];
            }
        }

    }
    return dp[n];
}
int main() {
    int n = 4;
    cout<<ways(n)<<endl;
    cout<<ways2(3,2)<<endl;
    cout<<ways2(4,3)<<endl;

    cout<<ways2(5,4)<<endl;
    cout<<ways_BU(5,4)<<endl;

    return 0;
}