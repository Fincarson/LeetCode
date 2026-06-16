function f(nums2: number[], x1: number, v: number): number {
    const n2 = nums2.length;
    let left = 0,
        right = n2 - 1;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        const prod = nums2[mid] * x1;
        if ((x1 >= 0 && prod <= v) || (x1 < 0 && prod > v)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (x1 >= 0) {
        return left;
    } else {
        return n2 - left;
    }
}

function kthSmallestProduct(
    nums1: number[],
    nums2: number[],
    k: number,
): number {
    const n1 = nums1.length;
    let left = -1e10,
        right = 1e10;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        let count = 0;
        for (let i = 0; i < n1; i++) {
            count += f(nums2, nums1[i], mid);
        }
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
