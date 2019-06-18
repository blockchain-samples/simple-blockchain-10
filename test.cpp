
#include "hash_simple.h"
#include "class-support.h"

#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <iomanip>
#include <cstdlib>
#include <vector>
using std::vector;

int main() {

    // Transaction tx1("rubensaw", "pignonea", 0x1);
    // Transaction tx2("hendrix7", "lengah23", 0x2);
    // Transaction tx3("mirabit0", "mckinn36", 0x3);
    // Transaction tx4("dremannd", "brandlem", 0x4);
    // Transaction tx5("webemal8", "ryannick", 0x5);

    unsigned long var = block_hash(0x0, 0x1, 0x2, 0x3, true);
    cout << var << endl;
    

    
}