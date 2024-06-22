// BFS(This won't work for disconnected graph)

#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>

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

void bfs(T source){
queue<T> q;
unordered_map<T,bool> mp;
q.push(source);
mp[source]=true;

while(!q.empty()){
T newnode=q.front();
q.pop();
cout<<newnode<<" ";
for(auto nbr:adjlist[newnode]){
    T newdata=nbr.first;
    if(!mp[newdata]){
        q.push(newdata);
        mp[newdata]=true;
    }

}
}
}
};

int main(){

    Graps<char> g;
    g.add('a','b',5,0);
    g.add('a','c',3,0);
    g.add('b','c',7,0);
    g.add('b','d',6,0);
    g.add('c','e',6,0);
    g.add('c','f',6,1);
    g.add('e','f',6,1);
    g.print();
    g.bfs('a');


    return 0;
}