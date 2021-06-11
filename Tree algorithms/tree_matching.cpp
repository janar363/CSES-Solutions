#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

vector<int> t[200001];
int h[200001], d[200001];
int dp[200001][2];

void matching(int cur, int p){
    int sum = 0;
    
    
    for(auto child: t[cur]){
        if(child!=p){
        matching(child, cur);
        dp[cur][0] += max(dp[child][0], dp[child][1]);
        }
    }
    
    for(auto child: t[cur]){
        if(child!=p){
        sum = max((1 + dp[child][0] + dp[cur][0] - max(dp[child][0], dp[child][1])), sum);
        }
    }
    
    dp[cur][1] = sum;
    
}
//1-> 2 3
//2->
//3->4 5
//
int main() {
    int n, a, b;
    cin >> n;
    
    for(int i=1; i<n; i++){
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    
    matching(1, -1);
    cout << max(dp[1][0], dp[1][1]);
    
    return 0;
}
