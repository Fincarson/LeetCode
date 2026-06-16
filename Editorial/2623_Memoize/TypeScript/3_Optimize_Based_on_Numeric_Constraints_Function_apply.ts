type Fn = (...params: any) => any

function memoize(fn: Fn): Fn {
  const cache = new Map();
  return function() {
    let key: number = arguments[0];
    if (arguments[1]) {
      key += arguments[1] * 100001;
    }
    const result = cache.get(key);
    if (result !== undefined) {
      return result;
    }
    const functionOutput = fn.apply(null, arguments as any);
    cache.set(key, functionOutput);
    return functionOutput;
  }
}
