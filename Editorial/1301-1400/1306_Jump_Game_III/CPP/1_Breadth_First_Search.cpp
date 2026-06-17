class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        size_t n = arr.size();

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // check if we reached zero
            if (arr[node] == 0) {
                return true;
            }
            if (arr[node] > 0) {
                // check available next steps
                if (node + arr[node] < n) {
                    q.push(node + arr[node]);
                }
                if (node - arr[node] >= 0) {
                    q.push(node - arr[node]);
                }
                // mark as visited
                arr[node] = -arr[node];
            }
        }
        return false;
    }
};
