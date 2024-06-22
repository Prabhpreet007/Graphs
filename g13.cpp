// floyd warshall (at last detect cycle)
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>

using namespace std;


class graph{
public:
unordered_map<int,list<pair<int,int>>> adjList;

void addEdge(int u,int v,int wt,int direction){
// direction=1 -> undirected
// direction=0 -> directed

if(direction==0){
    adjList[u].push_back({v,wt});
    adjList[v].push_back({u,wt});
}
else{
    adjList[u].push_back({v,wt});
}
}

void print(){
    for(auto a:adjList){
        cout<<a.first<<" = ";
        for(auto b:a.second){
            cout<<"{ "<<b.first<<","<<b.second<<" } ,";
        }
        cout<<endl;
    }
}

void floydWarshall(int n){

vector<vector<int>> dist (n,vector<int>(n,1e9));

for(int i=0;i<n;i++){
    dist[i][i]=0;
}

for(auto i:adjList){
    for(auto j:i.second){
        int u=i.first;
        int v=j.first;
        int wt=j.second;
        dist[u][v]=wt;
    }
}

for(int helper=0;helper<n;helper++){
    for(int src=0;src<n;src++){
        for(int destination=0;destination<n;destination++){
            dist[src][destination]=min(dist[src][destination],dist[src][helper]+dist[helper][destination]);
        }
    }
}
 
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<dist[i][j]<<" ";
    }
    cout<<endl;
}


}


};

int main(){

graph g1;
g1.addEdge(0,1,3,1);
g1.addEdge(1,0,2,1);
g1.addEdge(0,3,5,1);
g1.addEdge(1,3,4,1);
g1.addEdge(3,2,2,1);
g1.addEdge(2,1,1,1);
//g1.print();
cout<<endl;
g1.floydWarshall(4);


    return 0;
}