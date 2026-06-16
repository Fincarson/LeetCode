vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> medians;
    multiset<int> lo, hi;

    for (int i = 0; i < nums.size(); i++) {
        //remove outgoing element
        if (i >= k) {
            if (nums[i - k] <= *lo.rbegin())
                lo.erase(lo.find(nums[i - k]));
            else
                hi.erase(hi.find(nums[i - k]));
        }

        // insert incoming element
        lo.insert(nums[i]);

        // balance the sets
        hi.insert(*lo.rbegin());
        lo.erase(prev(lo.end()));

        if (lo.size() < hi.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }

        // get median
        if (i >= k - 1) {
            medians.push_back(k & 1 ? *lo.rbegin() : ((double)(*lo.rbegin()) + (double)(*hi.begin())) * 0.5);
        }
    }

    return medians;
}
