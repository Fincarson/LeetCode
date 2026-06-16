function cancellable(fn: Function, args: any[], t: number): Function {
  let isCancelled: boolean = false;
  fn(...args);
  
  const startInterval = (): void => {
    setTimeout(() => {
      if (isCancelled) return;
      fn(...args);
      startInterval();
    }, t);
  };
  
  startInterval();
  
  const cancelInterval: Function = (): void => {
    isCancelled = true;
  };

  return cancelInterval;
}
