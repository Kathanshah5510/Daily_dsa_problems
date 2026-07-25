#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int first = 0, second = 0;
    while(n > 0){
        int digit = n % 10;
        if(digit >= first){
            second = first;
            first = digit;
        }
        else if(digit > second){
            second = digit;
        }
        n /= 10;
    }
    cout << "Maximum product of two digits is: " << first*second << endl;

    return 0;
}