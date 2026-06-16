var delayAll = function(functions, ms) {
  const newFunctions = [];

  functions.forEach(el => {
    const newFuncWithPromise = () => {
      return new Promise((resolve, reject) => {
        // Introduce the delay
        setTimeout(() => {
          async function getResult() {
            try {
              // Execute original function
              const res = await el();
              resolve(res);
            } catch(err) {
              reject(err);
            }
          }
          getResult();
        }, ms);
      });
    }

    // Add the new function with the delay to the results
    newFunctions.push(newFuncWithPromise);
  });

  return newFunctions;
};
