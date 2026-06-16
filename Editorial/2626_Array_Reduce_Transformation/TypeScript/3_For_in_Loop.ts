type Fn = (accum: number, curr: number) => number

function reduce(arr: number[], fn: Fn, initialVal: number): number {
  let accumulator = initialVal;
  for (const index in arr) {
    accumulator = fn(accumulator, arr[index]);
  } 
  return accumulator;
};
