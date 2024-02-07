#include <iostream>
using namespace std;

class Recursion
{
public:
    int Factorial(int n)
    {
        if (n > 0)
        {
            return (n * Factorial(n - 1));
        }
        else
        {
            return 1;
        }
    }
    int FibonacciSeries(int a, int b, int c, int n)
    {
        cout << a << "\t";
        n--;
        c = a + b;
        a = b;
        b = c;
        if (n > 0)
        {
            return FibonacciSeries(a, b, c, n);
        }
        else
        {
            return a;
        }
    }
    int TailFactorial(int n, int fact)
    {
        fact *= n;
        if (n > 1)
        {
            return TailFactorial(n - 1, fact);
        }
        else
        {
            return fact;
        }
    }
    int Fibonacci(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        return (Fibonacci(n - 1) + Fibonacci(n - 2));
    }
    int TailFibonacci(int a, int b, int n)
    {
        if (n == 0)
        {
            return a;
        }
        if (n == 1)
        {
            return b;
        }
        return TailFibonacci(b, a + b, n - 1);
    }
    int towerOfHanoi(int discs, char src, char dest, char aux)
    {
        if (discs == 1)
        {
            cout << "Move from " << src << " to " << dest << "\n";
        }
        else
        {
            towerOfHanoi(discs - 1, src, aux, dest);
            towerOfHanoi(1, src, dest, aux);
            towerOfHanoi(discs - 1, aux, dest, src);
        }
    }
};

int main()
{
    Recursion R1;
    // cout << "Factorial is: " << R1.TailFactorial(2, 1);
    // cout << "Fib:" << endl
    //      << R1.Fibonacci(3, 3, 0, 10);
    // TailFibonacci and Fibonacci are basically the same for me?
    // R1.towerOfHanoi(5, 'A', 'B', 'C');
    R1.FibonacciSeries(0, 1, 0, 8);
    cout << "\n 7th is : \n"
         << R1.Fibonacci(7);
    cout << "\n 7th is : \n"
         << R1.TailFibonacci(0, 1, 3);

    return 0;
}