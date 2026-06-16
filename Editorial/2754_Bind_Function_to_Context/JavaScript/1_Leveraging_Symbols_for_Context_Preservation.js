
Function.prototype.bindPolyfill = function(obj) {
  const sym = Symbol()  // Create a unique symbol
  obj[sym] = this       // Assign the function to the symbol property of obj

  return (...args) => {     // Return a new function
    return obj[sym](...args)  // Invoke the original function, which is now a method on the object
  }
}
