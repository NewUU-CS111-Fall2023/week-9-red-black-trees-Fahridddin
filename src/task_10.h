int kthFactor(int n, int k) {
  if (k > n) return -1; // Not enough factors

  // Initialize variables and count factors
  int factorsCount = 0;
  int i = 1;

  // Find factors and track position
  while (i * i <= n) {
    if (n % i == 0) {
      factorsCount++;
      if (i * i == n) { // Perfect square case
        if (factorsCount == k) return i; // Found kth factor (i)
      } else { // Non-perfect square case
        int j = n / i; // Other factor
        if (factorsCount + 1 == k) return j; // Found kth factor (j)
        factorsCount++;
      }
    }
    i++;
  }

  // Check remaining factors (up to n)
  for (; i <= n / i; ++i) {
    if (n % i == 0 && factorsCount + 1 == k) return n / i; 
    factorsCount++;
  }

  // No kth factor found
  return -1;
}
