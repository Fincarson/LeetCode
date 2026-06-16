void processChild(struct Node* childNode, struct Node** prev,
                  struct Node** leftmost) {
    if (childNode) {
        // If the "prev" pointer is alread set i.e. if we
        // already found atleast one node on the next level,
        // setup its next pointer
        if (*prev) {
            (*prev)->next = childNode;
        } else {
            // Else it means this child node is the first node
            // we have encountered on the next level, so, we
            // set the leftmost pointer
            *leftmost = childNode;
        }
        *prev = childNode;
    }
}
struct Node* connect(struct Node* root) {
    if (!root) {
        return root;
    }
    // The root node is the only node on the first level
    // and hence its the leftmost node for that level
    struct Node* leftmost = root;
    // We have no idea about the structure of the tree,
    // so, we keep going until we do find the last level.
    // the nodes on the last level won't have any children
    while (leftmost) {
        // "prev" tracks the latest node on the "next" level
        // while "curr" tracks the latest node on the current
        // level.
        struct Node* prev = NULL;
        struct Node* curr = leftmost;
        // We reset this so that we can re-assign it to the leftmost
        // node of the next level. Also, if there isn't one, this
        // would help break us out of the outermost loop.
        leftmost = NULL;
        // Iterate on the nodes in the current level using
        // the next pointers already established.
        while (curr) {
            // Process both the children and update the prev
            // and leftmost pointers as necessary.
            processChild(curr->left, &prev, &leftmost);
            processChild(curr->right, &prev, &leftmost);
            // Move onto the next node.
            curr = curr->next;
        }
    }
    return root;
}
