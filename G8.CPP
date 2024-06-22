// TOLOLOGICAL SORT(BFS)

#include<iostream>
#include <unordered_map>
#include<list>
#include<map>
#include<queue>
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

void topoBFS(int n){
queue<int> q;
vector<int> ans;
map<int,int> indegree;

for(auto i:adj){
    for(auto j:adj[i.first]){
        indegree[j]++;
    }
}
cout<<endl;
for(int i=0;i<n;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}
cout<<"printing indegree"<<endl;
for(int i=0;i<indegree.size();i++){
    cout<<indegree[i]<<" ";
}
cout<<endl;
while(!q.empty()){
    int front=q.front();
    q.pop();
    cout<<front<<", ";
    // either print or store in vector it will also help us to check if the graph is cyclic or not
    ans.push_back(front);
    for(auto i:adj[front]){
        indegree[i]--;
        
        if(indegree[i]==0){
            q.push(i);
        }
    }
}

if(ans.size()==n){
    cout<<"graph is not cyclic";
}
else{
    cout<<"graph is cyclic";
}
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
g.topoBFS(n);

    return 0;
}