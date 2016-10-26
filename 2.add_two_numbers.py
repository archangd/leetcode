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
        (temp, count) = (temp, 0) if temp < 10 else (temp - 10, 1)
        ret = ListNode(temp)
        walk = ret

        l1 = l1.next
        l2 = l2.next
        while l1 is not None:
            if l2 is None:
                l2 = l1
                break
            temp = l1.val + l2.val + count

            (temp, count) = (temp, 0) if temp < 10 else (temp - 10, 1)
            walk.next = ListNode(temp)
            walk = walk.next

            l1 = l1.next
            l2 = l2.next

        while l2 is not None:
            temp = l2.val + count
            (temp, count) = (temp, 0) if temp < 10 else (temp - 10, 1)
            walk.next = ListNode(temp)
            walk = walk.next
            l2 = l2.next

        if count == 1:
            walk.next = ListNode(1)

        return ret
