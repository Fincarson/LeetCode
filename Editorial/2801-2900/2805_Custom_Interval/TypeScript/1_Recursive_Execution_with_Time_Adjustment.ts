let intervalIdCounter: number = 0;
const intervalMap: Map<number, NodeJS.Timeout> = new Map(); // To store timer IDs

function customInterval(fn: Function, delay: number, period: number): number {
    let count = 0;
    const customId = intervalIdCounter++; // Generate a unique ID

    function dfs(): void {
        const timerId = setTimeout(() => {
            fn();
            dfs();
        }, delay + period * count);
        count++;
        intervalMap.set(customId, timerId); // Store timer ID
    }

    dfs();

    return customId;
}

function customClearInterval(id: number): void {
    // Retrieve the timer ID associated with the custom ID 
    const timerId = intervalMap.get(id);
    
    if(timerId) {
        clearTimeout(timerId);
        intervalMap.delete(id);
    }
}
