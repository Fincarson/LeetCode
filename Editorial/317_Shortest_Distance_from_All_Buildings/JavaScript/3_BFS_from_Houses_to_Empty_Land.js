// Next four directions.
let dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

// Queue Implementation using Linked List.
class Node {
    constructor(row, col) {
        this.row = row;
        this.col = col;
        this.prev = null;
        this.next = null;
    }
}

class QueueClass {
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    length() {
        return this.length;
    }

    push(row, col) {
        const newNode = new Node(row, col);

        if (this.head == null) {
            this.head = newNode;
            this.tail = newNode;
        } 
        else {
            this.tail.next = newNode;
            newNode.prev = this.tail;
            this.tail = newNode;
        }

        this.length++;
    }

    pop() {
        if (this.head == null) return null;

        // Get the popped node.
        const popped = this.head;

        // Save newHead to a variable (could be null).
        const newHead = this.head.next;

        // If newHead is not null.
        if (newHead) {
            newHead.prev = null;
            this.head.next = null;
        } 
        
        else {
            // Change tail in case newHead is null.
            this.tail = null;
        }

        // Assign new tail (could be null).
        this.head = newHead;

        // Decrement length.
        this.length--;
        return popped;
    }
    
    empty() {
        return this.length == 0;
    }
}

let shortestDistance = function (grid) {
    let minDistance = Number.MAX_VALUE;
    let rows = grid.length;
    let cols = grid[0].length;

    // Total Mtrix to store total distance sum for each empty cell.
    let total = new Array(rows).fill(0).map(() => new Array(cols).fill(0));

    let emptyLandValue = 0;
    let minDist = Number.MAX_VALUE;

    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            
            // Start a BFS from each house.
            if (grid[row][col] == 1) {
                minDist = Number.MAX_VALUE;

                // Use a queue to perform a BFS, starting from the cell located at (row, col).
                let q = new QueueClass();
                q.push(row, col);

                let steps = 0;

                while (!q.empty()) {
                    steps++;

                    for (let level = q.length; level > 0; --level) {
                        let curr = q.pop();

                        dirs.forEach((dir) => {
                            let nextRow = curr.row + dir[0];
                            let nextCol = curr.col + dir[1];

                            // For each cell with the value equal to empty land value
                            // add distance and decrement the cell value by 1.
                            if (nextRow >= 0 && nextRow < rows &&
                                nextCol >= 0 && nextCol < cols &&
                                grid[nextRow][nextCol] == emptyLandValue) {
                                grid[nextRow][nextCol]--;
                                total[nextRow][nextCol] += steps;

                                q.push(nextRow, nextCol);
                                minDist = Math.min(minDist, total[nextRow][nextCol]);
                            }
                        });
                    }
                }

                // Decrement empty land value to be searched in next iteration.
                emptyLandValue--;
            }
        }
    }

    return minDist == Number.MAX_VALUE ? -1 : minDist;
};
