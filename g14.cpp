// KOSARAJU (VERY INPORTANT) STRONGLY CONNECTED COMPONENTS 

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
#include<stack>

using namespace std;


class Graph{
public:
unordered_map<int,list<int>> adjList;

void addEdge(int u,int v,int direction){
// direction=1 -> undirected
// direction=0 -> directed

if(direction==0){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
else{
    adjList[u].push_back(v);
}
}

void dfs1(int src,stack<int> &ordering,unordered_map<int,bool>& vis1){
vis1[src]=true;

for(auto nbr:adjList[src]){
    if(!vis1[nbr]){
        dfs1(nbr,ordering,vis1);
    }
}
ordering.push(src);
}

void dfs2(int src,unordered_map<int,bool>& vis2,unordered_map<int,list<int>>& adjNew){
vis2[src]=true;

for(auto i:adjNew[src]){
        if(!vis2[i]){
            dfs2(i,vis2,adjNew);
        
    }
}
}

int getStronglyConnectedComponents(int n){

unordered_map<int,bool>vis1;
stack<int> ordering;
for(int i=0;i<n;i++){
if(!vis1[i]){
    dfs1(i,ordering,vis1);
}
}
// reverse all edges
unordered_map<int,list<int>> adjNew;
for(auto i:adjList){
    for(auto x:i.second){
        int u=i.first;
        int v=x;
        adjNew[v].push_back(u);
    }
}

unordered_map<int,bool>vis2;

int count=0;
while(!ordering.empty()){
    int front=ordering.top();
    ordering.pop();
    if(!vis2[front]){
                count++;

        dfs2(front,vis2,adjNew);
    }
}
return count;
}
};

int main(){

Graph g;
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 0, 1);

	g.addEdge(2, 4, 1);

	g.addEdge(4, 5, 1);
	g.addEdge(5, 6, 1);
	g.addEdge(6, 4, 1);

	g.addEdge(6, 7, 1);
	int n = 8;
  int ans = g.getStronglyConnectedComponents(n);
  cout << "SCC Count: " << ans << endl;


    return 0;
}