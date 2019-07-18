// #include "proj11.h"
#include <iostream> 
#include <string>
#include <algorithm>
#include <vector>
using std::cout; using std::endl; using std::string; using std::vector;
using std::copy;

const int BLOX_SZ = 2;

struct Transaction{
    string sender_ {};
    string reciever_ {};
    long value_ {};

    Transaction(string s, string r, long v){
        sender_=s;
        reciever_=r;
        value_=v;
    }
    Transaction() = default;

    void print(){
        cout << "\tSender: " <<  sender_ <<endl;
        cout << "\tReciever: " << reciever_ << endl;
        cout << "\tValue: " << value_ << endl;
    }
};

struct Block{
    long id_num_ {};
    Transaction list_[BLOX_SZ] {};
    Block* next_{};
    bool valid_ = false;

    Block(long num, Transaction tx_arr[]){
        id_num_ = num;
        for (int i{0}; i<BLOX_SZ; i++){
            list_[i] = tx_arr[i];
        }
    }
    Block(){
        for (int i{}; i<BLOX_SZ; i++){
            list_[i] = Transaction();
        }
        valid_ = true;
    }
    void validate() { valid_ = true;}
    friend class Blockchain;

    void print(){
        cout << "ID: " << id_num_ << endl;
        cout << "TXs:   \n";
        for (int i{}; i<BLOX_SZ; i++){
            list_[i].print();
        }
        cout << "Next B: " << next_ << endl;
        cout << std::boolalpha << "Valid? " <<  valid_ << endl;
    }

};

struct Blockchain{
    long size_{};
    Block* genesis_{};
    Block* current_ {};
    Block* end_{};

    Blockchain(){
        size_= 0;
        Block* gblock = new Block;
        genesis_ = gblock;
        current_ = gblock;
        end_ = gblock;
        gblock->validate();
    }

    void append(Block b){
        Block* n_block = new Block(b.id_num_, b.list_);
        current_->next_ = n_block;
        current_ = n_block;
        size_++;
        n_block->id_num_ = size_;
    }
    void print(){
        for(Block* ptr = genesis_ ;ptr != nullptr; ptr = ptr->next_){
            cout << "LOCATION: " << ptr << endl;
            (*ptr).print();
            cout << "\n";
        }
    }
};

int main(){
    Transaction tx1("saw", "anna", 10);
    Transaction tx2("fenech", "leno", 20);
    Transaction v[BLOX_SZ] = {tx1, tx2};
    Block b1(0, v);

    Transaction tx3("dex", "sean", 11);
    Transaction tx4("reece", "aaron", 21);
    Transaction v1[BLOX_SZ] = {tx3, tx4};
    Block b2(0, v1);

    Blockchain chain;
    chain.append(b1);
    chain.append(b2);
    chain.print();

}