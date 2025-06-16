# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode(0)
        current = dummy_head
        carry = 0  # 进位

        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            total = val1 + val2 + carry
            carry = total // 10
            digit = total % 10

            current.next = ListNode(digit)
            current = current.next

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return dummy_head.next
    
# 完整的加法过程：
# 假设计算 342 + 465：
#   3 4 2
# + 4 6 5
# -------

# 第1位：2 + 5 = 7，carry=0，digit=7
# 第2位：4 + 6 = 10，carry=1，digit=0  
# 第3位：3 + 4 + 1(进位) = 8，carry=0，digit=8

# 结果：807