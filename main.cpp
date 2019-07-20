
#include "class-support.h"

#include <iostream>
using std::cout; using std::endl; using std::cin;
// #include <string>
// using std::string;
// #include <sstream>
// using std::stringstream;
// #include <iomanip>
// #include <cstdlib>
// #include <vector>
// using std::vector;
// #include<ios>     // for <streamsize> 
// #include<limits> // for numeric_limits 

int main() {
    Blockchain chain;
    int interact = 1;
    // char a, p, v{};
    while (interact){
        Block b;
        while (b._tx_counter < BLX_SZ){
            // printf("Please enter a character \n\t a - add transaction \n\t v - validate block \n\t p - print entire chain")
            // char action{};
            printf("Enter an 8 character netID, followed by a space and the next netID, then a space and a number value\n");
            string s, r;
            long v;
            cin >> s >> r >> v;
            b.add_transaction(s, r, v);
        }
        printf("Block full!\n");
        int approve{};
        printf("Approve this block? (1 = yes : 0 = no) \n");
        cout << b << endl;
        cin >> approve;
        if (approve)
            b.approve();
        else
            break;
        chain.append_block(b);

        printf("New Block Needed, continue? (y - 1 / n - 0)\n");
        cin >> interact;
    }
    chain.view_chain();

}