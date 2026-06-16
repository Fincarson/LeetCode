
type Fn = (...args: any[]) => any;

declare global {
    interface Function {
        bindPolyfill(obj: Record<string | symbol, any>): Fn;
    }
}

Function.prototype.bindPolyfill = function(this: Function, obj: Record<string | symbol, any>): Fn {
    const self = this;  // Reference to the original function using closure

    return function(...args: any[]) {     // Return a new function
        return self.apply(obj, args);  // Invoke original function with obj context using apply
    }
}
