#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2) {
    int earlistFinish = INT_MAX;
    for(int i = 0; i < start1.size(); i++){
        earlistFinish = min(earlistFinish, start1[i] + duration1[i]);
    }

    int ans = INT_MAX;
    for(int i = 0; i < start2.size(); i++){
        int finishTime = max(earlistFinish, start2[i])+ duration2[i];
        ans = min(ans, finishTime);
    }

    return ans;
}

int main(){
    int n, m;
    cout << "Enter the number of land rides: ";
    cin >> n;
    cout << "Enter the number of water rides: ";
    cin >> m;

    vector<int> land(n), landDuration(n), water(m), waterDuration(m);
    cout << "Enter the start times of land rides: ";
    for (int i = 0; i < n; i++) {
        cin >> land[i];
    }
    cout << "Enter the durations of land rides: ";
    for (int i = 0; i < n; i++) {
        cin >> landDuration[i];
    }
    cout << "Enter the start times of water rides: ";
    for (int i = 0; i < m; i++) {
        cin >> water[i];
    }
    cout << "Enter the durations of water rides: ";
    for (int i = 0; i < m; i++) {
        cin >> waterDuration[i];
    }
    cout << endl;

    int result1 = solve(land, landDuration, water, waterDuration);
    int result2 = solve(water, waterDuration, land, landDuration);
    cout << "Earlist finish time: " << min(result1, result2) << endl;
    
    return 0;
}