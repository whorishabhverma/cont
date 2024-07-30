/*
//1
int find(int i,vector<int> &parent){
    if(i==parent[i]) return i;
    return find(parent[i],parent);
}
void union(int x,int y,vector<int> &parent){
    int x_parent = find(x,parent);
    int y_parent = find(y,parent);
    if(x_parent != y_parent){
        parent[x_parent]=y_parent;
    }
}


video : 2
//isme problem ye h ki tree bht bda hota to recursion baar baar call hoga find krne ke liye  -> solution union by rank and path compression


// path compression
class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    
    //parent.resize();
    //rank.resize(V,0);
    
    DSU(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    
    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};

*/