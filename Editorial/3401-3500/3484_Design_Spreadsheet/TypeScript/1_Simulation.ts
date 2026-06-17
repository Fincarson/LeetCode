class Spreadsheet {
    private grid: number[][];

    constructor(rows: number) {
        this.grid = Array.from({ length: rows + 1 }, () =>
            new Array(27).fill(0),
        );
    }

    setCell(cell: string, value: number): void {
        const [x, y] = this.getPos(cell);
        this.grid[x][y] = value;
    }

    resetCell(cell: string): void {
        const [x, y] = this.getPos(cell);
        this.grid[x][y] = 0;
    }

    getValue(formula: string): number {
        const i = formula.indexOf("+");
        const cell1 = formula.substring(1, i);
        const cell2 = formula.substring(i + 1);
        return this.getCellVal(cell1) + this.getCellVal(cell2);
    }

    private getPos(cell: string): [number, number] {
        const x = parseInt(cell.substring(1));
        const y = cell.charCodeAt(0) - "A".charCodeAt(0);
        return [x, y];
    }

    private getCellVal(cell: string): number {
        if (/[A-Z]/.test(cell[0])) {
            const [x, y] = this.getPos(cell);
            return this.grid[x][y];
        } else {
            return parseInt(cell);
        }
    }
}
