function checkIfInstanceOf(obj: any, classFunction: any): boolean {
  if (obj === null || obj === undefined || typeof classFunction !== "function")
    return false;

  let currPotentialPrototype = Object.getPrototypeOf(obj);

  while (currPotentialPrototype !== null) {
    if (currPotentialPrototype === (classFunction as Function).prototype)
      return true;
    currPotentialPrototype = Object.getPrototypeOf(currPotentialPrototype);
  }

  return false;
};
