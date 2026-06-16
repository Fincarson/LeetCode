interface Item {
    value: number;
    left: number;
    right: number;
}

function maxValue(nums: number[]): number[] {
    const n = nums.length;
    const ans = new Array<number>(n);

    const stack: Item[] = [];

    for (let i = 0; i < n; i++) {
        let curr: Item = {
            value: nums[i],
            left: i,
            right: i,
        };

        while (stack.length > 0 && stack.at(-1)!.value > nums[i]) {
            const top = stack.pop()!;
            curr = {
                value: Math.max(curr.value, top.value),
                left: top.left,
                right: curr.right,
            };
        }

        stack.push(curr);
    }

    for (let i = 0; i < stack.length; i++) {
        for (let j = stack[i].left; j <= stack[i].right; j++) {
            ans[j] = stack[i].value;
        }
    }

    return ans;
}
