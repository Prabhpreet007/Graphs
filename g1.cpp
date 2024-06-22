// add and print elements of adjacency list
#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class Graps{
public:

unordered_map<int,list<int>> adjlist;
void add(int u,int v,bool direction){
// if direction is 1 then the graph is directed means there is only one path i.e from u to v
if(direction==1){
adjlist[u].push_back(v);
}
else{
    // here direction is 0 means the path will be fron u->v and v->u as the graph is undirected
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);

}

}

void print(){
    for(auto i:adjlist){
        cout<<i.first<<" -> {";
        for(auto neighbour:i.second){
            cout<<neighbour<<", ";
        }
        cout<<"}";
        cout<<endl;
    }
}

};

int main(){
    Graps g;
    g.add(0,2,1);
    g.add(1,2,1);
    g.add(2,1,1);
    g.add(3,2,1);
    g.add(0,1,1);
    g.add(0,4,0);
    g.print();


    return 0;
}