#include <bits/stdc++.h>

using namespace std;
int calculateMaximizedReturns(int n, int k, int d, int m, vector<int> returns) {
    // Participant's code will go here
    int i,j,z;
    vector<vector<int>>dp(1003,vector<int>(1003,0));
    
        for(i=n-1;i>=0;i--){
        
    for(j=k-1;j>=0;j--){
            int sum = 0;
            int maxm = returns[i]+dp[i+1][j];
            //cout<<i+1<<"\t"<<j+1<<endl;
            for(z=1;z<=d;z++){
                if(i+z<(int)returns.size())
                    sum +=  returns[i+z]*m;
                //cout<<"sum: "<<sum<<"\tdp[i+z][j+1]: "<<dp[i+z][j+1]<<"\ti+z: "<<i+z<<"\tdp[i][j]: "<<dp[i][j]<<endl;
                maxm = max(maxm,dp[i+z+1][j+1]+sum);
                
            }
            
            dp[i][j] = maxm;
            //cout<<i<<"\t"<<j<<"\t:"<<dp[i][j]<<endl;
            
        }
    }
    return dp[0][0];
}

vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void printVector(vector<string> vec) {
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    string firstLine;
    getline(cin, firstLine);

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int n = firstLineVec[0];
    int k = firstLineVec[1];
    int d = firstLineVec[2];
    int m = firstLineVec[3];

    string returns;
    getline(cin, returns);

    vector<int> returnsVec = splitStringToInt(returns, ' ');

    int result = calculateMaximizedReturns(n, k, d, m, returnsVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
