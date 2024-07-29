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

int find(int i,vector<int> &parent){
    if(i==parent[i]) return i;
    return parent[i] = find(parent[i],parent);
}
//by rank
void union(int x,int y,vector<int>&parent,vector<int>&rank){
    int x_parent = find(x,parent);
    int y_parent = find(y,parent);
    if(x_parent == y_parent) return;
    if(rank[x_parent] > rank[y_parent]){
        parent[y_parent] = x_parent;
    }
    else if(rank[x_parent] < rank[y_parent]){
        parent[X_parent] = y_parent;

    }
    else{
        //kisi ko parent bnao and rank bdhao
        parent[X_parent] = y_parent;
        rank[y_parent]+=1;
    }
}

*/