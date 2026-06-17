type F = (...p: any[]) => any

var debounce = function(fn, t) {
    let timeout;
    return function(...args) {
        clearTimeout(timeout);
        timeout = setTimeout(() => fn.apply(this, args), t)
    }
};
