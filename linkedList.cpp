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


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class SolutionCopyRandomList {
unordered_map<Node *, Node *> m;
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node * cur = new Node(head -> val, NULL, head->random);
        m[head] = cur;
        cur->next = copyRandomList(head->next);
        
        if(cur->random) cur->random = m[cur->random];
        return cur;
    }
};

class SolutionCopyRandomListOptimal {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node * l1, * l2, * newHead;
        for(l1 = head; l1; l1 = l1->next) {
            l2 = new Node(l1->val, l1->random, NULL);
            l1->random = l2;
        }
        newHead = head->random;
        for(l1 = head; l1; l1 = l1->next) {
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : NULL;
        }

        for(l1 = head; l1; l1 = l1->next) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ?l1->next->random : NULL;
        }
        return newHead;
        
    }
};

class SolutionEasyOptimalCopyRandomList {
public:
    Node* copyRandomList(Node* head) {
        for(auto l1 = head; l1; l1 = l1->next->next) {
            auto tmp = l1->next;
            l1->next = new Node(l1->val, tmp, NULL);
        }
        Node * newHead = head ? head->next : NULL;
        for(auto l1 = head; l1; l1 = l1->next->next) {
            if(l1->random) l1->next->random = l1->random->next;
        }
        for(auto l1 = head; l1; l1 = l1->next) {
            auto l2 = l1->next;
            if(l2) l1->next = l2->next;
            if(l2->next) l2->next = l2->next->next;
        }
        return newHead;
    }
};

class SolutionReverseList {
public:
    ListNode* reverseList(ListNode* head, ListNode* prev = NULL) {
        auto cur = head && head->next ? reverseList(head->next, head) : head;
        if(head) head->next = prev;
        return cur;
    }
};

class SolutionOptimalReverseList {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = NULL;
        for(auto l1 = head; l1;) {
            auto tmp = l1->next;
            l1->next = prev;
            prev = l1;
            l1 = tmp;
        }
        return prev;
    }
};

int main() {
    
}

