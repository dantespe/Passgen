#ifndef PASSGEN_H
#define PASSGEN_H

#include <iostream>
#include <vector>
#include <random>

const int DEFAULT_PASSWORD_LENGTH = 32;
const bool DEFAULT_NUMBERS = true;
const bool DEFAULT_SPECIAL = true;
const bool DEFAULT_PASS_TO_WRITE = 1;


//[begin, end)
//i.e [1, 3) represents set of {1, 2}
const int UPPER_BEGIN_ASCII = 65;
const int UPPER_END_ASCII = 91;

const int LOWER_BEGIN_ASCII = 97;
const int LOWER_END_ASCII = 123;

const int NUMBERS_BEGIN_ASCII = 48;
const int NUMBERS_END_ASCII = 58;

//Special chars
//[33, 48)
//[58, 65)
//[91, 97)
//[123, 127)

class Passgen {
public:
    Passgen();
    Passgen(int length_in, int count_in,
            bool numbers_in, bool spc_in);
    void write_passwords();

private:
    //A vector of all the ascii numbers in the set of chars
    std::vector<int> acceptable_chars;
    std::mt19937 random_gen;
    int pass_to_write;
    int length; //length of the passwors
    bool numbers; //where it has [0-9]
    bool special_characters; //@ , ./ > etc
    bool seeded;

    int get_random_int(); 
    void update_chars();
    void append_to_chars(int add);
    void write_passwords(int num_passwords);
};

#endif
