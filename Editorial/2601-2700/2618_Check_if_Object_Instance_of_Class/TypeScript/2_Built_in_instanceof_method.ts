function checkIfInstanceOf(obj: any, classFunction: any): boolean {
  if (obj === null || obj === undefined || typeof classFunction !== "function")
    return false;

  let inputObj = obj;
  if (typeof obj !== "object") {
    inputObj = Object(obj); // Make sure it's an object so instanceof has direct access to the constructor function
  }
  return inputObj instanceof classFunction;
};
