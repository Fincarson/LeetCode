class MaxStack {
private:
    stack<pair<int, int>> stk;
    priority_queue<pair<int, int>> heap;
    unordered_set<int> removed;
    int cnt;

public:
    MaxStack() { cnt = 0; }

    void push(int x) {
        stk.push({x, cnt});
        heap.push({x, cnt});
        cnt++;
    }

    int pop() {
        while (removed.count(stk.top().second)) {
            stk.pop();
        }
        const pair<int, int> p = stk.top();
        stk.pop();
        removed.insert(p.second);
        return p.first;
    }

    int top() {
        while (removed.count(stk.top().second)) {
            stk.pop();
        }
        return stk.top().first;
    }

    int peekMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        return heap.top().first;
    }

    int popMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        const pair<int, int> p = heap.top();
        heap.pop();
        removed.insert(p.second);
        return p.first;
    }
};
