type MultidimensionalArray = (MultidimensionalArray | number)[];

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
  const stack: MultidimensionalArray[] = [arr];

  while (stack.length > 0) {
    const current = stack.pop();

    if (!Array.isArray(current)) {
      yield current;
      continue;
    }

    for (let i = current.length - 1; i >= 0; i--) {
      stack.push(current[i] as MultidimensionalArray);
    }
  }
}
