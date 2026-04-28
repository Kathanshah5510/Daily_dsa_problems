#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n, x;
    cin >> m >> n >> x;

    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<int> arr;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr.push_back(grid[i][j]);
        }
    }

    int base = arr[0];
    for(int val : arr){
        if((val - base) % x != 0){
            cout << -1 << endl;
            return 0;
        }
    }

    sort(arr.begin(), arr.end());
    int median = arr[arr.size() / 2];
    int ct = 0;
    for(int val : arr){
        ct += abs(val - median) / x;
    }

    cout << ct << endl;

    return 0;
}