class LookupTree {
  private map = new Map<any, any>();

  private hasValue = false;

  private value: any = null;

  private getValueHelper(path: any, i: number): { value: any; success: boolean } {
    const key = path[i];
    if (i >= path.length) {
      if (this.hasValue) {
        return { value: this.value, success: true };
      } else {
        return { value: undefined, success: false };
      }
    } else {
      if (this.map.has(key)) {
        return this.map.get(key).getValueHelper(path, i + 1);
      } else {
        return { value: undefined, success: false };
      }
    }
  }

  public getValue(path: any[]) {
    return this.getValueHelper(path, 0);
  }

  private setValueHelper(path: any[], i: number, value: any) {
    const key = path[i];
    if (i >= path.length) {
      this.value = value;
      this.hasValue = true;
    } else {
      if (!this.map.has(key)) {
        this.map.set(key, new LookupTree());
      }
      return this.map.get(key).setValueHelper(path, i + 1, value);
    }
  }

  public setValue(path: any[], value: any) {
    return this.setValueHelper(path, 0, value);
  }
}

function memoize<F extends (...params: any[]) => any>(func: F): F {
  const tree = new LookupTree();
  const newFunction = (...params: any[]) => {
    const cache = tree.getValue(params);
    if (cache.success) {
      return cache.value;
    }
    const result = func(...params);
    tree.setValue(params, result);
    return result;
  };
  return newFunction as F;
}
