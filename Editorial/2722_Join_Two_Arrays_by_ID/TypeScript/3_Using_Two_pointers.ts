function join(arr1: any[], arr2: any[]): any[] {
  arr1.sort((a, b) => a.id - b.id);
  arr2.sort((a, b) => a.id - b.id);

  let joinedArray: any[] = [];
  let i = 0, j = 0;

  while (i < arr1.length && j < arr2.length) {
    if (arr1[i].id < arr2[j].id) {
      joinedArray.push(arr1[i]);
      i++;
    } else if (arr1[i].id > arr2[j].id) {
      joinedArray.push(arr2[j]);
      j++;
    } else {
      joinedArray.push({ ...arr1[i], ...arr2[j] });
      i++;
      j++;
    }
  }

  while (i < arr1.length) {
    joinedArray.push(arr1[i]);
    i++;
  }

  while (j < arr2.length) {
    joinedArray.push(arr2[j]);
    j++;
  }

  return joinedArray;
}
