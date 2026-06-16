struct ListNode* getMid(struct ListNode* head);
struct ListNode* merge(struct ListNode* list1, struct ListNode* list2);

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* mid = getMid(head);
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);
    return merge(left, right);
}

struct ListNode* merge(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummyHead;
    struct ListNode* ptr = &dummyHead;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            ptr->next = list1;
            list1 = list1->next;
        } else {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }
    ptr->next = list1 ? list1 : list2;
    return dummyHead.next;
}

struct ListNode* getMid(struct ListNode* head) {
    struct ListNode* midPrev = NULL;
    while (head && head->next) {
        midPrev = (midPrev == NULL) ? head : midPrev->next;
        head = head->next->next;
    }
    struct ListNode* mid = midPrev->next;
    midPrev->next = NULL;
    return mid;
}
