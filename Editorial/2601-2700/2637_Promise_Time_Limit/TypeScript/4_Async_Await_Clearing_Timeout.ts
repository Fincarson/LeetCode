type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
  return async function(...args) {
    return new Promise(async (resolve, reject) => {
      const timeout = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);

      try {
        const result = await fn(...args);
        resolve(result);
      } catch(err) {
        reject(err);
      }
      clearTimeout(timeout);
    });
  };
};
