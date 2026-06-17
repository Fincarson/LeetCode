type Fn = (...params: any) => any

function createKeyGenerator() {
    let count = 0;
    const map = new Map<unknown, number>();
    return function(input: unknown) {
        if (map.has(input)) return map.get(input);
        map.set(input, ++count)
        return count;
    }
}

function memoize(fn: Fn): Fn {
    const keyGenerator = createKeyGenerator();
    const cache = new Map<string, any>();
    return function(...args) {
        const numbers = args.map(keyGenerator);
        const key = numbers.join(',');
        if (cache.has(key)) return cache.get(key);
        const result = fn(...args);
        cache.set(key, result);
        return result;
    }
}
