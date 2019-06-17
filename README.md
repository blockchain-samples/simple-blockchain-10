# EZ-blockchain
A blockchain network, meant to serve educational and testing purposes

In this code base, I intend to create a C++ implementation of a blockchain. I go about this project with the intention to try things and
simplify a blockchain. Through this project, I will use my own hashing algorithms and list my assumptions and shortfalls relative to security, privacy, tracability, etc. 

Eventually, this code base will be updated with a front end UI. 

My goal is to create some working trial of a blockchain mostly as a test for myself. 

ASSUMPTIONS:

1. Hashing Algorithm is easily breakable - This algorithm is intended as a translation for strings and to compress other variables. In this regard, I am strictly using it as a demonstration - These hashing algorithms can be substituted out for SHA-256 or another more secure hashing algorithm

2. Blocks are validated only by the user, in a real network this consensus is needed among the several participants. I chose to implement this code base in this way to stay away from Proof-of-Work and Proof-of-Stake consensus mechanisms. I believe there are several new methods that would be suited better for different networks. As these developments occur, I simply chose to omit a true consensus mechanism - but it would be built into the "Validate Block" method of the block class.

3. The Transaction class currently only stores Sender, Receiver, Timestamp, and Value. The Value attribute is intended currently to only represent a number - However, writing another "Records/Assets" class, Value can be substituted for these Assets/Records and implement more data functionality beyond a value based transaction blockchain. 
