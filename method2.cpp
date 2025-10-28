#include<iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseLinkedList(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next;
    if(curr == NULL){
        next == NULL;
    }else{
        next = curr->next;
    }
    while(curr != NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(curr != NULL){
            next = curr->next;
        }
    }
    head = prev;
    return head;
}
    
bool isPalindrome(ListNode* head) {
    
    // finding size of linked list
    int size = 0;
    ListNode* curr = head;
    while(curr != NULL){
        size++;
        curr = curr->next;
    }
    
    ListNode node;
    ListNode* head1 = head;
    ListNode* head2;
    
    // finding mid node
    int mid = (size - 1) / 2;
    curr = head;
    for(int i = 0; i < mid; i++){
        curr = curr->next;
    }
    if(size % 2 == 0){
        head2 = curr->next;
    }else{
        node.val = curr->val;
        node.next = curr->next;
        head2 = &node;
    }
    curr->next = NULL;
    
    // reverse second half
    head2 = reverseLinkedList(head2);
    
    // checking palindrome
    while(head1 != NULL){
        if(head1->val != head2->val){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}