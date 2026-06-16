function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    const newArr: number[] = [];
    for (const stringIndex in arr) {
        const i = Number(stringIndex);
        if (fn(arr[i], i)) {
            newArr.push(arr[i]);
        }
    }
    return newArr;
};
