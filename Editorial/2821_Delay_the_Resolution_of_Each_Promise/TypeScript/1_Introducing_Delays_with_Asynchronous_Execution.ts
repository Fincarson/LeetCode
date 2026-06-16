function delayAll(functions: Function[], ms: number): Function[] {
    const newFunctions: Function[] = [];

    functions.forEach(el => {
        const newFuncWithPromise: Function = () => {
            return new Promise((resolve, reject) => {
                // Introduce the delay
                setTimeout(async () => {
                    try {
                        // Execute original function
                        const res = await el();
                        resolve(res);
                    } catch(err) {
                        reject(err);
                    }
                }, ms);
            });
        }

        // Add the new function with the delay to the results
        newFunctions.push(newFuncWithPromise);
    });

    return newFunctions;
};
