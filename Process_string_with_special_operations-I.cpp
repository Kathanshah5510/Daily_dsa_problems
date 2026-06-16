#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    string res;
    for(char ch : s) {

        if(ch >= 'a' && ch <= 'z') {
            res.push_back(ch);
        }
        else if(ch == '*') {
            if(!res.empty())
                res.pop_back();
        }
        else if(ch == '#') {
            res += res;
        }
        else if(ch == '%') {
            reverse(res.begin(), res.end());
        }
    }
    cout << "Processed string: " << res << endl;

    return 0;
}