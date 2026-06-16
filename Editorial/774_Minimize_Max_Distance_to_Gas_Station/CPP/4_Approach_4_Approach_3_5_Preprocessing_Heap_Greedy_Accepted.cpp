class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int N = stations.size();

        // Step 1: Compute an upper bound for distance
        double distUpper =
            (stations.back() - stations.front()) / (double)(K + 1);

        // Step 2: Conservative allocation of stations per interval
        priority_queue<tuple<double, double, int>>
            pq; // (distance, interval_length, ki)
        for (int i = 0; i < N - 1; ++i) {
            double interval = stations[i + 1] - stations[i];
            int ki = floor(interval / distUpper);
            double actualDist = interval / (ki + 1);
            K -= ki;
            pq.push({actualDist, interval, ki});
        }

        // Step 3: Greedy allocation of remaining stations
        while (K-- > 0) {
            auto [dist, interval, ki] = pq.top();
            pq.pop();
            ki += 1;
            double newDist = interval / (ki + 1);
            pq.push({newDist, interval, ki});
        }

        // Step 4: Return the largest remaining distance
        return get<0>(pq.top());
    }
};
