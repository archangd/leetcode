# Definition for singly-linked list.

# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        temp = l1.val + l2.val
        count = int(temp / 10)
        ret = ListNode(int(temp % 10))
        walk = ret

        l1 = l1.next
        l2 = l2.next
        while True:
            try:
                temp = l1.val + l2.val + count
            except:
                if l2 is None:
                    l2 = l1
                break

            count = int(temp / 10)
            walk.next = ListNode(int(temp % 10))
            walk = walk.next

            l1 = l1.next
            l2 = l2.next

        # while l2 is not None:
        while True:
            try:
                temp = l2.val + count
            except:
                if count == 1:
                    walk.next = ListNode(1)
                return ret
            count = int(temp / 10)
            walk.next = ListNode(int(temp % 10))
            walk = walk.next
            l2 = l2.next
