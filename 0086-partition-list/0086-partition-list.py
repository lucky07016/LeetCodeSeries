class Solution:
    def partition(self, head, x):
        smallDummy = ListNode(0)
        largeDummy = ListNode(0)

        small = smallDummy
        large = largeDummy

        while head:

            if head.val < x:
                small.next = head
                small = small.next
            else:
                large.next = head
                large = large.next

            head = head.next

        large.next = None
        small.next = largeDummy.next

        return smallDummy.next