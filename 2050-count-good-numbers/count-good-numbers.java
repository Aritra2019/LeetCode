class Solution {
    public int countGoodNumbers(long n) {
        long MOD = 1000000007L;                 // modulus 10^9 + 7
        long even = (n + 1) / 2;               // number of even indices (0,2,4,...)
        long odd = n / 2;                      // number of odd indices (1,3,5,...)
        long pow5 = modPow(5L, even, MOD);     // compute 5^even % MOD
        long pow4 = modPow(4L, odd, MOD);      // compute 4^odd % MOD
        long ans = (pow5 * pow4) % MOD;        // multiply under modulus
        return (int) ans;                      // return result as int
    }

    private long modPow(long base, long exp, long mod) {
        long result = 1L % mod;                // initialize result
        base %= mod;                           // reduce base modulo mod
        while (exp > 0) {                      // loop while exponent > 0
            if ((exp & 1) == 1)                // if current bit of exp is 1
                result = (result * base) % mod;// multiply result by base (modded)
            base = (base * base) % mod;        // square the base (modded)
            exp >>= 1;                         // shift exponent right by 1 (divide by 2)
        }
        return result;                         // return computed power modulo mod
    }
}
