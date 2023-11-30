# include<iostream>
# include<vector>

using namespace std;

vector<pair<int, int> > moves;

int get_number_of_moves(int n){
    if(n == 1) return 1;

    return get_number_of_moves(n-1) * 2 + 1;
}

void make_moves(int n, int from, int to, int temp){
    // cout << "called make move\n";

    // return;
    if(n == 1){
        moves.push_back(make_pair(from, to));

        return;
    }

    // move n-1 from -> temp
    make_moves(n-1, from, temp, to);

    // move 1 from -> to
    make_moves(1, from, to, temp);

    // move n-1 temp -> to
    make_moves(n-1, temp, to, from);
    return;

    
}

int main(){
    int n;

    cin >> n;

    make_moves(n, 1, 3, 2);

    cout << moves.size() << endl;

    for(auto move: moves){
        cout << move.first << " " << move.second << endl;
    }

}