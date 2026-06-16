int nthBit = 1 << n;
for (int i = 0; i < nthBit; ++i) {  // equivalent to (int)Math.pow(2, n)
    // generate bitmask, from 0..00 to 1..11
    String bitmask = Integer.toBinaryString(i | nthBit).substring(1);
}
