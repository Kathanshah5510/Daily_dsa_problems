#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    // Find the maximum element in the array
    int maxElement = *max_element(nums.begin(), nums.end());
    
    // Decrease all elements to be less than or equal to maxElement
    for (int i = 0; i < n; i++){
        if (nums[i] > maxElement)
            nums[i] = maxElement;
    }
    
    // Rearranging the array in non-increasing order
    sort(nums.begin(), nums.end(), greater<int>());
    
    cout << "Maximum element after decreasing and rearranging: " << nums[0] << endl;
    
    return 0;
}