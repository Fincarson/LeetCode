var createCounter = function(n: number) {
  let currentCount = n - 1;
  return function() {
    currentCount += 1;
    return currentCount;      
  };
};
