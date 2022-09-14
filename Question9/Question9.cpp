#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<vector<vector<int>>> ans;
void allPermutationRecursive(vector<vector<int>>& v,int i,int n){
    if(i>n)
    {
        ans.push_back(v);
        return;
    }
    for(int j=i;j<=n;j++){
        swap(v[i],v[j]);
        allPermutationRecursive(v,i+1,n);
        // backtracking to restore the original array
        swap(v[i],v[j]);
    }
}
int helper(int b,int idx,vector<vector<int>>& dp,vector<vector<int>>& x){

    if(idx == (int) x[0].size()){
        return 0;
    }
    if(b==(int)x.size()){
        return INT_MAX/2;
    }
    if(dp[b][idx]!=INT_MAX){
        return dp[b][idx];
    }
    //cout<<min((helper(b,idx+1,dp,x)+x[b][idx]),helper(b+1,idx,dp,x))<<endl;
    return (dp[b][idx] = min((helper(b,idx+1,dp,x)+x[b][idx]),helper(b+1,idx,dp,x)));
}
int bankersAndClients(int c, int b,vector< vector<int> > &time) {
// Complete the bankersAndClients function .
    int n= (int)time.size();
    allPermutationRecursive(time,0,b-1);
    //cout<<endl;
    vector<vector<int>> dp(b+1,vector<int>(c+1,INT_MAX));
    int minm = INT_MAX;
    for(vector<vector<int>> x:ans){
        for(auto y:dp){
            for(auto z:y){
                z = INT_MAX;
            }
        }     
        minm = min(minm,helper(0,0,dp,x));
        /*
        cout<<endl;
        for(auto y:dp){
            for(auto z:y){
                cout<<z<<" ";
            }
            cout<<endl;
        } 
        cout<<endl;
        */
        
    }
    return minm;
  

}

int main(){
    int b,c;
    cin >> c>>b;
    int answer;
    vector<vector<int>> time(b,vector<int>(c));
    for(int i = 0; i < b; i++){
        
        for(int j = 0;j < c;j++){
          cin>>time[i][j];
        }
    }
	answer = bankersAndClients(c,b,time);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}
