#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class SolutionAddTwoNumbers {
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
class SolutionMergeTwoLists {
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

// reverse linked lists my solution non optimal 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionReverseKGroup {
public:
    ListNode* reverseKGroup(ListNode* head, int k, const int & idx, queue<int> & q) {
        if(head == NULL) {
            if(idx % k != 0) q = queue<int>();
            return NULL;
        }
        
        queue<int> curQ = q;
        if(idx % k == 0) q = queue<int>();
        
        q.push(head->val);
        reverseKGroup(head->next, k, idx + 1, q);
        
        if(q.size()) {
            head->val = q.front();
            q.pop();
        }
        if(idx % k == 0) q = curQ;
        
        return head;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        queue<int> q = queue<int>();
        return reverseKGroup(head, k, 0, q);
    }
};

class SolutionOptimalReverseKGroup {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        queue<int> q = queue<int>();
        stack<ListNode *> s;
        ListNode * cur = head;
        while(cur != NULL) {
            int idx = 0;
            while(idx++ < k && cur) {
                s.push(cur);
                q.push(cur->val);
                cur = cur->next;
            }
            if(idx != k + 1) break;
            while(s.size()) { s.top()->val = q.front(); s.pop(), q.pop(); }
        }
        return head;
    }
};

class SolutionConstantMemReverseKGroup {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto cur = head;
        int cnt = 0;
        while(cnt < k && cur) { cur = cur->next, cnt++; }
        
        if(cnt == k) {
            cur = reverseKGroup(cur, k);
            while(cnt--) {
                auto tmp = head->next;
                head->next = cur, cur = head, head = tmp;
            }
            head = cur;
        }
        
        return head;
    }
};

class SolutionOptimalIterativeReverseKGroup {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto prev = dummy, tail = dummy, cur = dummy;
        while(true) {
            int cnt = 0;
            while(tail && cnt++ < k) tail = tail->next;
            if(!tail) break;
            head = prev->next;
            
            while(prev->next != tail) {
                cur = prev->next;
                prev->next = cur->next;
                
                cur->next = tail->next;
                tail->next = cur;
            }
            
            tail = prev = head;
        }
        return (*dummy).next;
    }
};

int main() {
    
}

