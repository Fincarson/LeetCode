declare global {
   interface Array<T> {
      snail(rowsCount: number, colsCount: number): T[][];
   }
}

Array.prototype.snail = function<T>(rowsCount: number, colsCount: number): T[][] {
   if (rowsCount * colsCount !== this.length) return [];

   const res = new Array(rowsCount).fill(null).map(el => new Array(colsCount).fill(null));

   for (let currRow = 0; currRow < rowsCount; currRow++) {
      for (let currCol = 0; currCol < colsCount; currCol++) {
         if (currCol % 2 === 0) {
            res[currRow][currCol] = this[rowsCount * currCol + currRow];
            continue
         }
         
         res[currRow][currCol] = this[rowsCount * currCol + rowsCount - 1 - currRow];
      }
   }

   return res;
}
