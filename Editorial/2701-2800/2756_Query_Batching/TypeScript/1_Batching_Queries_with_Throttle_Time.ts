
type QueryMultiple = (keys: string[]) => Promise<string[]>;

class QueryBatcher {
    private queryMultiple: QueryMultiple;
    private t: number;
    private isAvailable: boolean;
    private stashed: Array<{ key: string, resolve: (value: string) => void }>;

    constructor(queryMultiple: QueryMultiple, t: number) {
        this.queryMultiple = queryMultiple;
        this.t = t;
        this.isAvailable = true;  // Flag to indicate if the batcher can immediately process a query
        this.stashed = [];  // Temporary storage for queries arriving during a throttle time
    }

    async getValue(key: string): Promise<string> {
        return new Promise((resolve) => {
            if (this.isAvailable) {
                // If the batcher is available, process the query immediately
                this.isAvailable = false;
                this.queryMultiple([key]).then(results => resolve(results[0]));
                this.cooldown();  // Start the throttle time
                return;
            }
            // If the batcher is not available, stash the query for later processing
            this.stashed.push({ key, resolve });
        });
    }

    private cooldown(): void {
        setTimeout(() => {
            // If no stashed queries exist after the throttle time, set the batcher as available
            if (this.stashed.length === 0) {
                this.isAvailable = true;
                return;
            }

            // Prepare the stashed keys for batching and keep the resolve functions for later
            const keysToQuery = this.stashed.map(item => item.key);
            const resolvers = this.stashed.map(item => item.resolve);

            // Clear the stashed queries as they are about to be processed
            this.stashed = [];

            // Process the batched queries and return results to the respective callers
            this.queryMultiple(keysToQuery)
                .then(results => {
                    resolvers.forEach((resolve, idx) => {
                        resolve(results[idx]);
                    });
                });

            // Start another cooldown for the next batch
            this.cooldown();
        }, this.t);
    }
}
