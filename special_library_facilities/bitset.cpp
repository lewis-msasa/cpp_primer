#include <iostream>
#include <bitset>

using namespace std;

/*
BITSET
- used for bit operations
*/


int main(int argc, char** argv){

    bitset<32> bitVec(1U);



    bitset<8> bits(42); // 42 in binary is 00101010
    std::cout << "Initial bitset: " << bits << std::endl;

    // Accessing bits
    std::cout << "Bit at position 1: " << bits[1] << std::endl; // Outputs 1

    // Modifying bits
    bits.set(0);  // Set the bit at position 0 to 1
    bits.reset(1); // Set the bit at position 1 to 0
    bits.flip(2); // Flip the bit at position 2 (1 becomes 0, and 0 becomes 1)

    std::cout << "Modified bitset: " << bits << std::endl;


    //init a bitset from an unsigned value
    bitset<13> bitvec1(0xbeef); // bits are 1111011101111

    bitset<20> bitvec2(0xbeef); // bits are 00001011111011101111


    bitset<32> bitvec(1U); // 32 bits; low-order bit is 1, remaining bits are 0 bool is_set = bitvec.any(); // true, one bit is set
    bool is_not_set = bitvec.none(); // false, one bit is set
    bool all_set = bitvec.all(); // false, only one bit is set
    size_t onBits = bitvec.count(); // returns 1
    size_t sz = bitvec.size(); // returns 32
    bitvec.flip(); // reverses the value of all the bits in bitvec
    bitvec.reset();  // sets all the bits to 0
    bitvec.set(); // sets all the bits to 1

    unsigned long ulong = bitvec.to_ulong(); cout << "ulong = " << ulong << endl;



    return 0;
}