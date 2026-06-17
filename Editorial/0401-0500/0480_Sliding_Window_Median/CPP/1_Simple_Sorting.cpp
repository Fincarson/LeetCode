vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> medians;

    for (int i = 0; i + k <= nums.size(); i++) {
        vector<int> window(nums.begin() + i, nums.begin() + i + k);

        sort(window.begin(), window.end());

        if (k & 1)
            medians.push_back(window[k / 2]);
        else
            medians.push_back((double)(window[k / 2 - 1] + (double)window[k / 2]) / 2.0);
    }

    return medians;
}
