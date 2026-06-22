#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    unordered_map<char, int> freq;
    for(auto& i : s){
        freq[i]++;
    }
    int count = min({freq['b'], freq['a'], freq['l']/2, freq['o']/2, freq['n']});
    cout << "The number of 'balloon' made from the string is/are: " << count << endl;

    return 0;
}