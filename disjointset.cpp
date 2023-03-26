#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
      vector<int> rank,parent,size;
      public:
      DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] =i;
            size[i]=1;
        }
      }
      int findupar(int node){
        if(node==parent[node]){
            return node;
        } 
        return parent[node] = findupar(parent[node]);
      }
      void unionbyRank(int u, int v){
        int ulp_u = findupar(u);

        int ulp_v = findupar(v);
        if(ulp_u == ulp_v){
            return ;
        }
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
      }
      void unionbySize(int u, int v){
        int ulp_u = findupar(u);

        int ulp_v = findupar(v);
        if(ulp_u == ulp_v){
            return ;
        }
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
              parent[ulp_v] = ulp_u;
              size[ulp_u] +=size[ulp_v];
        }
      }
};
int main(){
    DisjointSet ds(7);
    ds.unionbyRank(1,2);
    ds.unionbyRank(2,3);
    ds.unionbyRank(4,5);
    ds.unionbyRank(6,7);
    ds.unionbyRank(5,6);
    if(ds.findupar(3)== ds.findupar(7)){
        cout<<"SAME\n";

    }
    else{
        cout<<"NOT SAME"<<"\n";
    }
    ds.unionbyRank(3,7);
    return 0;
}