
using namespace std;
#include <string>
#include <iostream>

int solution(int n){
    // code here
	int x= n/3;
	int ans = x*2;
	if(n%3){
		ans++;
	}
	return ans;
}

/*  Do not edit below code */
int main() {
	int n;
	cin >> n;	
    int answer=solution(n);
	cout << answer << endl;	
}
