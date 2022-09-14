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
int totalPairs(int n, vector<int>& values) {
    // Complete the total pairs function
    stack<int> s;
    int i,count=0;
    for(i=0;i<n;i++){
        while(!s.empty() && s.top()<values[i]){
            s.pop();
        }
        if(!s.empty()){
            count++;
        }
        s.push(values[i]);
    }
    stack<int> q;
    for(i=n-1;i>=0;i--){
        while(!q.empty() && q.top()<values[i]){
            q.pop();
        }
        if(!q.empty()){
            count++;
        }
        q.push(values[i]);
    }
    return count;
}

int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
	int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}
