#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for(int num : nums){
        if(num >= max1){
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        else if(num >= max2){
            max3 = max2;
            max2 = num;
        }
        else if(num >= max3){
            max3 = num;
        }

        if(num <= min1){
            min2 = min1;
            min1 = num;
        }
        else if(num <= min2){
            min2 = num;
        }
    }

    int product1 = max1 * max2 * max3;
    int product2 = min1 * min2 * max1;
    cout << max(product1, product2) << endl;

    return 0;
}