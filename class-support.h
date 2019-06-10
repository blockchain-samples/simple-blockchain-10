#pragma once

#include <iostream>
#include <string>
using std::string;
#include <chrono>

class Transaction{
    public:
    Transaction() = default;
    string _hash;
    pair<string, long> _timestamp;
    public:
    long _sender_ID;
    long _receiver_ID;
    long value_;
}

class Block{
    public:
    Block()=default;
    //Block(initializer_list<string>);
    string hash_;
    string timestamp_;
    Block* prev_block_ = nullptr; //while the block_hash_ wraps in previous block, pointers can be used to help understanding 
    Block* next_block_ = nullptr; // used to help understanding after blocks have been hashed together

    string get_hash();
    bool is_valid();
    string hash(Block);
    void fill_block(initializer_list<T>)
};

