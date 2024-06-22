// shortest path(BFS) undirected graph

// TOLOLOGICAL SORT(BFS)

#include<iostream>
#include <unordered_map>
#include<list>
#include<map>
#include<queue>
#include<algorithm>
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

void short_path(int src,int dest){
vector<int> ans;
map<int,int> parent;
map<int,bool> vis;

queue<int> q;
q.push(src);
parent[src]=-1;
vis[src]=true;

while(!q.empty()){
    int front=q.front();
    q.pop();
    for(auto nbr:adj[front]){
        if(!vis[nbr]){
            vis[nbr]=true;
            parent[nbr]=front;
            q.push(nbr);
        }
    }
}
while(dest!=-1){
ans.push_back(dest);
dest=parent[dest];
}
reverse(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
}


};

int main(){
graph g;
g.add(0,5,0);
g.add(5,4,0);
g.add(4,3,0);
g.add(0,6,0);
g.add(6,3,0);
g.add(0,1,0);
g.add(1,2,0);
g.add(2,3,0);
int src=0;
int dest=3;
g.short_path(src,dest);

    return 0;
}