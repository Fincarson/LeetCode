function replaceNonCoprimes(nums: number[]): number[] {
    const ans: number[] = [];
    for (let num of nums) {
        while (ans.length > 0) {
            const last = ans[ans.length - 1];
            const g = gcd(last, num);
            if (g > 1) {
                num = Math.floor(last / g) * num;
                ans.pop();
            } else {
                break;
            }
        }
        ans.push(num);
    }
    return ans;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
