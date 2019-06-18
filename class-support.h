#pragma once

#include <string>
using std::string;
#include <ostream>
using std::ostream;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;

class Block;
class Blockchain;

class Transaction{
    private:
    long _sender_ID;
    long _receiver_ID;
    long _value;
    pair<string, long> _timestamp;

    public:
    Transaction() = default;
    Transaction(const string, const string, long);
    unsigned long _hash; 
    string view(); //allows readable version of sender, receiver, value, and timestamp
};

/************
 * TRANSACTION FUNCTIONS 
*************/

//Transaction Constructor
Transaction::Transaction(string sender , string receiver, long value){
    _sender_ID = ID_hash(sender);
    _receiver_ID = ID_hash(receiver);
    _value = value;
    _timestamp = time_now();
    _hash = tx_hash(_sender_ID, _receiver_ID, _value, _timestamp.second);
}

// Read and View a transaction
string Transaction::view(){
    stringstream ss;
    ss << this->_sender_ID << "-->" << this->_receiver_ID << endl;
    ss << "Value of: " << this->_value << "   at: " << this->_timestamp.first << endl;
    return ss.str();
}

class Block{
    private:
    unsigned long tx_array[10];
    Block* _prev_block = nullptr; //while the block_hash_ wraps in previous block, pointers can be used to help understanding 
    Block* _next_block = nullptr; // used to help understanding after blocks have been hashed together

    public:
    Block()=default;
    Block(vector<unsigned long>);
    unsigned long _block_num =0; 
    unsigned long _blockhash =0;
    pair<string, long> _timestamp = {"",0};
    unsigned long _prev_hash =0;
    unsigned long _merkle_root =0;
    bool _valid = false;
    
    bool valid_block();
    void approve();
    bool add_transaction(string, string, unsigned int);

    friend ostream& operator<< (ostream& oss, Block& block){
        oss << "_____________________________________________\n";
        oss << "| Block Number: " << block._block_num << "                           |\n";
        // oss << "| Previous Block Hash: " << block._prev_block->_block_num << " |\n";
        oss << "| Merkle Root Hash: " << block._merkle_root << "    |\n";
        oss << "| Block Validation: " << block._timestamp.first;
        oss << "|___________________________________________|\n";
        return oss;
    }
};

/************
*BLOCK FUNCTIONS 
*********** */

Block::Block(vector<unsigned long> tx_list){
    // _block_num = ; unsure how to approach numbering of blocks???
    _prev_hash = 0; //also unsure how to approach linking of information...

    _merkle_root = merkle_hash(tx_list);
    copy(tx_list.begin(), tx_list.end(), tx_array);
}

void Block::approve(){
    _timestamp = time_now();
    _blockhash = block_hash(this->_merkle_root, _timestamp.second, this->_prev_hash, this->_block_num, this->_valid);
    _valid = true;
}


class Blockchain{
    public:
    Blockchain() = default;
    Blockchain(string);
    Blockchain(vector<unsigned long>); //initialize with Block Hashes - Possible Later functionality
    unsigned long _size = 0;
    unsigned long _current_hash = 0;
    string _purpose = "Default";

    friend class Block;
    bool append_block(const Block&);
    bool valid_chain();
    pair<string, long> validate_record(const string, const string, long value);
};

/*************
 * BLOCKCHAIN FUNCTIONS 
 * ***********/
Blockchain::Blockchain(string purpose){
    _size = 0;
    _current_hash = 0;
    _purpose = purpose;

    Block block = Block();
    block._timestamp = time_now();
    block._valid = true;





}
