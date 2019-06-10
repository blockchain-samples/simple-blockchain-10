/***********
 * This is a simple hashing algorithm - 
 * meant to simply provide collision resistant output given two hashes to combine.
 * Additionally a hash generation function given a uniqe string to create a 32-bit value.
 * ********/
#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <ctime>
#include <utility>
using std::pair;

long compression(long arg1, long arg2){
    return (arg1 * arg2) ^ ((arg1 << 3) + (arg2 >> 2));
}

long ID_hash(string name){ //name will be 8 characters + Case 
    //Given a unique string this function returns a uniqe long as a address
    /*****
     * Plan to return to update and make IDs more unique and readable
     * ***/
    string result;
    //convert to uppercase for ASCII code
    string padding = "19"; //magic number
    for(int i = 0; i < 8; i++) {
        name.at(i) = toupper(name.at(i));
    }   
    unsigned int ASCII_rep = 0;
    for (int i=0; i<8; i++){
        //printf("%d\n", (int)name[i]);
        ASCII_rep += (int)name[i];
    }
    result = ( std::to_string(ASCII_rep) + std::to_string(ASCII_rep) ) ;
    return std::stol(result + padding);
}

long tx_hash(long sender_ID, long receiver_ID, long data, long timestamp){
    //hashing transaction data together in a series of compression steps
    //Follows loosely to Merkle-Damgard Construction - description found here: http://www.partow.net/programming/hashfunctions/
    long initial_vector = 0x4cc4310e; //Magic number
    long intermediate1 = compression(initial_vector, sender_ID);
    long intermediate2 = compression(intermediate1, receiver_ID);
    long intermediate3 = compression(intermediate2, data);
    long result = compression(intermediate3, timestamp);

    return result;
}
pair<string, long> time_now(){
    //Given Current time based on Coordinated Universal Time (UTC) in string and long types
    pair<string, long> result;

    time_t timenow = time(0);

    tm *timer = gmtime(&timenow); //pointer to a time_t typed obj - contains time val
    char* utc_time_s = asctime(timer);
    result.first = utc_time_s;

    long utc_time_l = static_cast<long> (timenow);
    result.second = utc_time_l;

    return result;
}