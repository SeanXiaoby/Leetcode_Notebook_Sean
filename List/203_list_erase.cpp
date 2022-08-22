#include<iostream>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        ListNode* cur = head, *pre = nullptr;
        while(cur != nullptr){
            if(cur->val == val){
                if(pre!=nullptr){
                    pre->next = cur->next;
                }else{
                    head = cur->next;
                }
                ListNode* temp = cur->next;
                delete cur;
                cur = temp;
            }else{
                pre = cur;
                cur = pre->next;
            }
            
        }
        return head;
    }
};


// int main(){

// }