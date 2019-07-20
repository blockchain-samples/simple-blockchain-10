#pragma once

#include <iostream>
using std::endl;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;
#include <ostream>
using std::ostream;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <utility>
using std::pair;

const int BLX_SZ = 3;

class Transaction{
    private:
        long _sender_ID = 0;
        long _receiver_ID = 0;
        long _value = 0;
        pair<string, long> _timestamp{{},{}};

    public:
        Transaction() = default; //null transaction ctor
        Transaction(const string, const string, long);

        unsigned long _hash; 

        string view(); //allows readable version of sender, receiver, value, and timestamp
};

class Block{
    public:
        unsigned long _tx_array[BLX_SZ]{};
        int _tx_counter = 0;
        Block* _prev = nullptr; //while the block_hash_ wraps in previous block, pointers can be used to help understanding 
        Block* _next = nullptr; // used to help understanding after blocks have been hashed together

    public:
        Block(); //null block ctor
        Block(const Block&); //copy ctor

        unsigned long _block_num = 0; 
        unsigned long _blockhash = 0;
        pair<string, long> _timestamp {};
        unsigned long _prev_hash = 0;
        unsigned long _merkle_root = 0;
        bool _valid = false;
        
        bool add_transaction(string, string, unsigned int);
        void view();
        void approve();
        bool valid_block();

        friend ostream& operator<< (ostream& oss, Block& block){
            oss << "_____________________________________________\n";
            oss << "| Block Number: " << block._block_num << "                           |\n";
            oss << "| Block Hash:   " << block._blockhash << "         |\n";
            // oss << "| Previous Block Hash: " << block._prev->_block_num << " |\n";
            oss << "| Merkle Root Hash: " << block._merkle_root << "     |\n";
            oss << "| Validation Time: " << block._timestamp.first;
            oss << "| VALID:    " << std::boolalpha << block._valid << "                             |\n"; 
            oss << "|___________________________________________|\n";
            return oss;
        }
        friend class Blockchain;
};


class Blockchain{
    public:
        Blockchain();
        unsigned long _size = 0;
        Block* _current = nullptr;
        Block* _genesis_ptr = nullptr;
        string _name = "Default";

        bool append_block(Block&);
        bool valid_chain();
        int get_size();
        void view_chain();
};
