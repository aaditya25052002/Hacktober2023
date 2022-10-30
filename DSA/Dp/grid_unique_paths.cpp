#include<bits/stdc++.h>
using namespace std;

// Unique path with memoization i.e. top-down dp
// Time Complexity :- O(m*n)
// Space Complexity :- O(m*n) + Auxiliary Space
int uniquePathsMemoization(int m,int n,vector<vector<int>> &dp){
    if(m==0 || n==0){
        return 1;
    }
    if(dp[m][n]!=-1) return dp[m][n];
    return dp[m][n] = uniquePathsMemoization(m,n-1,dp) + uniquePathsMemoization(m-1,n,dp);
}

// Unique path with tabulation i.e. bottom-up dp
// Time Complexity :- O(m*n)
// Space Complexity :- O(m*n)
int uniquePathsTabulation(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0) dp[i][j]=1;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

// Unique path with tabulation
// Time Complexity :- O(m*n)
// Space Complexity :- O(n)
int uniquePathsSpaceOptimized(int m, int n) {
    vector<int> dp(n,0);
    for(int i=0;i<m;i++){
        vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            if(i==0) temp[j]=1;
            else if (j==0) temp[j] = dp[j];
            else temp[j] = dp[j] + temp[j-1];
        }
        dp = temp;
    }
    return dp[n-1];
}

int uniquePaths(int m, int n) {
    // vector<vector<int>> dp(m,vector<int>(n,-1));
    // return uniquePathsMemoization(m,n,dp)
    // return uniquePathsTabulation(m,n);
    return uniquePathsSpaceOptimized(m-1,n-1);
}

int main(){
	int n,m;
	cin>>n>>m;
	cout<<uniquePaths(m,n)<<endl;
	return 0;
}