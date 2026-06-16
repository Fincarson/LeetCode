function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const newArr: number[] = new Array(arr.length);
    for (const i in arr) {
        newArr[i] = fn(arr[i], Number(i));
    }
    return newArr;
};
