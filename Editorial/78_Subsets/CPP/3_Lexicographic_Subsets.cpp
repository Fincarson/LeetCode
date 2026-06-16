int nthBit = 1 << n;
for (int i = 0; i < nthBit; ++i) {  // equivalent to pow(2, n)
    // generate bitmask, from 0..00 to 1..11
    string bitmask = bitset<n + 1>(i | nthBit).to_string().substr(32 - n);
}
