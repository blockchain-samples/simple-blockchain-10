
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

    Transaction tx1("rubensaw", "pignonea", 0x1);
    Transaction tx2("hendrix7", "lengah23", 0x2);
    Transaction tx3("mirabit0", "mckinn36", 0x3);
    Transaction tx4("dremannd", "brandlem", 0x4);
    Transaction tx5("webemal8", "ryannick", 0x5);


    cout << tx1.view() << endl;
    vector<unsigned long> vec = {tx1._hash, tx2._hash, tx3._hash, tx4._hash, tx5._hash};

    auto block_hash = merkle_hash(vec);
    cout << block_hash << endl<< sizeof(block_hash) << endl;

    Block blk(vec);

    cout << blk;

}