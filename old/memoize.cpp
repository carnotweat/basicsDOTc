// via cubbi 
// debugging due
// may help in establishing a full duplex async communication channel
/ This program calculates the nth fibonacci number
// using algorithm 1B: cached binary recursion
//
// compile: g++ -std=c++0x -O2 -o f1b f1b.cc -lgmpxx -lgmp
// executed: ./f1b n

#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <gmpxx.h>
#include <vector>
typedef std::unordered_map<int, mpz_class> memo;

// Naive binary recursion: F(n) = F(n-1) + F(n-2) with memoization
// First checks if the answer is known, reports it if it is known
// then recurses twice, saves the new answer, and returns it.
mpz_class frec(int n, memo& m) {
   memo::iterator i = m.find(n);
   if(i!=m.end()) return i->second;
   return n<2 ? n : m[n] = frec(n-1, m) + frec(n-2, m);
}

// Function fib initializes the memoization data structure and calls frec
mpz_class fib(int n) {
    memo m;
    return frec(n, m);
}

// Function f(n) handles the negative arguments: F(-n) = F(n)*(-1)^(n+1)
mpz_class f(int n) {
    if(n<0)
        return n%2 ? fib(-n) : 0-fib(-n);
    else
        return fib(n);
}

// Function fib_print prints out n'th Fibonacci number
void fib_print(int n) {
    std::cout << n << "th Fibonacci number is "
              << f(n).get_str(10) << '\n';
}
// entry point:
// convert the first argument to a number and calls fib_print
// if argument did not exist or wasn't a number, show usage information
int main(int argc, char** argv) {
    std::vector<std::string> args(argv, argv+argc);
    try {
        fib_print(stoi(args.at(1)));
    } catch (std::exception& ) {
        std::cout << "Usage: " << args[0] << " <n>\n";
    }
}


