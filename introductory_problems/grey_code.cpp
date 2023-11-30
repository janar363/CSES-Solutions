# include<iostream>
# include<vector>

using namespace std;


vector<string> get_grey_code(int n){
    vector<string> grey_code;

    if(n == 1){

        grey_code.push_back("0");
        grey_code.push_back("1");


        return grey_code;
    }

    grey_code = get_grey_code(n-1);

    int endIdx = grey_code.size()-1;

    for(int i=endIdx; i>=0; i--){
        grey_code.push_back("1"+grey_code[i]);
        grey_code[i] = "0"+grey_code[i];
    }

    return grey_code;
}

int main(){
    int n; 

    cin >> n;

    for(auto code: get_grey_code(n)){
        cout << code << "\n";
    }
}