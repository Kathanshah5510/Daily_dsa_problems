#include <bits/stdc++.h>
using namespace std;    

int main(){
    string word;
    cout << "Enter the word to type: ";
    cin >> word;
    int ans = 0;
    for(int i = 0; i < word.size(); i++)
        ans += i / 8 + 1;
    cout << "Minimum number of pushes to type the word: " << ans << endl;

    return 0;
}