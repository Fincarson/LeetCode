class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> no_duplicate_list;
        for (int i : nums) {
            if (find(no_duplicate_list.begin(), no_duplicate_list.end(), i) ==
                no_duplicate_list.end()) {
                no_duplicate_list.push_back(i);
            } else {
                no_duplicate_list.erase(remove(no_duplicate_list.begin(),
                                               no_duplicate_list.end(), i));
            }
        }
        return no_duplicate_list[0];
    }
};
