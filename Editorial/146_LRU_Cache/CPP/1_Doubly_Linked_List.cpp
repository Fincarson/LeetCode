struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};
