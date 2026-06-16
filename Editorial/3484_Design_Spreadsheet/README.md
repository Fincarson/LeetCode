# 3484. Design Spreadsheet

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/design-spreadsheet/)  
`Array` `Hash Table` `String` `Design` `Matrix`

**Problem Link:** [LeetCode 3484 - Design Spreadsheet](https://leetcode.com/problems/design-spreadsheet/)

## Problem

A spreadsheet is a grid with 26 columns (labeled from 'A' to 'Z') and a given number of rows. Each cell in the spreadsheet can hold an integer value between 0 and 105.

Implement the Spreadsheet class:

- Spreadsheet(int rows) Initializes a spreadsheet with 26 columns (labeled 'A' to 'Z') and the specified number of rows. All cells are initially set to 0.
- void setCell(String cell, int value) Sets the value of the specified cell. The cell reference is provided in the format "AX" (e.g., "A1", "B10"), where the letter represents the column (from 'A' to 'Z') and the number represents a 1-indexed row.
- void resetCell(String cell) Resets the specified cell to 0.
- int getValue(String formula) Evaluates a formula of the form "=X+Y", where X and Y are either cell references or non-negative integers, and returns the computed sum.

Note: If getValue references a cell that has not been explicitly set using setCell, its value is considered 0.

### Example 1

## Constraints

- 1 <= rows <= 103
- 0 <= value <= 105
- The formula is always in the format "=X+Y", where X and Y are either valid cell references or non-negative integers with values less than or equal to 105.
- Each cell reference consists of a capital letter from 'A' to 'Z' followed by a row number between 1 and rows.
- At most 104 calls will be made in total to setCell, resetCell, and getValue.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3484. Design Spreadsheet

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define COLUMNS 26

typedef struct {
    int** grid;
    int rows;
} Spreadsheet;

void getPos(const char* cell, int* x, int* y) {
    *x = atoi(cell + 1);
    *y = toupper(cell[0]) - 'A';
}

Spreadsheet* spreadsheetCreate(int rows) {
    Spreadsheet* obj = (Spreadsheet*)malloc(sizeof(Spreadsheet));
    obj->rows = rows + 1;
    obj->grid = (int**)malloc(obj->rows * sizeof(int*));
    for (int i = 0; i < obj->rows; i++) {
        obj->grid[i] = (int*)calloc(COLUMNS, sizeof(int));
    }
    return obj;
}

void spreadsheetSetCell(Spreadsheet* obj, char* cell, int value) {
    int x, y;
    getPos(cell, &x, &y);
    obj->grid[x][y] = value;
}

void spreadsheetResetCell(Spreadsheet* obj, char* cell) {
    int x, y;
    getPos(cell, &x, &y);
    obj->grid[x][y] = 0;
}

int getCellVal(Spreadsheet* obj, const char* cell) {
    if (isalpha(cell[0])) {
        int x, y;
        getPos(cell, &x, &y);
        return obj->grid[x][y];
    } else {
        return atoi(cell);
    }
}

int spreadsheetGetValue(Spreadsheet* obj, char* formula) {
    char* plus = strchr(formula, '+');
    char* cell1 = (char*)malloc(plus - formula);
    strncpy(cell1, formula + 1, plus - formula - 1);
    cell1[plus - formula - 1] = '\0';
    char* cell2 = strdup(plus + 1);
    int val1 = getCellVal(obj, cell1);
    int val2 = getCellVal(obj, cell2);
    free(cell1);
    free(cell2);
    return val1 + val2;
}

void spreadsheetFree(Spreadsheet* obj) {
    for (int i = 0; i < obj->rows; i++) {
        free(obj->grid[i]);
    }
    free(obj->grid);
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Spreadsheet {
public:
    Spreadsheet(int rows) {
        this->grid = vector<vector<int>>(rows + 1, vector<int>(26));
    }

    void setCell(string cell, int value) {
        auto [x, y] = getPos(cell);
        grid[x][y] = value;
    }

    void resetCell(string cell) {
        auto [x, y] = getPos(cell);
        grid[x][y] = 0;
    }

    int getValue(string formula) {
        int i = formula.find('+');
        string cell1 = formula.substr(1, i - 1);
        string cell2 = formula.substr(i + 1);
        return getCellVal(cell1) + getCellVal(cell2);
    }

private:
    vector<vector<int>> grid;

    pair<int, int> getPos(const string &cell) {
        int x = stoi(cell.substr(1));
        int y = cell[0] - 'A';
        return {x, y};
    }

    int getCellVal(string &cell) {
        if (isalpha(cell[0])) {
            auto [x, y] = getPos(cell);
            return grid[x][y];
        } else {
            return stoi(cell);
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Spreadsheet {
    private int[,] grid;

    public Spreadsheet(int rows) {
        this.grid = new int[rows + 1, 26];
    }

    public void SetCell(string cell, int value) {
        var pos = GetPos(cell);
        grid[pos.Item1, pos.Item2] = value;
    }

    public void ResetCell(string cell) {
        var pos = GetPos(cell);
        grid[pos.Item1, pos.Item2] = 0;
    }

    public int GetValue(string formula) {
        int i = formula.IndexOf('+');
        string cell1 = formula.Substring(1, i - 1);
        string cell2 = formula.Substring(i + 1);
        return GetCellVal(cell1) + GetCellVal(cell2);
    }

    private Tuple<int, int> GetPos(string cell) {
        int x = int.Parse(cell.Substring(1));
        int y = cell[0] - 'A';
        return Tuple.Create(x, y);
    }

    private int GetCellVal(string cell) {
        if (char.IsLetter(cell[0])) {
            var pos = GetPos(cell);
            return grid[pos.Item1, pos.Item2];
        } else {
            return int.Parse(cell);
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Spreadsheet struct {
	grid [][]int
}

func Constructor(rows int) Spreadsheet {
	grid := make([][]int, rows+1)
	for i := range grid {
		grid[i] = make([]int, 27)
	}
	return Spreadsheet{grid: grid}
}

func (this *Spreadsheet) SetCell(cell string, value int) {
	x, y := this.getPos(cell)
	this.grid[x][y] = value
}

func (this *Spreadsheet) ResetCell(cell string) {
	x, y := this.getPos(cell)
	this.grid[x][y] = 0
}

func (this *Spreadsheet) GetValue(formula string) int {
	i := strings.Index(formula, "+")
	cell1 := formula[1:i]
	cell2 := formula[i+1:]
	return this.getCellVal(cell1) + this.getCellVal(cell2)
}

func (this *Spreadsheet) getPos(cell string) (int, int) {
	x, _ := strconv.Atoi(cell[1:])
	y := int(cell[0] - 'A')
	return x, y
}

func (this *Spreadsheet) getCellVal(cell string) int {
	if cell[0] >= 'A' && cell[0] <= 'Z' {
		x, y := this.getPos(cell)
		return this.grid[x][y]
	} else {
		val, _ := strconv.Atoi(cell)
		return val
	}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Spreadsheet {

    private int[][] grid;

    public Spreadsheet(int rows) {
        this.grid = new int[rows + 1][26];
    }

    public void setCell(String cell, int value) {
        int[] pos = getPos(cell);
        grid[pos[0]][pos[1]] = value;
    }

    public void resetCell(String cell) {
        int[] pos = getPos(cell);
        grid[pos[0]][pos[1]] = 0;
    }

    public int getValue(String formula) {
        int i = formula.indexOf('+');
        String cell1 = formula.substring(1, i);
        String cell2 = formula.substring(i + 1);
        return getCellVal(cell1) + getCellVal(cell2);
    }

    private int[] getPos(String cell) {
        int x = Integer.parseInt(cell.substring(1));
        int y = cell.charAt(0) - 'A';
        return new int[] { x, y };
    }

    private int getCellVal(String cell) {
        if (Character.isLetter(cell.charAt(0))) {
            int[] pos = getPos(cell);
            return grid[pos[0]][pos[1]];
        } else {
            return Integer.parseInt(cell);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var Spreadsheet = function (rows) {
    this.grid = Array.from({ length: rows + 1 }, () => new Array(27).fill(0));
};

Spreadsheet.prototype.setCell = function (cell, value) {
    const [x, y] = this.getPos(cell);
    this.grid[x][y] = value;
};

Spreadsheet.prototype.resetCell = function (cell) {
    const [x, y] = this.getPos(cell);
    this.grid[x][y] = 0;
};

Spreadsheet.prototype.getValue = function (formula) {
    const i = formula.indexOf("+");
    const cell1 = formula.substring(1, i);
    const cell2 = formula.substring(i + 1);
    return this.getCellVal(cell1) + this.getCellVal(cell2);
};

Spreadsheet.prototype.getPos = function (cell) {
    const x = parseInt(cell.substring(1));
    const y = cell.charCodeAt(0) - "A".charCodeAt(0);
    return [x, y];
};

Spreadsheet.prototype.getCellVal = function (cell) {
    if (/[A-Z]/.test(cell[0])) {
        const [x, y] = this.getPos(cell);
        return this.grid[x][y];
    } else {
        return parseInt(cell);
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Spreadsheet:

    def __init__(self, rows: int):
        self.grid = [[0] * 27 for _ in range(rows + 1)]

    def setCell(self, cell: str, value: int) -> None:
        x, y = self.getPos(cell)
        self.grid[x][y] = value

    def resetCell(self, cell: str) -> None:
        x, y = self.getPos(cell)
        self.grid[x][y] = 0

    def getValue(self, formula: str) -> int:
        i = formula.find("+")
        cell1 = formula[1:i]
        cell2 = formula[i + 1 :]
        return self.getCellVal(cell1) + self.getCellVal(cell2)

    def getPos(self, cell):
        x = int(cell[1:])
        y = ord(cell[0]) - ord("A")
        return (x, y)

    def getCellVal(self, cell):
        if cell[0].isalpha():
            x, y = self.getPos(cell)
            return self.grid[x][y]
        else:
            return int(cell)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
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
```

</details>

<br>

## Approach 2: Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    char *key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, const char *key) {
    HashItem *pEntry = NULL;
    HASH_FIND_STR(*obj, key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, char *key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = strdup(key);
    pEntry->val = val;
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, char *key, int val) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem **obj, const char *key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

bool hashErase(HashItem **obj, char *key) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return false;
    }
    HASH_DEL(*obj, pEntry);
    free(pEntry->key);
    free(pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr->key);
        free(curr);
    }
}

typedef struct {
    HashItem *cellValues;
} Spreadsheet;

Spreadsheet *spreadsheetCreate(int rows) {
    Spreadsheet *obj = (Spreadsheet *)malloc(sizeof(Spreadsheet));
    obj->cellValues = NULL;
    return obj;
}

void spreadsheetSetCell(Spreadsheet *obj, char *cell, int value) {
    hashSetItem(&obj->cellValues, cell, value);
}

void spreadsheetResetCell(Spreadsheet *obj, char *cell) {
    hashErase(&obj->cellValues, cell);
}

int getCellVal(Spreadsheet *obj, const char *cell) {
    if (isalpha(cell[0])) {
        return hashGetItem(&obj->cellValues, cell, 0);
    } else {
        return atoi(cell);
    }
}

int spreadsheetGetValue(Spreadsheet *obj, char *formula) {
    char *plus = strchr(formula, '+');
    char *cell1 = (char *)malloc(plus - formula);
    strncpy(cell1, formula + 1, plus - formula - 1);
    cell1[plus - formula - 1] = '\0';
    char *cell2 = strdup(plus + 1);
    int val1 = getCellVal(obj, cell1);
    int val2 = getCellVal(obj, cell2);
    free(cell1);
    free(cell2);
    return val1 + val2;
}

void spreadsheetFree(Spreadsheet *obj) {
    hashFree(&obj->cellValues);
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Spreadsheet {
public:
    Spreadsheet(int) {}

    void setCell(string cell, int value) { cellValues[cell] = value; }

    void resetCell(string cell) { cellValues.erase(cell); }

    int getValue(string formula) {
        int i = formula.find('+');
        string cell1 = formula.substr(1, i - 1);
        string cell2 = formula.substr(i + 1);
        return (isalpha(cell1[0]) ? cellValues[cell1] : stoi(cell1)) +
               (isalpha(cell2[0]) ? cellValues[cell2] : stoi(cell2));
    }

private:
    unordered_map<string, int> cellValues;
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Spreadsheet {
    private Dictionary<string, int> cellValues = new Dictionary<string, int>();

    public Spreadsheet(int size) {}

    public void SetCell(string cell, int value) {
        cellValues[cell] = value;
    }

    public void ResetCell(string cell) {
        cellValues.Remove(cell);
    }

    public int GetValue(string formula) {
        int i = formula.IndexOf('+');
        string cell1 = formula.Substring(1, i - 1);
        string cell2 = formula.Substring(i + 1);
        int val1 = char.IsLetter(cell1[0]) ? cellValues.GetValueOrDefault(cell1)
                                           : int.Parse(cell1);
        int val2 = char.IsLetter(cell2[0]) ? cellValues.GetValueOrDefault(cell2)
                                           : int.Parse(cell2);
        return val1 + val2;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Spreadsheet struct {
	cellValues map[string]int
}

func Constructor(rows int) Spreadsheet {
	return Spreadsheet{
		cellValues: make(map[string]int),
	}
}

func (this *Spreadsheet) SetCell(cell string, value int) {
	this.cellValues[cell] = value
}

func (this *Spreadsheet) ResetCell(cell string) {
	delete(this.cellValues, cell)
}

func (this *Spreadsheet) GetValue(formula string) int {
	i := strings.Index(formula, "+")
	cell1 := formula[1:i]
	cell2 := formula[i+1:]

	var val1, val2 int
	if unicode.IsLetter(rune(cell1[0])) {
		val1 = this.cellValues[cell1]
	} else {
		val1, _ = strconv.Atoi(cell1)
	}
	if unicode.IsLetter(rune(cell2[0])) {
		val2 = this.cellValues[cell2]
	} else {
		val2, _ = strconv.Atoi(cell2)
	}

	return val1 + val2
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Spreadsheet {

    private Map<String, Integer> cellValues = new HashMap<>();

    public Spreadsheet(int size) {}

    public void setCell(String cell, int value) {
        cellValues.put(cell, value);
    }

    public void resetCell(String cell) {
        cellValues.remove(cell);
    }

    public int getValue(String formula) {
        int i = formula.indexOf('+');
        String cell1 = formula.substring(1, i);
        String cell2 = formula.substring(i + 1);
        int val1 = Character.isLetter(cell1.charAt(0))
            ? cellValues.getOrDefault(cell1, 0)
            : Integer.parseInt(cell1);
        int val2 = Character.isLetter(cell2.charAt(0))
            ? cellValues.getOrDefault(cell2, 0)
            : Integer.parseInt(cell2);
        return val1 + val2;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var Spreadsheet = function (rows) {
    this.cellValues = {};
};

Spreadsheet.prototype.setCell = function (cell, value) {
    this.cellValues[cell] = value;
};

Spreadsheet.prototype.resetCell = function (cell) {
    delete this.cellValues[cell];
};

Spreadsheet.prototype.getValue = function (formula) {
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
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Spreadsheet:

    def __init__(self, rows: int):
        self.cell_values = {}

    def setCell(self, cell: str, value: int) -> None:
        self.cell_values[cell] = value

    def resetCell(self, cell: str) -> None:
        if cell in self.cell_values:
            del self.cell_values[cell]

    def getValue(self, formula: str) -> int:
        i = formula.find("+")
        cell1 = formula[1:i]
        cell2 = formula[i + 1 :]
        val1 = (
            self.cell_values.get(cell1, 0) if cell1[0].isalpha() else int(cell1)
        )
        val2 = (
            self.cell_values.get(cell2, 0) if cell2[0].isalpha() else int(cell2)
        )
        return val1 + val2
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
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
```

</details>
