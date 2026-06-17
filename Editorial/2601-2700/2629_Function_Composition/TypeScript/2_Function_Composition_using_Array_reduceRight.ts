type F = (x: number) => number;

function compose(functions: F[]): F {
    return (x: number) => functions.reduceRight((acc, f) => f(acc), x);
}
;
