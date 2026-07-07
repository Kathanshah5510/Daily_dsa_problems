#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cout << "Enter a number: ";
    cin >> n;
    string s = to_string(n);
    long long x = 0;
    int sum = 0;
    for(char c : s){
        if(c != '0'){
            x = x * 10 + (c - '0');
            sum += (c - '0');
        }
    }
    cout << "Result of multiplication: " << x * sum << endl;

    return 0;
}