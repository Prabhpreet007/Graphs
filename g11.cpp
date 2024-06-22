// dijkstra algo
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<limits.h>
#include<set>
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
// void dijkstaShortestPath(int src,int dest,int n){
// vector<int> dist(n+1,INT_MAX);
// set<pair<int,int>> st;

// st.insert({0,src});
// dist[src]=0;
// while(!st.empty()){
//     auto frontNode=st.begin();
//     pair<int,int> srcPair=*frontNode;
//     int srcDist=srcPair.first;
//     int srcNode=srcPair.second;

//     st.erase(st.begin());

//     for(auto nbr:adj[srcNode]){
//         // adj me {node,dist} ese hai and 
//         // st me {dist,node} hai
//         int nbrNode=nbr.first;
//         int nbrDist=nbr.second;
//         if(nbrDist+srcDist<dist[nbrNode]){
//             auto prevEntry=st.find({nbrDist,nbrNode});
//             if(prevEntry!=st.end()){
//                 // present hai erase kro and new wla add kro
//                 st.erase(prevEntry);
//             }
//             dist[nbrNode]=nbrDist+srcDist;
//             st.insert({dist[nbrNode],nbrNode});
//         }

//     }

// }
// cout<<"the dist from "<<src<<" to "<<dest<<" is "<<dist[dest]<<endl;


// }

void dijkstaShortestPath(int src,int dest,int n){
vector<int> dist(n+1,INT_MAX);
set<pair<int,int>> st;

dist[src]=0;
st.insert({0,src});
// esko nikalo and nbr pe jao saare

while(!st.empty()){
    auto frontNode=st.begin();
    pair<int,int> srcPair=*frontNode;

    int srcDist=srcPair.first;
    int srcNode=srcPair.second;
    st.erase(frontNode);

    for(auto nbr:adj[srcNode]){
        int nbrNode=nbr.first;
        int nbrDist=nbr.second;

        if(nbrDist+srcDist<dist[nbrNode]){
            // dist[nbrNode] implies that aap koi or path se aye ho pehle agr yes toh check kro ki wo dist kam hai current path ke dist se
            auto previousNode=st.find({nbrDist,nbrNode});
            if(previousNode!=st.end()){
                // milgya erase kro
                st.erase({nbrDist,nbrNode});
            }
            dist[nbrNode]=srcDist+nbrDist;
            st.insert({dist[nbrNode],nbrNode});
        }
    }
}
cout<<"the dist from "<<src<<" to "<<dest<<" is "<<dist[dest]<<endl;

}

};


int main(){

Graph g;
g.addedge(1,6,14,0);
g.addedge(1,3,9,0);
g.addedge(1,2,7,0);
g.addedge(2,3,10,0);
g.addedge(2,4,15,0);
g.addedge(3,4,11,0);
g.addedge(6,3,2,0);
g.addedge(6,5,9,0);
g.addedge(5,4,6,0);
g.printadj();
cout<<endl;
int src=6;
int dest=4;
int n=6;
g.dijkstaShortestPath(src,dest,n);

    return 0;
}