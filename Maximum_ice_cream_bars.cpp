#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, coins;
    cout << "Enter the number of ice cream bars: ";
    cin >> n;
    cout << "Enter the number of coins available: ";
    cin >> coins;
    vector<int> costs(n);
    cout << "Enter the costs of the ice cream bars: ";
    for(int i = 0; i < n; i++){
        cin >> costs[i];
    }
    int count = 0;
    sort(costs.begin(), costs.end());
    for(int i = 0; i < n; i++){
        if(coins - costs[i] < 0){
            break;
        }
        else{
            coins -= costs[i];
            count++;
        }
    }
    cout << "Maximum number of ice cream bars that can be bought: " << count << endl;
    return 0;
}