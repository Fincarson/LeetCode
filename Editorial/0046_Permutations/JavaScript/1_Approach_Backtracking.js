var permute = function (nums) {
    var ans = [];
    var backtrack = function (curr) {
        if (curr.length === nums.length) {
            ans.push([...curr]);
            return;
        }
        for (var num of nums) {
            if (!curr.includes(num)) {
                curr.push(num);
                backtrack(curr);
                curr.pop();
            }
        }
    };
    backtrack([]);
    return ans;
};
