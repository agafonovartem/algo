#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
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

// using Pisano period
long long fibonacci_huge_fast(long long n, long long m) {
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
    
    //std::cout << period << std::endl;
    //
    
}

int main() {
    /*
    while (true) {
        long long n = rand() % 100 + 2;
        long long m = rand() % 100 + 2;
        std::cout << n << " " << m << "\n";
        long long res1 = get_fibonacci_huge_naive(n, m);
        long long res2 = fibonacci_huge_fast(n, m);
        if (res1 != res2){
            std::cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else{
            std::cout << "OK \n";
        }
    }
     */
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << fibonacci_huge_fast(n, m) << '\n';
}
