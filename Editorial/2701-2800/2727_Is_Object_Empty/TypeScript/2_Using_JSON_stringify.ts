function isEmpty(obj: Record<string, any> | any[]): boolean {
  if (JSON.stringify(obj).length <= 2) {
    return true;
  } else {
    return false;
  }
}
