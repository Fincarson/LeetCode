var createCounter = function(n) {
  --n;
  return function() {
    return ++n;      
  };
};
