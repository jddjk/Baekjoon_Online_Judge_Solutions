#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> words;
int n, k;
int ans = 0;
int alpha = 0;
int learned = 0;

void backtrack(int idx, int cnt){
    if(cnt == k){
        int read = 0;
        for(int i = 0; i < n; i++){
            bool canRead = true;
            for(char ch : words[i]){
                if((learned & (1 << (ch - 'a'))) == 0){
                    canRead = false;
                    break;
                }
            }
            if(canRead) read++;
        }
        ans = max(ans, read);
        return;
    }
    
    for(int i = idx; i < 26; i++){
        if(!(learned & (1 << i))){
            learned += (1 << i);
            backtrack(i+1, cnt+1);
            learned -= (1 << i);
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        words.push_back(word.substr(4, word.size() - 8));
        for(char ch : words[i]){
            alpha |= (1 << (ch - 'a'));
        }
    }
    
    if(k < 5){
        cout << 0 << "\n";
        return 0;
    }
    else if(k == 26){
        cout << n << "\n";
        return 0;
    }

    learned |= (1 << ('a' - 'a'));
    learned |= (1 << ('n' - 'a'));
    learned |= (1 << ('t' - 'a'));
    learned |= (1 << ('i' - 'a'));
    learned |= (1 << ('c' - 'a'));
    k -= 5;
    
    backtrack(0, 0);

    cout << ans << "\n";

    return 0;
}
