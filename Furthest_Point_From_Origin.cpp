#include <bits/stdc++.h>
using namespace std;

int main(){
    string moves;
    cin >> moves;
    // int distance = 0;
    // int left = 0, right = 0, cnt = 0;
    // int distance = 0;
        // int left = 0, right = 0, cnt = 0;
        // for(int i = 0; i < moves.size(); i++){
        //     if(moves[i] == 'L'){
        //         left++;
        //     }
        //     else if(moves[i] == 'R'){
        //         right++;
        //     }
        //     else{
        //         cnt++;
        //     }
        // }
        // for(auto &i : moves){
        //     if(left >= right){
        //         if(i == '_'){
        //             i == 'L';
        //         }
        //     }
        //     else{
        //         if(i == '_'){
        //             i == 'R';
        //         }
        //     }
        // }
        // for(auto &i : moves){
        //     if(i == 'L'){
        //         distance += -1;
        //     }
        //     else if(i == 'R'){
        //         distance += 1;
        //     }
        //     else continue;
        // }

    int left = 0, right = 0, blank = 0;

    for (auto &i : moves) {
        if (i == 'L') left++;
        else if (i == 'R') right++;
        else blank++;
    }

    int ans = abs(right - left) + blank;
    cout << ans;
    // cout << endl;
}