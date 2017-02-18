#include "Passgen.h"

Passgen::Passgen() {
    length = DEFAULT_PASSWORD_LENGTH;
    numbers = DEFAULT_NUMBERS;
    special_characters = DEFAULT_SPECIAL;
    pass_to_write = DEFAULT_PASS_TO_WRITE;
}

Passgen::Passgen(int length_in, int count_in, bool numbers_in, bool spc_in) :
    length(length_in), numbers(numbers_in),
    special_characters(spc_in), pass_to_write(count_in){
    if (length <= 0) length = 1;
}

void Passgen::update_chars() {
    //Adding Upper Case
    for (int i = UPPER_BEGIN_ASCII; i < UPPER_END_ASCII; ++i)
       append_to_chars(i);

    //lower case
    for (int i = LOWER_BEGIN_ASCII; i < LOWER_END_ASCII; ++i)
       append_to_chars(i);

    if (numbers) {
       for (int i = NUMBERS_BEGIN_ASCII; i < NUMBERS_END_ASCII; ++i)
           append_to_chars(i);
   }

   if (special_characters) {
       //Makes sense if you check an ASCII TABLE
       for (int i = 33; i < 48; ++i)
           append_to_chars(i);

       for (int i = 58; i < 65; ++i)
           append_to_chars(i);

       for (int i = 123; i < 127; ++i)
           append_to_chars(i);
   }
}

int get_random_int(int size) {
    std::mt19937 random_gen;
    random_gen.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, size - 1);
    return int(dist(random_gen));
}

void Passgen::write_passwords(int num_passwords) {
    int size = int(acceptable_chars.size());

    if (num_passwords <= 0) return;
    for (int i = 0; i < length; ++i) {
        //gets a random index
        unsigned index = get_random_int(size);
        std::cout << char(acceptable_chars[index]);
    }
    std::cout << "\n";
    write_passwords(num_passwords-1);
}

void Passgen::write_passwords() {
    update_chars();
    write_passwords(pass_to_write);
}

void Passgen::append_to_chars(int add) {
    acceptable_chars.push_back(add);
}
