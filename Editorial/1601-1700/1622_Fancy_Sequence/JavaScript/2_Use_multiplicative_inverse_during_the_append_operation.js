const MOD = 1000000007n;

var Fancy = function () {
    this.v = [];
    this.a = 1n;
    this.b = 0n;
};

// fast exponentiation
Fancy.prototype.quickMul = function (x, y) {
    let ret = 1n;
    let cur = BigInt(x);
    let power = BigInt(y);
    while (power !== 0n) {
        if ((power & 1n) !== 0n) {
            ret = (ret * cur) % MOD;
        }
        cur = (cur * cur) % MOD;
        power >>= 1n;
    }
    return Number(ret);
};

// multiplicative inverse
Fancy.prototype.inv = function (x) {
    return this.quickMul(x, MOD - 2n);
};

Fancy.prototype.append = function (val) {
    const adjustedVal =
        (((BigInt(val) - this.b + MOD) % MOD) *
            BigInt(this.inv(Number(this.a)))) %
        MOD;
    this.v.push(Number(adjustedVal));
};

Fancy.prototype.addAll = function (inc) {
    this.b = (this.b + BigInt(inc)) % MOD;
};

Fancy.prototype.multAll = function (m) {
    this.a = (this.a * BigInt(m)) % MOD;
    this.b = (this.b * BigInt(m)) % MOD;
};

Fancy.prototype.getIndex = function (idx) {
    if (idx >= this.v.length) {
        return -1;
    }
    const ans = (((this.a * BigInt(this.v[idx])) % MOD) + this.b) % MOD;
    return Number(ans);
};
