type MultidimensionalArray = (MultidimensionalArray | number)[];

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
  if (!Array.isArray(arr)) {
    yield arr;
    return;
  }

  for (let i = 0; i < arr.length; i++) {
    yield* inorderTraversal(arr[i] as MultidimensionalArray);
  }
}
