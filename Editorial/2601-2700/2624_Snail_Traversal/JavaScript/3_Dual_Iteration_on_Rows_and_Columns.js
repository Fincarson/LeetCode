Array.prototype.snail = function(rowsCount, colsCount) {
  if(rowsCount * colsCount !== this.length) return [];

  const res = new Array(rowsCount).fill(null).map(el => new Array(colsCount).fill(null))

  for (let currRow = 0; currRow < rowsCount; currRow++) {
    for (let currCol = 0; currCol < colsCount; currCol++) {
      if (currCol % 2 === 0) {
        res[currRow][currCol] = this[rowsCount * currCol + currRow]
        continue
      }

      if (currCol % 2 !== 0) {
        res[currRow][currCol] = this[rowsCount * currCol + rowsCount - 1 - currRow]
      }
    }
  }

  return res
}
