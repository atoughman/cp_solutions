// problem link
// https://leetcode.com/problems/swap-nodes-in-pairs/description/

// swap values
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode* ans = head;

        while(head and head->next) {
            ListNode* right = head->next;
            swap(head->val, right->val);
            head = right->next;
        }

        return ans;
    }
};

// swap nodes
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode* prev_head = NULL;
        ListNode* ans = head->next;

        while(head and head->next) {
            ListNode* right = head->next;
            head->next = right->next;
            right->next = head;
            if(prev_head) prev_head->next = right;
            prev_head = head; 
            head = head->next;
        }

        return ans;
    }
};