def primeDecompose(num):
        """ decompose any positive number into 
                a series of prime factors.
            e.g. 12 = 2 * 2 * 3
        """
    factor = 2
    prime_factors = []
    while num >= factor * factor:
        if num % factor == 0:
            prime_factors.append(factor)
            num = num // factor
        else:
            factor += 1
    prime_factors.append(num)
    return prime_factors
