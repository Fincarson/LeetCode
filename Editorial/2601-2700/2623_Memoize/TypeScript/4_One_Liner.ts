var memoize = (fn: (...params: any) => any, cache = {}) => (...args) => cache[args.join()] ?? (cache[args.join()] = fn(...args))
