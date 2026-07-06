#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b){
             if (a[0] == b[0])
                 return a[1] > b[1];
             return a[0] < b[0];
         });

    int count = 0;
    int maxEnd = -1;
    for (auto &it : intervals){
        if (it[1] > maxEnd){
            count++;
            maxEnd = it[1];
        }
    }
    cout << "The number of intervals that are not covered by any other interval is: " << count << endl;
    
    return 0;
}