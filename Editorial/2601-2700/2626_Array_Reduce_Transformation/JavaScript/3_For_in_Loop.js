var reduce = function(arr, fn, initialVal) {
  let accumulator = initialVal;
  for (const index in arr) {
    accumulator = fn(accumulator, arr[index]);
  } 
  return accumulator;
};
