var createCounter = function(init) {
  let currentCount = init;
  return new Proxy({}, {
    get: (target, key) => {
      switch(key) {
        case "increment":
          return () => ++currentCount;
        case "decrement":
          return () => --currentCount;
        case "reset":
          return () => (currentCount = init);
        default:
          throw Error("Unexpected Method")
      }
    },
  });
};
