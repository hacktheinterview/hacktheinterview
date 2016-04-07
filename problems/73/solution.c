
int * primesum(int a) {
    int result[2];
    int * isPrime = malloc(sizeof(int) * (a + 1));
    for (int i = 2; i <= a; i++) {
            isPrime[i] = 1;
    }
    for(int i = 2; i <=a; i++) {
        for (int j = 2; i * j <= a; j++) {
            isPrime[i * j] = 0;
        }
    }

    for (int i = 2; i < a; i++) {
        int j = a - i;
        if (isPrime[i] == 1 && isPrime[j] == 1) {
            result[0] = i;
            result[1] = j;
            return result;
        }
    }
    return result;
}

