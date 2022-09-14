using namespace std;
#include <string>
#include <iostream>

string solution(string n){
    // code here
    int i,m,max1=0,max2=0,current_len = 0;
    
    m = n.length();
    for(i=0;i<m;){
    //cout<<i<<endl;
        if(n[i]=='1'){
            i = i + 1;
            continue;
        }
        current_len = 0;
        while(n[i]=='0'){
            current_len++;
            i++;
            
        }
        if(current_len>max1){
            max2 = max1;
            max1 = current_len;
        }
        else if(current_len>max2){
            max2 = current_len;
        }
    }
    if(max1%2==0){
        return "B";
    }
    else{
        if((max1+1)/2>max2){
            return "A";
        }
        else{
            return "B";
        }
    }
    return "B";
}

/*  Do not edit below code */
int main() {
	string  n;
	cin >> n;	
    string answer=solution(n);
	cout << answer << endl;	
}
