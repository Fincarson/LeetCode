struct MRUQueueListNode {
    int value;
    MRUQueueListNode* next;

    MRUQueueListNode() : value(0), next(nullptr) {}
    MRUQueueListNode(int val) : value(val), next(nullptr) {}
};

class MRUQueue {
private:
    MRUQueueListNode* head;
    MRUQueueListNode* tail;

public:
    MRUQueue(int n) {
        head = new MRUQueueListNode();
        MRUQueueListNode* current = head;

        // Initialize the linked list with values from 1 to n
        for (int number = 1; number <= n; ++number) {
            current->next = new MRUQueueListNode(number);
            current = current->next;
        }

        tail = current;
    }

    int fetch(int k) {
        MRUQueueListNode* current = head;

        // Traverse to the node before the k-th node
        for (int index = 1; index < k; ++index) {
            current = current->next;
        }

        // Get the value of the k-th node
        int value = current->next->value;

        // Move the k-th node to the end of the list
        tail->next = current->next;
        tail = tail->next;
        current->next = tail->next;
        tail->next = nullptr;

        return value;
    }
};
