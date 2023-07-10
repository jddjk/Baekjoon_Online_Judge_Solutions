#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> nums;
    vector<int> ops;
    int num = 0;
    int result = 0;
    bool minus = false;

    for(char ch : s){
        if(ch == '+' || ch == '-'){
            nums.push_back(num);
            num = 0;
            ops.push_back(ch);
        }
        else {
            num = num * 10 + (ch - '0');
        }
    }
    nums.push_back(num);

    for(int i = 0; i < ops.size(); i++){
        if(ops[i] == '-' || minus){
            result -= nums[i+1];
            minus = true;
        }
        else{
            result += nums[i+1];
        }
    }
    result += nums[0];

    cout << result;

    return 0;
}
