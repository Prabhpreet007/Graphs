// add and print elements of adjacency list with weights and in generalized form (it will work for int,char etc)

#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

template<typename T>
class Graps{
public:

// weight will be always be in int
unordered_map<T,list<pair<T,int>>> adjlist;
void add(T u,T v,int wt,bool direction){
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
        for(pair<T,int> p:i.second){
            cout<<" { "<<p.first<<", "<<p.second<<" },";
        }
        cout<<"}";
        cout<<endl;
    }
}

};

int main(){
    // Graps<int> g;
    // g.add(0,1,5,1);
    // g.add(0,2,3,1);
    // g.add(0,3,7,1);
    // g.add(1,4,6,0);
    // g.print();

    Graps<char> g;
    g.add('a','b',5,1);
    g.add('b','c',3,1);
    g.add('a','c',7,1);
    g.add('c','a',6,1);
    g.print();


    return 0;
}