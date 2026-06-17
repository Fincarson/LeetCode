function createInfiniteObject(): Record<string, () => string> {
  return new Proxy({}, {
    get: function(target: object, propKey: string | symbol): () => string {
      return function(): string {
        return String(propKey);
      };
    }
  });
}
