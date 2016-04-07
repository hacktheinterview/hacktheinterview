class Solution:
    def sortListUsingInsertionSort(self, head):
        if not head or not head.next:
            return head

        newHead = ListNode(head.val)
        pointer = head.next

        while pointer != None:
            innerPointer = newHead
            nextNode = pointer.next

            if pointer.val <= newHead.val:
                oldHead = newHead
                newHead = pointer
                newHead.next = oldHead
            else:
                while innerPointer.next != None:
                    if pointer.val > innerPointer.val and pointer.val <= innerPointer.next.val:
                        oldNext = innerPointer.next
                        innerPointer.next = pointer
                        pointer.next = oldNext

                    innerPointer = innerPointer.next;

                if innerPointer.next == None and pointer.val > innerPointer.val:
                    innerPointer.next = pointer
                    pointer.next = None

            pointer = nextNode

        return newHead
