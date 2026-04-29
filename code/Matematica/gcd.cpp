//GCD
//O(log B)
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
//lcm(a, b) = a*b/gcd(a, b)