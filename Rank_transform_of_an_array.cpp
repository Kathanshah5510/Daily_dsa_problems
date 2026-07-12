#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    unordered_map<int, int> rank;
    int currRank = 1;
    for (int x : temp) {
        if (rank.find(x) == rank.end()){
            rank[x] = currRank++;
        }
    }

    for (int i = 0; i < arr.size(); i++){
        arr[i] = rank[arr[i]];
    }

    cout << "The rank transformed array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}