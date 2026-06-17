class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> output;
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> heap;

        for (auto &x: points) heap.push({sqrt((x[0]*x[0]) + (x[1] * x[1])), {x[0], x[1]}});
        while(k--){
            vector<int> temp;
            temp.push_back(heap.top().second.first);
            temp.push_back(heap.top().second.second);
            output.push_back(temp);
            heap.pop();
        }
        return output;
    }
};