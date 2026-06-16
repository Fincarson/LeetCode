function singleNumber(nums: number[]): number {
    let no_duplicate_list: number[] = [];
    for (let i of nums) {
        if (!no_duplicate_list.includes(i)) {
            no_duplicate_list.push(i);
        } else {
            no_duplicate_list.splice(no_duplicate_list.indexOf(i), 1);
        }
    }
    return no_duplicate_list[0];
}
