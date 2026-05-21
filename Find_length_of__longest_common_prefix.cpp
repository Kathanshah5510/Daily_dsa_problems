#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 3, m = 1;
    // cin >> n >> m;

    vector<int> arr1(n), arr2(m);
    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < m; i++) cin >> arr2[i];

    vector<string> str1, str2;
    for(int x : arr1) str1.push_back(to_string(x));
    for(int x : arr2) str2.push_back(to_string(x));

    int maxlength = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int len = 0;
            int limit = min(str1[i].size(), str2[j].size());
            for(int k = 0; k < limit; k++){
                if(str1[i][k] != str2[j][k]) break;
                len++;
                maxlength = max(maxlength, len);
            }
        }
    }
    cout << maxlength << endl;


    return 0;
}