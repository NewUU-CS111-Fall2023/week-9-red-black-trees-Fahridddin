int kthFactor(int n, int k) {
  if (k > n) return -1; 

  int factorsCount = 0;
  int i = 1;

  while (i * i <= n) {
    if (n % i == 0) {
      factorsCount++;
      if (i * i == n) {
        if (factorsCount == k) return i; 
      } else { 
        int j = n / i; 
        if (factorsCount + 1 == k) return j; 
        factorsCount++;
      }
    }
    i++;
  }

  for (; i <= n / i; ++i) {
    if (n % i == 0 && factorsCount + 1 == k) return n / i; 
    factorsCount++;
  }

  return -1;
}
