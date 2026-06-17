class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int totalCost = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // add all sticks to the min heap.
        for (int i = 0; i < sticks.size(); i++) {
            pq.push(sticks[i]);
        }
        
        // combine two of the smallest sticks until we are left with just one.
        while (pq.size() > 1) {
            int stick1 = pq.top(); 
            pq.pop();
            int stick2 = pq.top(); 
            pq.pop();
            
            int cost = stick1 + stick2;
            totalCost += cost;
            
            pq.push(stick1+stick2);
        }
        
        return totalCost;
    }
};
