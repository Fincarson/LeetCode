int totalHammingDistance(vector<int>& nums)
{
    int ans = 0;

    if (nums.empty())
        return ans;

    for (int i = 0; i < nums.size() - 1; i++)                  // for all unique pairs of elements
        for (int j = i + 1; j < nums.size(); j++)
            ans += __builtin_popcount(nums[i] ^ nums[j]);      // count number of 1 bits in xor resultant

    return ans;
}
