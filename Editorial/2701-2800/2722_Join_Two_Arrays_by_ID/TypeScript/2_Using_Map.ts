function join(arr1: any[], arr2: any[]): any[] {
  const map = new Map<number, any>();

  for (const obj of arr1) {
    map.set(obj.id, obj);
  }

  for (const obj of arr2) {
    if (!map.has(obj.id)) {
      map.set(obj.id, obj);
    } else {
      const prevObj = map.get(obj.id);
      for (const key of Object.keys(obj)) {
        prevObj[key] = obj[key];
      }
    }
  }

  const res: any[] = [];
  for (const key of map.keys()) {
    res.push(map.get(key));
  }

  return res.sort((a, b) => a.id - b.id);
}
