class Spreadsheet {
    private cellValues: { [key: string]: number } = {};

    constructor(size: number) {}

    setCell(cell: string, value: number): void {
        this.cellValues[cell] = value;
    }

    resetCell(cell: string): void {
        delete this.cellValues[cell];
    }

    getValue(formula: string): number {
        const i = formula.indexOf("+");
        const cell1 = formula.substring(1, i);
        const cell2 = formula.substring(i + 1);
        const val1 = /[a-z]/i.test(cell1[0])
            ? this.cellValues[cell1] || 0
            : parseInt(cell1);
        const val2 = /[a-z]/i.test(cell2[0])
            ? this.cellValues[cell2] || 0
            : parseInt(cell2);
        return val1 + val2;
    }
}
