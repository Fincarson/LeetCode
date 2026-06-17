function cancellable(fn: Function, args: any[], t: number): Function {
  let isCancelled: boolean = false;
  
  setTimeout(() => {
    if (!isCancelled) {
      fn(...args);
    }
  }, t);

  return () => {
    isCancelled = true;
  };
}
