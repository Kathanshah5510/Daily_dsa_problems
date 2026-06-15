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
    if(n == 1){
        cout << "The linked list has only one node. No middle node to delete." << endl;
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    cout << "Linked list after deleting the middle node: ";
    temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}