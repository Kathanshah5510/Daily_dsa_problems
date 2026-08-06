#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cout << "Enter two integers: ";
    cin >> n >> t;
    for(int x = n;; x++){
        int temp = x;
        int product = 1;
        while(temp > 0){
            int digit = temp % 10;
            product *= digit;
            temp /= 10;
        }
        if(product % t == 0){
            cout << x;
            break;
        }
    }
}