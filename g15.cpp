// PRIM'S ALGORITHM
// GFG MINIMUM SPANNING TREE
class Solution
{
	public:
	int FindMin(vector<int> key,vector<bool> MST){
	    int mini=INT_MAX;
	    int index=-1;
	    for(int i=0;i<key.size();i++){
	        if(key[i]<mini && MST[i]==false){
	            mini=key[i];
	            index=i;
	        }
	    }
	    return index;
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V,INT_MAX);
        vector<bool> MST(V,false);
        vector<int> parent(V,-1);
        
        key[0]=0;
        
        while(true){
            int u=FindMin(key,MST);
            if(u==-1)break;
            
            MST[u]=true;
            
            for(auto i:adj[u]){
                int node=i[0];
                int wt=i[1];
                if(MST[node]==false && key[node]>wt){
                    key[node]=wt;
                    parent[node]=u;
                }
            }
            
        }
        int sum=0;
        for(int i=0;i<V;i++){
            sum+=key[i];
        }
        return sum;
    }
};