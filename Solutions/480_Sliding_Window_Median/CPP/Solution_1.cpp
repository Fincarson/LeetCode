class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        multiset<int> LHS, RHS;

        for(int i = 0; i < nums.size(); ++i){
            if(i >= k){
                if(nums[i-k] <= *LHS.rbegin()) LHS.erase(LHS.find(nums[i-k]));
                else RHS.erase(RHS.find(nums[i-k]));
            }

            LHS.insert(nums[i]);
            RHS.insert(*LHS.rbegin());
            LHS.erase(prev(LHS.end()));

            if(LHS.size() < RHS.size()){
                LHS.insert(*RHS.begin());
                RHS.erase(RHS.begin());
            }
            
            if(i >= k-1){
                medians.push_back(k & 1 ? *LHS.rbegin() : ((double)*LHS.rbegin() + (double)*RHS.begin()) / 2.0);
            }
        }
        return medians;
    }
};