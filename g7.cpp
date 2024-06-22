// TOLOLOGICAL SORT(DFS)

#include<iostream>
#include <unordered_map>
#include<list>
#include<map>
#include<stack>
using namespace std;

class graph{
public:
unordered_map<int,list<int>> adj;

void add(int u,int v,int direction){
    // 1 is directed 
    // 0 is undirected
if(direction==1){
adj[u].push_back(v);
}
else{
adj[u].push_back(v);
adj[v].push_back(u);
}
}

void print(){
    for(auto i:adj){
        cout<<i.first<<" : {";
        for(auto j:i.second){
            cout<<j<<", ";
        }
        cout<<"}"<<endl;
    }
}

void toposort(int src,map<int,bool>& vis,stack<int>& st){
    vis[src]=true;

    for(auto i:adj[src]){
        if(!vis[i]){
            toposort(i,vis,st);
        }
    }
    st.push(src);
}
};

int main(){
graph g;
g.add(0,1,1);
g.add(1,2,1);
g.add(2,3,1);
g.add(3,4,1);
g.add(3,5,1);
g.add(4,6,1);
g.add(5,6,1);
g.add(6,7,1);

g.print();
int n=8;
map<int,bool> vis;
stack<int> st;

for(int i=0;i<n;i++){
    if(!vis[i]){
        g.toposort(i,vis,st);
    }
}

cout<<endl;
while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}
    return 0;
}