#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}


long long fibonacci_fast_mod(long long n, long long m) {
    long long a[n];
    a[0] = 0;
    a[1] = 1;
    for (long long i = 2; i <= n; i++){
        a[i] = ((a[i-1] % m) + (a[i-2] % m)) % m;
    }
    return a[n];
}

long long fibonacci_huge_fast(long long n, long long m) {
    if (n == 0){
        return 0;
    }
    long long previous = 0;
    long long current  = 1;
    int period = 0;
    for (long long i = 0; i < n - 1; ++i) {
        period++;
        long long tmp_previous = previous % m;
        previous = current % m;
        current = (tmp_previous + current % m) % m;
        if (previous == 0 && current == 1){
            //std::cout << period << std::endl;
            current = fibonacci_fast_mod(n % period, m);
            break;
        }
    }
    return current;
}

int fibonacci_sum_squares_fast(long long n){
    //std::cout << fibonacci_huge_fast(n+1, 10) << ' ' << fibonacci_huge_fast(n, 10) << std::endl;
    return (fibonacci_huge_fast(n+1, 10) * fibonacci_huge_fast(n, 10)) % 10;
}


int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n) << std::endl;
    std::cout << fibonacci_sum_squares_fast(n) << std::endl ;
}
