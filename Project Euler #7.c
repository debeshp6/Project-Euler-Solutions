#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
    int N_upper_bound = 10001;  // 10001 (+ 1) for Project Euler Problem
    long int limit = ceil(N_upper_bound *
                          (log(N_upper_bound) + log(log(N_upper_bound))));

    bool numbers[++limit];
    memset(numbers, true, (limit) * sizeof(bool));
    long int primes[N_upper_bound];
    int primes_count = 0;

    int T, N;
    scanf("%d", &T);
    for (int _ = 0; _ < T; _++) {
        scanf("%d", &N);
        if (primes_count >= N) {
            printf("%ld\n", primes[N - 1]);
            continue;
        }
        long int number = 2;
        if (primes_count != 0) {
            number = primes[primes_count - 1] + 1;
        }
        for (; number < limit; number++) {
            if (numbers[number]) {
                primes[primes_count++] = number;
                for (long int multiple = number * number; multiple < limit;
                     multiple += number) {
                    numbers[multiple] = false;
                }
                if (primes_count == N) {
                    printf("%ld\n", number);
                    break;
                }
            }
        }
    }
    return 0;
}
