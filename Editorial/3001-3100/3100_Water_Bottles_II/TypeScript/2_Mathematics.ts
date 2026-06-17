function maxBottlesDrunk(numBottles: number, numExchange: number): number {
    let a = 1;
    let b = 2 * numExchange - 3;
    let c = -2 * numBottles;
    let delta = b * b - 4 * a * c;
    let t = Math.ceil((-b + Math.sqrt(delta)) / (2 * a));
    return numBottles + t - 1;
}
