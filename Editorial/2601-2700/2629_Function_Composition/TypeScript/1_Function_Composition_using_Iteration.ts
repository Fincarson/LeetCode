type F = (x: number) => number;

function compose(functions: F[]): F {
    return function(x: number): number {
        if (functions.length === 0) return x;
        let input = x;

        for (let i = functions.length - 1; i >= 0; i--) {
            const currFunc = functions[i];

            input = currFunc(input);
        }

        return input;
    };
};
