#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of the costs: ";
    cin >> n;
    vector<int> costs(n);
    int n = costs.size();
    cout << "Enter the cost of candies: ";
    for(int i = 0; i < n; i++){
        cin >> costs[i];
    }

    sort(costs.rbegin(), costs.rend());
    int money = 0;
    for(int i = 0; i < n; i++){
        if((i+1) % 3 != 0){
            money += costs[i];
        }
    }

    cout << "The total cost is: " << money << endl;
}