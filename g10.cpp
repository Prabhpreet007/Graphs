#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

class Graph {
public:
unordered_map<int,list<pair<int,int>>> adj;
// pair<int,int> this is becoz we need to save the node and its weight also

void addedge(int u,int v,int wt,int direction){
if(direction==1){
adj[u].push_back({v,wt});
}
else{
adj[u].push_back({v,wt});
adj[v].push_back({u,wt});
}
}

void printadj(){
    for(auto i:adj){
        cout<<i.first<<"-> ";
        for(auto j:i.second){
            cout<<"{ "<<j.first<<","<<j.second<<"} ,";
        }
        cout<<endl;
    }
}

void findTopo(int src,unordered_map<int,bool> &vis,stack<int> &st){
vis[src]=true;

for(auto nbr:adj[src]){
    if(!vis[nbr.first]){
        findTopo(nbr.first,vis,st);
    }
}
st.push(src);
}

void shortpathTopo(stack<int> &st,int n){
vector<int>dist(n,INT_MAX);
int front=st.top();
st.pop();
dist[front]=0;

for(auto i:adj[front]){
    int node=i.first;
    int nodeDist=i.second;
    if(nodeDist+dist[front]<dist[node]){
        dist[node]=nodeDist+dist[front];
    }
}

while(!st.empty()){
    int front=st.top();
    st.pop();

    for(auto i:adj[front]){
    int node=i.first;
    int nodeDist=i.second;
    if(nodeDist+dist[front]<dist[node]){
        dist[node]=nodeDist+dist[front];
    }
}
}
for(auto i:dist){
    cout<<i<<" ";
}
}

};


int main(){

Graph g;
g.addedge(0,1,5,1);
g.addedge(0,2,3,1);
g.addedge(2,1,2,1);
g.addedge(2,3,5,1);
g.addedge(2,4,6,1);
g.addedge(1,3,3,1);
g.addedge(4,3,1,1);

g.printadj();
cout<<endl;

int src=0;
stack<int> st;
unordered_map<int,bool> vis;
g.findTopo(src,vis,st);

// while(!st.empty()){
//     cout<<st.top()<<" ";
//     st.pop();
// }
cout<<endl;
int n=5;
g.shortpathTopo(st,n);

    return 0;
}