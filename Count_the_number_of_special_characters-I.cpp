#include <bits/stdc++.h>
using namespace std;

int main(){
    string word;
    cout << "Enter a string: ";
    cin >> word;

    // unordered_map<char, int> freq;
    // for(auto c : word){
    //     freq[c]++;
    // }

    // int count = 0;
    // for(char ch = 'a'; ch <= 'z'; ch++){
    //     if(freq[ch] > 0 && freq[toupper(ch)] > 0){
    //         count++;
    //     }
    // }    
    // cout << "Number of special characters: " << count << endl;
    
    unordered_set<char> lower;
    unordered_set<char> upper;
    for(char ch : word){
        if(islower(ch)) lower.insert(ch);
        else upper.insert(ch);
    }

    int count = 0;
    for(char ch : lower){
        if(upper.count(toupper(ch))){
            count++;
        }
    }
    cout << "Number of special characters: " << count << endl;

    return 0;
}