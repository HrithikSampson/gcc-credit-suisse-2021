#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int a,b,f,s,t;
unordered_map<string,int> pos;
unordered_map<int,int> dept;
class Group{
    public:
    int total;
    int f;
    int s;
    int t;
    Group(){
        this->total = 0;
        this->f = 0;
        this->s = 0;
        this->t = 0;
    }
    Group operator+(Group g2){
         Group g;
         g.total = this->total + g2.total;
         g.f = this->f + g2.f;
         g.s = this->s + g2.s;
         g.t = this->t + g2.t;
         return g; 
    }
    bool operator>(Group g){
        return this->total>g.total;
    }
    bool operator!(void){
        return !total;
    }
};
bool compare(Group g1,Group g2,int b,int f,int s,int t){
    return ((g1.f+g2.f)<=f) && ((g1.s+g2.s)<=s) && ((g1.t+g2.t)<=t) && ((g1.total+g2.total)<=t);     
}



class disjoint_sets{
    public:
    int* parent;
    Group rank[10001];
    disjoint_sets(int n){
        parent = new int[n+1]; //0  is dummy
        int i;
        for(i=1;i<=n;i++){
            parent[i] = -1;
        }
    }
    int find(int x){
        if(parent[x] == -1){
            return x;
        }
        return (parent[x] = find(parent[x]));//path compression
    }
    void unite(int x,int y,int b,int f,int s,int t){
        static int time = 1;
        int set1parent = find(x);
        int set2parent = find(y);
        //cout<<"set1parent:"<<set1parent<<" for iter:"<<(time++)<<" set2parent:"<<set2parent<<endl;
        if(!rank[set1parent]){
            parent[x] = set2parent;
            Group g;
            g.total = 1;
            if(dept[x]==1){
                g.f++;
            } 
            else if(dept[x]==2){
                g.s++;
            }
            else{
                g.t++;
            }
            if(compare(rank[set1parent],rank[set2parent],b,f,s,t)){
                rank[set1parent] = g;
            
                rank[set2parent] = rank[set2parent] + rank[set1parent];
            }
            //cout<<"SINGLE UNION"<<endl;
            return;
        }
        if(!rank[set2parent]){
            parent[y] = set1parent;
            Group g;
            g.total = 1;
            if(dept[y]==1){
                g.f++;
            } 
            else if(dept[y]==2){
                g.s++;
            }
            else{
                g.t++;
            }
            if(compare(rank[set1parent],rank[set2parent],b,f,s,t)){
                rank[set2parent] = g;
                rank[set1parent] = rank[set1parent] + rank[set2parent];
            }
            //cout<<"SINGLE UNION"<<endl;
            return;
        }
        
        if(set1parent == set2parent){
            return;
        }
        if(!compare(rank[set1parent],rank[set2parent],b,f,s,t)){
            //cout<<"NOT POSSIBLE"<<endl;
            return;
        }
        if(rank[set1parent] > rank[set2parent]){
            parent[set2parent] = set1parent;
            rank[set1parent] = rank[set1parent] + rank[set2parent];
        }
        else{
            parent[set1parent] = set2parent;
            rank[set2parent] = rank[set2parent] + rank[set1parent];
        }//unionbyrank
    }
};

void theHackathon(int n, int m, int a, int b, int f, int s, int t) {
    // Participant code here
    disjoint_sets d(n);
    int i,dept_id;
    string s0,s1,s2;
    for(i=0;i<n;i++){
        cin>>s0;
        cin>>dept_id;
        pos[s0] = i+1;
        dept[pos[s0]] = dept_id;
    }
    for(i=0;i<m;i++){
        cin>>s1>>s2;
        d.unite(pos[s1],pos[s2],b,f,s,t);
        
    }
    int max = INT_MIN;
    int max_i = 0; 
    for(i=1;i<=n;i++){
        int ty = d.rank[i].total;
        if(ty > max){
            max = ty;
            max_i = i;
        }
    }
    set<int> elem;
    for(i=1;i<=n;i++){
        if(d.find(i) == max_i){
            elem.insert(i);
        }
    }
    //cout<<"SIZE:"<<(int)elem.size()<<endl;
    set<string> ans;
    for(auto p:pos){
        if(elem.find(p.second) != elem.end()){
            ans.insert(p.first);
        }
    }
    if(ans.size()>=a){
        for(auto se:ans){
            cout<<se<<endl;
        }
    }
    else{
        cout<<"no groups"<<endl;
    }
    return;
    
}

int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);

    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
