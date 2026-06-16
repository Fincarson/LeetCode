declare global {
    interface String {
        replicate(times: number): string;
    }
}

String.prototype.replicate = function(times: number) {
    let result = "";
    for (let i = 0; i < times; i++) {
        result += this;
    }
    return result;
};
