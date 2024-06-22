// bellman ford (at last detect cycle)
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>

using namespace std;


class graph{
public:
unordered_map<char,list<pair<char,int>>> adjList;

void addEdge(char u,char v,int wt,int direction){
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
void bellman(int n,char src){
vector<int> dist(n,INT_MAX);                
dist[src-'A']=0;

for(int i=1;i<n;i++){
    // n-1 times chlao esko

    for(auto a:adjList){
        for(auto b:a.second){
            char u=a.first;
            char v=b.first;
            int wt=b.second;
            if(dist[u-'A']!=INT_MAX && dist[u-'A']+wt<dist[v-'A']){
        // dist[u]!=INT_MAX this is coz agr dist[u] INT_MAX hua toh fir int ki range se bhar chla jyega 
                dist[v-'A']=dist[u-'A']+wt;
            }
        }
    }
}
// yaha tk hamare paas shortest path aagya hai now check cycle 
bool flag=false;
    for(auto a:adjList){
        for(auto b:a.second){
            char u=a.first;
            char v=b.first;
            int wt=b.second;
            if(dist[u-'A']!=INT_MAX && dist[u-'A']+wt<dist[v-'A']){
                flag=true;
                break;
        // dist[u]!=INT_MAX this is coz agr dist[u] INT_MAX hua toh fir int ki range se bhar chla jyega 
                dist[v-'A']=dist[u-'A']+wt;
            }
        }
    }

    if(flag){
        cout<<"cycle present ";
    }
    else{
        cout<<"no cycle "<<endl<<"printing the distance array "<<endl;
        for(auto i:dist){
            cout<<i<<", ";
        }cout<<endl;

    }

}

};

int main(){

graph g1;
g1.addEdge('A','B',-1,1);
g1.addEdge('B','E',2,1);
g1.addEdge('E','D',-3,1);
g1.addEdge('D','C',5,1);
g1.addEdge('A','C',4,1);
g1.addEdge('B','C',3,1);
g1.addEdge('B','D',2,1);
g1.addEdge('D','B',1,1);
g1.print();
cout<<endl;
g1.bellman(5,'A');


    return 0;
}