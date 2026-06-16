function once<T extends (...args: any[]) => any>(fn: T): 
 ((...args: Parameters<T>) => ReturnType<T> | undefined) {
  let hasBeenCalled = false;
  return function(...args){
    if (!hasBeenCalled) {
      hasBeenCalled = true;
      return fn.apply(this, args);
    }
  }
}
