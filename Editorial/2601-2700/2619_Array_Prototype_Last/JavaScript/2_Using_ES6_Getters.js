Object.defineProperty(Array.prototype, 'last', {
  get: function() {
    return () => this.length ? this[this.length - 1] : -1;
  }
});
