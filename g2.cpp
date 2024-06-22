// add and print elements of adjacency list with weights
#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class Graps{
public:

unordered_map<int,list<pair<int,int>>> adjlist;
void add(int u,int v,int wt,bool direction){
// if direction is 1 then the graph is directed means there is only one path i.e from u to v
if(direction==1){
adjlist[u].push_back({v,wt});
}
else{
    // here direction is 0 means the path will be fron u->v and v->u as the graph is undirected
    adjlist[u].push_back({v,wt});
    adjlist[v].push_back({u,wt});

}

}

void print(){
    for(auto i:adjlist){
        cout<<i.first<<" -> {";
        for(pair<int,int> p:i.second){
            cout<<" { "<<p.first<<", "<<p.second<<" },";
        }
        cout<<"}";
        cout<<endl;
    }
}

};

int main(){
    Graps g;
    g.add(0,1,5,1);
    g.add(0,2,3,1);
    g.add(0,3,7,1);
    g.add(1,4,6,0);
    g.print();


    return 0;
}