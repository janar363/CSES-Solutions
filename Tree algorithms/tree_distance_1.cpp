#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
#define vi vector<int>
#define pb push_back
using namespace std;

vi t[200001];
bool visited[200001];
int h[200001], d[200001];
int di[200001][2];

void depth(int cur, int p){
    for(auto child: t[cur]){
        if(!visited[child] && child!=p){
            d[child] = 1 + d[cur];
            depth(child, cur);
        }
    }
}

void dfs(int cur, int p, int end){
    for(auto child: t[cur]){
        if(!visited[child] && child!=p){
            di[child][end] = 1 + di[cur][end];
            dfs(child, cur, end);
        }
    }
    
}



int main() {
    int n, a, b;
    cin >> n;
    
    for(int i=1; i<n; i++){
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    
    //cal depths of nodes
    depth(1, -1);
    
    int end1, end2, m=0;
    
    // extract max depth node
    for(int i=1; i<=n; i++){
        if(d[i]>m){
            m=d[i];
            end1=i;
        }
    }
    
    //dfs from the max depth node which is on one side of the diameter
    di[end1][0] = 0;
    dfs(end1, -1, 0);
    
    m = 0;
    //extract node on the other side of diameter with max depth
    for(int i=1; i<=n; i++){
        if(di[i][0]>m){
            m=di[i][0];
            end2=i;
        }
    }
    
    //dfs from other node of the diameter
    di[end2][1] = 0;
    dfs(end2, -1, 1);
    
    for(int i=1; i<=n; i++)
        cout <<  max(di[i][0], di[i][1]) << " ";
    
    return 0;
}
