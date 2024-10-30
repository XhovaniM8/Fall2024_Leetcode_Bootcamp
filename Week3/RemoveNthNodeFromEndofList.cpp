class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Create a dummy node to handle edge cases where the head needs to be removed
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // Initialize two pointers
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        // Move the fast pointer n+1 steps ahead to maintain the gap
        for (int i = 0; i <= n; ++i)
        {
            fast = fast->next;
        }

        // Move both fast and slow pointers until fast reaches the end
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Slow is now at the node just before the one to be deleted
        ListNode *nodeToDelete = slow->next;
        slow->next = slow->next->next; // Remove the nth node

        // Free the memory of the deleted node (optional in languages like C++)
        delete nodeToDelete;

        // Return the new head (which could be different if we deleted the original head)
        ListNode *newHead = dummy->next;
        delete dummy; // Free the dummy node
        return newHead;
    }
};
