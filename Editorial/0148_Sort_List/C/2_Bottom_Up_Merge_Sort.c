typedef struct ListNode ListNode;

// Function to count the number of nodes in the linked list.
int getCount(ListNode *head) {
    int cnt = 0;
    ListNode *ptr = head;
    while (ptr != NULL) {
        ptr = ptr->next;
        cnt++;
    }
    return cnt;
}

// Function to split the list into two parts.
ListNode *split(ListNode *start, int size, ListNode **nextSubList) {
    ListNode *midPrev = start;
    ListNode *end = start->next;
    // Use fast and slow approach to find middle and end of second linked list
    for (int index = 1; index < size && (midPrev->next != NULL ||
                                         (end != NULL && end->next != NULL));
         index++) {
        if (end != NULL && end->next != NULL) {
            end = (end->next->next != NULL) ? end->next->next : end->next;
        }
        if (midPrev->next != NULL) {
            midPrev = midPrev->next;
        }
    }
    ListNode *mid = midPrev->next;
    midPrev->next = NULL;
    *nextSubList = end != NULL ? end->next : NULL;
    if (end != NULL) end->next = NULL;
    // Return the start of second linked list
    return mid;
}

// Function to merge two linked lists.
void merge(ListNode **tailRef, ListNode *list1, ListNode *list2) {
    ListNode dummyHead;
    ListNode *newTail = &dummyHead;
    dummyHead.next = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            newTail->next = list1;
            list1 = list1->next;
        } else {
            newTail->next = list2;
            list2 = list2->next;
        }
        newTail = newTail->next;
    }
    newTail->next = (list1 != NULL) ? list1 : list2;
    // Traverse till the end of merged list to get the newTail
    while (newTail->next != NULL) {
        newTail = newTail->next;
    }
    // Link the old tail with the head of merged list
    (*tailRef)->next = dummyHead.next;
    // Update the old tail to the new tail of merged list
    *tailRef = newTail;
}

struct ListNode *sortList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    int n = getCount(head);
    ListNode *start = head;
    ListNode dummyHead;
    dummyHead.next = NULL;
    ListNode *tail, *nextSubList;

    for (int size = 1; size < n; size *= 2) {
        tail = &dummyHead;
        while (start != NULL) {
            if (start->next == NULL) {
                tail->next = start;
                break;
            }
            ListNode *mid = split(start, size, &nextSubList);
            merge(&tail, start, mid);
            start = nextSubList;
        }
        start = dummyHead.next;
    }
    return dummyHead.next;
}
