#include <iostream>
using namespace std;

using u64 = unsigned long long;
using u128 = __int128_t;

u64 mulmod(u64 a, u64 b, u64 m) {
    return (u64)((u128)a * b % m);
}

// Calcula x^y módulo M
u64 power(u64 x, u64 y, u64 M)
{
    if (y == 0)
        return 1;

    u64 p = power(x, y / 2, M) % M;
    p = mulmod(p, p, M);

    return (y % 2 == 0) ? p : mulmod(x, p, M);
}

bool ehPrimo(u64 n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (u64 i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

u64 proxPrimo(u64 N)
{
    // Caso base
    if (N <= 1)
        return 2;

    u64 primo = N;
    bool achou = false;

    // Procura o próximo primo
    while (!achou) {
        primo++;

        if (ehPrimo(primo))
            achou = true;
    }

    return primo;
}


int main()
{
    u64 n, t;
    cin >> n >> t;

    u64 p = proxPrimo(n);

    // inverso é t^(p-2) módulo p
    cout << power(t, p - 2, p);  

    return 0;
}