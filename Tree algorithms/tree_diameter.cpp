#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
#define vi vector<int>
using namespace std;

vi t[200001];
int h[200001], d[200001];

int height(int cur, int p){
    if(!t[cur].size()) return 0;
    for(auto child: t[cur]){
        if(child!=p){
            h[cur] = max(h[cur], 1 + height(child, cur));
        }
    }
    return h[cur];
}

int diameter(int cur, int p){
    vi hts;
    
    for(auto child: t[cur]){
        if(child!=p){
            diameter(child, cur);
            d[cur] = max(d[cur], d[child]);
            hts.push_back(h[child]);
        }
    }
    
    sort(hts.begin(), hts.end(), greater<int>());
    int s = hts.size();
    
    if(s>=2)
        d[cur] = max(d[cur], hts[0]+hts[1]+2);
    else if(s==1)
        d[cur] = max(d[cur], hts[0]+1);
    else d[cur] = 0;
    
    return d[cur];
}

int main() {
    int n, a, b;
    cin >> n;
    
    for(int i=1; i<n; i++){
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    
    height(1, -1);
    cout << diameter(1, -1);
    
    return 0;
}

