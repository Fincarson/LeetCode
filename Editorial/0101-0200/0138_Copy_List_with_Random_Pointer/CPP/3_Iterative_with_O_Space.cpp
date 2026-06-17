class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        // Creating a new weaved list of original and copied nodes.
        Node* ptr = head;
        while (ptr != nullptr) {
            // Cloned node
            Node* newNode = new Node(ptr->val, nullptr, nullptr);
            // Inserting the cloned node just next to the original node.
            // If A->B->C is the original linked list,
            // Linked list after weaving cloned nodes would be
            // A->A'->B->B'->C->C'
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }
        ptr = head;
        // Now link the random pointers of the new nodes created.
        // Iterate the newly created list and use the original nodes' random
        // pointers, to assign references to random pointers for cloned nodes.
        while (ptr != nullptr) {
            ptr->next->random =
                (ptr->random != nullptr) ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }
        // Unweave the linked list to get back the original linked list and the
        // cloned list. i.e. A->A'->B->B'->C->C' would be broken to A->B->C and
        // A'->B'->C'
        Node* ptr_old_list = head;        // A->B->C
        Node* ptr_new_list = head->next;  // A'->B'->C'
        Node* head_old = head->next;
        while (ptr_old_list != nullptr) {
            ptr_old_list->next = ptr_old_list->next->next;
            ptr_new_list->next = (ptr_new_list->next != nullptr)
                                     ? ptr_new_list->next->next
                                     : nullptr;
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }
        return head_old;
    }
};
