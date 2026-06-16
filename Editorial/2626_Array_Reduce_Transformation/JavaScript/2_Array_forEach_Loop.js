var reduce = function(arr, fn, initialVal) {
  let accumulator = initialVal;
  arr.forEach((element) => {
    accumulator = fn(accumulator, element);
  });
  return accumulator;
};
