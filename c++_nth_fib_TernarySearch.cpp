#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

// Matrix structure to store matrix values
struct Matrix{
    int a, b, c, d;
};

// Function to multiply two matrices
Matrix mul(Matrix a, Matrix b)
{
    Matrix c;
    c.a = (1LL * a.a * b.a + 1LL * a.b * b.c) % MOD;
    c.b = (1LL * a.a * b.b + 1LL * a.b * b.d) % MOD;
    c.c = (1LL * a.c * b.a + 1LL * a.d * b.c) % MOD;
    c.d = (1LL * a.c * b.b + 1LL * a.d * b.d) % MOD;
    return c;
}

// Function to find the nth Fibonacci number using ternary search
int fib(int n){
    // Matrix to store Fibonacci values
    Matrix mat = { 1, 1, 1, 0 };

    // Base case: if n is 0, return 0
    if (n == 0)
        return 0;

    // Matrix to store power of mat
    Matrix res = { 1, 0, 0, 1 };

    // Ternary search to find the nth Fibonacci number
    int l = 0, r = n;
    while (l <= r){
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        Matrix res1 = res;
        Matrix res2 = res;

        // Find power of mat ^ mid1
        for (int i = 1; i <= mid1; i <<= 1){
            if (i & mid1)
                res1 = mul(res1, mat);
            mat = mul(mat, mat);
        }

        // Find power of mat ^ mid2
        for (int i = 1; i <= mid2; i <<= 1){
            if (i & mid2)
                res2 = mul(res2, mat);
            mat = mul(mat, mat);
        }

        // If n lies in the range [mid1 + 1, mid2 - 1], return the result
        if (mid1 + 1 <= n && n <= mid2 - 1)
            return res2.a;

        // If n lies in the range [mid2, r], update l and res
        else if (n > mid2)
            l = mid2 + 1, res = res2;

        // If n lies in the range [l, mid1], update r and res
        else
            r = mid1 - 1, res = res1;
    }

    return -1;
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n) << endl;
    return 0;
}
