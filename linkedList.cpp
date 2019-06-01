#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, const int & carry = 0) {
        if(!l1 && !l2 && !carry) return NULL;
        
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        int sum = (v1 + v2 + carry) % 10;
        int nC = (v1 + v2 + carry) / 10;
        
        ListNode * cur = new ListNode(sum);
        cur->next = addTwoNumbers(l1 ? l1->next : NULL, l2 ? l2->next : NULL, nC);
        return cur;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2) return NULL;
        
        ListNode * cur = new ListNode(0);
        int &val = cur->val;
        
        if(!l1) val = l2->val, l2 = l2->next;
        else if(!l2) val = l1->val, l1 = l1->next;
        else {
            if(l1->val < l2->val) val = l1->val, l1 = l1->next;
            else val = l2->val, l2 = l2->next;
        }
        cur->next = mergeTwoLists(l1, l2);
        return cur;
    }
};

int main() {
    
}

