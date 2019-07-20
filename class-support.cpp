#include "class-support.h"
#include "hash_simple.h"

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

/************
*BLOCK FUNCTIONS 
*********** */
Block::Block(){
    for (int i{}; i<BLX_SZ; i++) { _tx_array[i] = 0; }
}

Block::Block(const Block& b){
    _block_num = b._block_num;
    _blockhash = b._blockhash;
    _timestamp = b._timestamp;
    _prev_hash = b._prev_hash;
    _merkle_root = b._merkle_root;
    _valid = b._valid;
    for (int i{}; i<BLX_SZ; i++){
        _tx_array[i] = b._tx_array[i];
        _tx_counter = i;
    }
    _prev = b._prev;
    _next = b._next; 
}

bool Block::add_transaction(string sender, string receiver, unsigned int value){
    // auto tx_time = time_now();
    unsigned long tx = tx_hash(ID_hash(sender), ID_hash(receiver), value, time_now().second);
    if (_tx_counter < BLX_SZ){
        _tx_array[_tx_counter] = tx;
        _tx_counter++; 
        return true;
    }
    printf("Block Full - Transaction not added");
    return false;
}

void Block::view(){
    for(int i{}; i<BLX_SZ; i++){
        cout << _tx_array[i] << endl; 
    }
}

void Block::approve(){
    // _block_num = ()++;
    _timestamp = time_now(); 
    _valid = true;
    _merkle_root = merkle_hash(_tx_array);
    _blockhash = block_hash(this->_merkle_root, _timestamp.second, this->_prev_hash, this->_block_num, this->_valid);
    //This function is where I can build in an idea of consensus among the parties
}

bool Block::valid_block(){
    return _valid;
}

/*************
 * BLOCKCHAIN FUNCTIONS 
 * ***********/
Blockchain::Blockchain(){
    printf("Initializing Blockchain\n");
    _size = 0;

    Block* GENESIS_Block = new Block(); //initialize null block
    GENESIS_Block->_timestamp = time_now();
    GENESIS_Block->_valid = true;
    GENESIS_Block->_next = nullptr;

    _current = GENESIS_Block;
    _genesis_ptr = GENESIS_Block;
    
}

bool Blockchain::append_block(Block& block_n){
    if(block_n._valid){
        Block* blx_ptr = new Block(block_n);
        _current->_next = blx_ptr;
        blx_ptr->_prev_hash = _current->_blockhash;
        blx_ptr->_prev = _current;
        _current = blx_ptr;
        _size++;
        blx_ptr->_block_num = _size;
        return true;
    }
    return false;
}

int Blockchain::get_size(){
    return _size;
}

void Blockchain::view_chain(){
    Block* walking_ptr = _genesis_ptr;
    while (walking_ptr != nullptr){
        cout << (walking_ptr) << endl;
        cout << "______________" << endl;
        cout << (*walking_ptr) << endl;
        cout << "v  v   v   v" << endl;
        walking_ptr = walking_ptr->_next;
    }
}
 