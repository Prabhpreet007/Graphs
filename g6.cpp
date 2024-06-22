// DFS(This will work for disconnected graph)

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

void dfs(T src,unordered_map<T,bool> &mp){

    mp[src]=true;
    cout<<src<<" ";

    for(auto i:adjlist[src]){
        T x=i.first;//dont directly for i just check for i.first
        if(mp[x]==false){
            dfs(x,mp);
        }
    }
}
};

int main(){
    Graps<char> g;
    g.add('a','b',5,0);
    g.add('b','c',3,0);

    g.add('d','e',7,0);

    g.add('f','g',6,0);
    g.add('g','g',6,0);

unordered_map<char,bool> mp;

    for(char i='a';i<='g';i++){
        if(mp[i]==false){
        g.dfs(i,mp);
        cout<<endl;
        }
    }

    // g.print();


    return 0;
}