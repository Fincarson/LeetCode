function compareVersion(version1: string, version2: string): number {
    let nums1 = version1.split(".");
    let nums2 = version2.split(".");
    let n1 = nums1.length,
        n2 = nums2.length;

    // compare versions
    for (let i = 0; i < Math.max(n1, n2); ++i) {
        let i1 = i < n1 ? parseInt(nums1[i]) : 0;
        let i2 = i < n2 ? parseInt(nums2[i]) : 0;
        if (i1 != i2) {
            return i1 > i2 ? 1 : -1;
        }
    }
    // The versions are equal
    return 0;
}
