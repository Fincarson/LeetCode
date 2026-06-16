type Fn = (accum: number, curr: number) => number

function reduce(arr: number[], fn: Fn, initialVal: number): number {
  let accumulator = initialVal;
  arr.forEach((element) => {
    accumulator = fn(accumulator, element);
  });
  return accumulator;
};
