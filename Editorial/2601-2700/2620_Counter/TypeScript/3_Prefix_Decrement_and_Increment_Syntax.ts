var createCounter = function(n: number) {
  --n;
  return function() {
    return ++n;      
  };
};
