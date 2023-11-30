# include <iostream>

using namespace std;

long long get_knight_positions(long long k){
    return (k * k) * (k*k-1) / 2 - 4 * (k - 1) * (k - 2);
}

int main(){
    int n;

    cin >> n;

    for(int i=1; i<=n; i++){
        cout << get_knight_positions(i) << endl;
    }

}