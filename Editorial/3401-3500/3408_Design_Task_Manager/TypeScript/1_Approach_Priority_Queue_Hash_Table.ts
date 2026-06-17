class TaskManager {
    private taskInfo: Map<number, [number, number]>;
    private heap: PriorityQueue<[number, number]>;

    constructor(tasks: number[][]) {
        this.taskInfo = new Map();
        this.heap = new PriorityQueue<[number, number]>(
            (a: [number, number], b: [number, number]) => {
                if (a[0] === b[0]) {
                    return a[1] > b[1] ? -1 : 1;
                }
                return a[0] > b[0] ? -1 : 1;
            },
        );
        for (const [userId, taskId, priority] of tasks) {
            this.taskInfo.set(taskId, [priority, userId]);
            this.heap.enqueue([priority, taskId]);
        }
    }

    add(userId: number, taskId: number, priority: number): void {
        this.taskInfo.set(taskId, [priority, userId]);
        this.heap.enqueue([priority, taskId]);
    }

    edit(taskId: number, newPriority: number): void {
        if (this.taskInfo.has(taskId)) {
            const [priority, userId] = this.taskInfo.get(taskId)!;
            this.taskInfo.delete(taskId);
            this.taskInfo.set(taskId, [newPriority, userId]);
            this.heap.enqueue([newPriority, taskId]);
        }
    }

    rmv(taskId: number): void {
        this.taskInfo.delete(taskId);
    }

    execTop(): number {
        while (!this.heap.isEmpty()) {
            const [priority, taskId] = this.heap.dequeue();
            if (
                this.taskInfo.has(taskId) &&
                this.taskInfo.get(taskId)![0] === priority
            ) {
                const userId = this.taskInfo.get(taskId)![1];
                this.taskInfo.delete(taskId);
                return userId;
            }
        }
        return -1;
    }
}
