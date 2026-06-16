type Obj = Record<any, any>;

function compactObject(obj: Obj): Obj {
  function dfs(obj: any): any {
    if (!obj) return false;
    if (typeof obj !== 'object') return obj;

    if (Array.isArray(obj)) {
      const newArr: any[] = [];
      for (let i = 0; i < obj.length; i++) {
        const curr = obj[i];
        const subRes = dfs(curr);

        if (subRes) {
          newArr.push(subRes);
        }
      }

      return newArr;
    }

    const newObj: Obj = {};

    for (const key in obj) {
      const subRes = dfs(obj[key]);
      if (subRes) {
        newObj[key] = subRes;
      }
    }

    return newObj;
  }

  return dfs(obj);
};
