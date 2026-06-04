#include <bits/stdc++.h>
using namespace std;

int waviness(int num){
    string s = to_string(num);
    int count = 0;
    for(int i = 1; i < s.size() - 1; i++){
        if(s[i] > s[i-1] && s[i] > s[i+1]) count++;
        else if(s[i] < s[i-1] && s[i] < s[i+1]) count++;
    }
    return count;
}

int main(){
    int num1, num2;
    cout << "Enter the range (num1 num2): ";
    cin >> num1 >> num2;
    int ans = 0;
    for(int i = num1; i <= num2; i++){
        ans += waviness(i);
    }
    cout << "The waviness from " << num1 << " to " << num2 << " is: " << ans << endl;
    
    return  0;
}