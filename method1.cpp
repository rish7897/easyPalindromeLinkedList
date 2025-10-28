#include<iostream>
#include<vector>
using namespace std;


// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    vector<ListNode*> heads;
    ListNode* curr = head;
    while(curr != NULL){
        heads.push_back(curr);
        curr = curr->next;
    }
    int start = 0;
    int end = heads.size() - 1;
    while(start < end){
        if(heads[start]->val != heads[end]->val){
            return false;
        }
        start++;
        end--;
    }
    return true;
}