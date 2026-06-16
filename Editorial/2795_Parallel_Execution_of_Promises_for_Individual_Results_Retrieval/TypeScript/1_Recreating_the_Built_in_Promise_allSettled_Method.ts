type FulfilledObj = {
    status: 'fulfilled';
    value: any;
}

type RejectedObj = {
    status: 'rejected';
    reason: any;
}

type Obj = FulfilledObj | RejectedObj;

const promiseAllSettled = (functions: (() => Promise<any>)[]): Promise<Obj[]> => {
    return new Promise(resolve => {
        // if there are no promises, resolve immediately with an empty array
        if(functions.length === 0) {
            resolve([]);
            return;
        }

        const res: Obj[] = new Array(functions.length).fill(null);
        let settledCounter = 0;

        functions.forEach(async (func, idx) => {
            try {
                const result = await func();
                res[idx] = { status: 'fulfilled', value: result };
            } catch(error) {
                res[idx] = { status: 'rejected', reason: error };
            } finally {
                settledCounter++;
                // if all promises have settled, resolve with the results
                if(settledCounter === functions.length) {
                    resolve(res);
                }
            }
        });
    });
};
