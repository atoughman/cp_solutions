// problem link
// https://leetcode.com/problems/sort-list/description/

class Solution {
public:
    void merge(ListNode* left, ListNode* right, int right_count) {
        ListNode* lp = left;
        while(lp != right and right_count) {
            if(lp->next->val > right->next->val) {
                ListNode* tmp = right->next;
                right->next = tmp->next;
                tmp->next = lp->next;
                lp->next = tmp;
                --right_count;
            }
            ListNode* trav = left->next;

            lp = lp->next;
        }
    }

    void merge_sort(ListNode* head, int l, int r) {
        if(l == r) return;
        int mid = l + (r-l)/2;

        // VERY IMP : First call this
        merge_sort(head, l, mid);

        // VERY IMP : Then calculate right pointer
        ListNode* right = head;
        int ct = l;
        while(ct <= mid) {
            right = right->next;
            ++ct;
        }
        // then call this
        merge_sort(right, mid+1, r);
        
        // then merge
        merge(head, right, r-mid);

        // iff
        /*
            you will calculate right pointer first,
            then call
            merge_sort(head, l, mid);  [ PART 1 ]
            merge_sort(right, mid+1, r);
            (which we usually do),
            this may lead to right pointer getting itself sorted when we call first part
            Which will result in incorrect result.

            HOW the improved code work? why it doesn't update there.
            coz we send it as a left pointer, and left pointer are never part of
            sorting, accoring to implementation. they act as dummy node.
        */

    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        int l = 1;
        int r = 1;
        ListNode* trav = head;
        while(trav->next) {
            trav = trav->next;
            ++r;
        }
        trav = new ListNode(); // dummy node inserted in starting of linked list
        trav->next = head;
        merge_sort(trav, l, r);
        return trav->next;
    }
};