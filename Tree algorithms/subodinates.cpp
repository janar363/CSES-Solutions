#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
vector<int> t[200001];
int h[200001], d[200001];


void cal(int cur, int p, vector<int>& ans){
    for(auto child: t[cur]){
        cal(child, cur, ans);
        ans[cur] += ans[child] + 1;
    }
}

int main() {
    int n, temp;
    cin >> n;
    
    vector<int> ans(n+1, 0);
    for(int i=2; i<=n; i++){
        cin >> temp;
        t[temp].push_back(i);
    }
    
    cal(1, 0, ans);
    
    for(int i=1; i<=n; i++)
        cout << ans[i] << " ";
    return 0;
}
