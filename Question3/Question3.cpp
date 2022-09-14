  
#include <bits/stdc++.h>
using namespace std;
int helper(int idxA,int idxB,int k,vector<int>& a,vector<int>& b,vector<vector<int>>& dp){
    if(k<0){
        return 0;
    }
    if(idxA == (int)a.size() && idxB == (int)b.size()){
        return idxB+idxA;
    }
    if(idxA<(int)a.size() && idxB<(int)b.size() && dp[idxA][idxB]){
        return dp[idxA][idxB];
    }
    int left = (idxA<(int)a.size() && k>=a[idxA])?helper(idxA+1,idxB,k-a[idxA],a,b,dp):0;
    int right = (idxB<(int)b.size() && k>=b[idxB])?helper(idxA,idxB+1,k-b[idxB],a,b,dp):0;
    return (dp[idxA][idxB] = max({left,right,idxA+idxB}));
}
int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b) {
    //write your code here
    vector<vector<int>> dp((int)a.size()+1,vector<int>((int)b.size()+1,0));
    //cout<<helper(0,0,maxSum,a,b,dp)<<endl;
    return helper(0,0,maxSum,a,b,dp);

}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;
    int maxSum = x;
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(maxSum, a, b);
    cout << result;
    return 0;
}
