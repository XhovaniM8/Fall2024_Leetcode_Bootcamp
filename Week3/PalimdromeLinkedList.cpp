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
class Solution
{
public:
    // Helper function to reverse a linked list
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
        {
            return true; // Empty or single-node list is a palindrome
        }

        // Step 1: Find the middle of the linked list using slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        ListNode *secondHalfStart = reverseList(slow);

        // Step 3: Compare the first and second half of the list
        ListNode *firstHalfStart = head;
        ListNode *secondHalfCopy = secondHalfStart; // For restoring the list later (optional)
        bool isPalin = true;
        while (secondHalfStart != nullptr)
        {
            if (firstHalfStart->val != secondHalfStart->val)
            {
                isPalin = false;
                break;
            }
            firstHalfStart = firstHalfStart->next;
            secondHalfStart = secondHalfStart->next;
        }

        // Step 4 (Optional): Restore the list by reversing the second half back
        reverseList(secondHalfCopy);

        return isPalin;
    }
};