#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

int main(){
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<int> values(n);
    cout << "Enter the values of the nodes: ";
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    Node* head = new Node(values[0]);
    Node* temp = head;
    for(int i = 1; i < n; i++){
        temp->next = new Node(values[i]);
        temp = temp->next;
    }

    vector<int> nums;
    while(head){
       nums.push_back(head->data);
        head = head->next;
    }

    int ans = 0;
    for(int i = 0; i < nums.size()/2; i++){
        ans = max(ans, nums[i] + nums[nums.size()-1-i]);
    }
    cout << "Maximum twin sum: " << ans << endl;

    return 0;
}