class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Precompute the Euclidean distance for each point,
        // define the initial binary search range,
        // and create a reference list of point indices
        vector<double> distances;
        vector<int> remaining;
        double low = 0, high = 0;
        for (int i = 0; i < points.size(); i++) {
            distances.push_back(euclideanDistance(points[i]));
            high = max(high, distances[i]);
            remaining.push_back(i);
        }
                
        // Perform a binary search of the distances
        // to find the k closest points
        vector<int> closest;
        while (k) {
            double mid = low + (high - low) / 2;
            vector<vector<int>> result = splitDistances(remaining, distances, mid);
            vector<int>& closer = result[0];
            vector<int>& farther = result[1];
            if (closer.size() > k) {
                // If more than k points are in the closer distances
                // then discard the farther points and continue
                remaining.swap(closer);
                high = mid;
            } else {
                // Add the closer points to the answer array and keep
                // searching the farther distances for the remaining points
                k -= closer.size();
                closest.insert(closest.end(), closer.begin(), closer.end());
                remaining.swap(farther);
                low = mid;
            }
        }
        
        // Return the k closest points using the reference indices
        vector<vector<int>> answer;
        for (int index : closest) {
            answer.push_back(points[index]);
        }
        return answer;
    }
    
private:
    vector<vector<int>> splitDistances(vector<int>& remaining, vector<double>& distances,
                                       double mid) {
        // Split the distances around the midpoint
        // and return them in separate vectors
        vector<vector<int>> result(2);
        vector<int> &closer = result[0], &farther = result[1];
        for (int index : remaining) {
            if (distances[index] <= mid) {
                closer.push_back(index);
            } else {
                farther.push_back(index);
            }
        }
        return result;
    } 
    
    double euclideanDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};
