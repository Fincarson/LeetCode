declare global {
   interface Array<T> {
      snail(rowsCount: number, colsCount: number): T[][];
   }
}

Array.prototype.snail = function<T>(rowsCount: number, colsCount: number): T[][] {
   if (this.length !==  rowsCount * colsCount) return [];
   
   let result = Array(rowsCount).fill(null).map(() => new Array(colsCount).fill(null));
   
   for (let j = 0; j < this.length; j++) {
      const i = Math.floor(j / rowsCount);
      
      if (i % 2 === 0) {
         result[j % rowsCount][i] = this[j];
         continue;
      }
      
      result[rowsCount - j % rowsCount - 1][i] = this[j];
   }
   
   return result;
}
