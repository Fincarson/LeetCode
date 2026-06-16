
type Fn = (...args: any[]) => any;

declare global {
    interface Function {
        bindPolyfill(obj: Record<string | symbol, any>): Fn;
    }
}

Function.prototype.bindPolyfill = function(this: Function, obj: Record<string | symbol, any>): Fn {
    const sym = Symbol();  // Create a unique symbol
    obj[sym] = this;       // Assign the function to the symbol property of obj

    return (...args: any[]) => {     // Return a new function
        return obj[sym](...args);   // Invoke the original function, which is now a method on the object
    }
}
