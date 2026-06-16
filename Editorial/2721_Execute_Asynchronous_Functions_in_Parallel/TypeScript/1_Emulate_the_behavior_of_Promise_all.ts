async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
  return new Promise<T[]>((resolve, reject) => {
    if(functions.length === 0) {
      resolve([]);
      return;
    }

    const res: T[] = new Array(functions.length).fill(null);

    let resolvedCount = 0;

    functions.forEach(async (el, idx) => {
      try {
        const subResult = await el();
        res[idx] = subResult;
        resolvedCount++;
        if(resolvedCount === functions.length) {
          resolve(res);
        }
      } catch(err) {
        reject(err);
      }
    });
  });
};
