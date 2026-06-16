
type CallbackFn = (
    next: (data: number, error?: string) => void,
    ...args: number[]
) => void

type Promisified = (...args: number[]) => Promise<number>

function promisify(fn: CallbackFn): Promisified {
    return function(...args: number[]): Promise<number> {
        return new Promise((resolve, reject) => {
            function callback(result: number, error?: string) {
                // If error, reject the Promise
                if (error) {
                    reject(error);
                // If no error, resolve the Promise
                } else {
                    resolve(result);
                }
            }

            fn(callback, ...args);
        });
    };
}
