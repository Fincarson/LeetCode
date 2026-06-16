declare global {
   interface Array<T> {
      snail(rowsCount: number, colsCount: number): T[][];
   }
}

Array.prototype.snail = function<T>(rowsCount: number, colsCount: number): T[][] {
   if (rowsCount * colsCount !== this.length) return [];

   const res = new Array(rowsCount).fill(null).map(() => new Array(colsCount).fill(null));

   const directions = [[1, 0], [-1, 0]]; // down, up
   let directionIndex = 0;
   let row = 0, col = 0;

   for (let i = 0; i < this.length; i++) {
      res[row][col] = this[i];
      let nextRow = row + directions[directionIndex][0];
      let nextCol = col;

      if (nextRow < 0 || nextRow === rowsCount) {
         directionIndex = (directionIndex + 1) % 2; // change direction
         nextRow = row;
         nextCol = col + 1;
      }

      row = nextRow;
      col = nextCol;
   }

   return res;
}
