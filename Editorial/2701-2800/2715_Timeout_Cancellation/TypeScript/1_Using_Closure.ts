function cancellable(fn: Function, args: any[], t: number): Function {
  const timeoutId = setTimeout(() => {
    fn.apply(null, args);
  }, t);

  const cancelFn: Function = () => {
    clearTimeout(timeoutId);
  };

  return cancelFn;
}
