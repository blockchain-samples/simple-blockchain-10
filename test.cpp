#include <iostream>
using std::cout; using std::endl;
#include "hash_simple.h"
// #include "block.h"
#include <string>
using std::string;

int main() {
    // union timestamp var;
    // var.str_time = time_now();
    long s, r, d;
    // auto t = 
    s = ID_hash("rubensaw");
    r = ID_hash("pignonea");
    d = 0xe294b000;
    auto t = time_now();
    long hash = tx_hash(s, r, d, t.second);
    cout << tx_hash << endl;


}