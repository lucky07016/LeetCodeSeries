class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split list
        ListNode* right = slow->next;
        slow->next = nullptr;

        ListNode* left = head;

        // Sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge sorted halves
        return merge(left, right);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        if (l1 != nullptr) {
            curr->next = l1;
        }

        if (l2 != nullptr) {
            curr->next = l2;
        }

        return dummy.next;
    }
};