#include "Passgen.h"
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;


/////////// DEFAULTS ////////////////////
const bool INCLUDE_NUMEBRS_DEFAULT = true;
const bool INCLUDE_SYMBOLS_DEFAULT = true;
const int PASSWORD_DEFAULT_LENGTH = 128;
const int PASSWORDS_TO_WRITE = 1;
const string VERBOSE =
    "Usage: Passgen [count] [length]\n"
    "-b           A basic password with letters and numbers.\n"
    "-c           The number of passwords to generate.\n"
    "-d           Hide the message from output.\n"
    "-i           Open Passgen in interactive mode.\n"
    "-l           Length of the generated password.\n"
    "-n           Include numbers in generated passwords.\n"
    "-s           Include symbols in generated passwords.\n";


bool yes_or_no_to_bool(char i) {
    if (i == 'y' || i == 'Y') return true;
    return false;
}

void print_computation(bool def, int count, int length,
  bool numbers, bool symbols) {
    cout << "===========================\n";
    if (def)
        cout << "USING DEFAULT SETTINGS:\n";

    cout << "Generating " << count << " password(s).\n"
         << "Length: " << length << " characters.\n";

    numbers ? cout << "Including Numbers\n" :
        cout << "Excluding Numbers\n";

    symbols ? cout << "Including Symbols\n" :
        cout << "Excluding Symbols\n";

    cout << "===========================\n";
}

void interactive() {
    /***
        Prompts users for input, generates passwords, then exits(0).
    ***/
    int count, length; bool numbers, symbols; char y;

    cout << "How many passwords should I write: ";
    cin >> count;

    cout << "How long should each password be: ";
    cin >> length;

    cout << "Should I include numbers [Y/n]: ";
    cin >> y;
    numbers = yes_or_no_to_bool(y);

    cout << "Should I include symbols [Y/n]: ";
    cin >> y;
    symbols = yes_or_no_to_bool(y);

    Passgen passgen(length, count, numbers, symbols);
    print_computation(false, count, length, numbers, symbols);
    passgen.write_passwords();
    exit(0);
    return;
}

bool read_flags(int argc, char * argv[], int & count,
    int & length, bool & numbers, bool & symbols, int & output) {
    int flag;
    bool prompt = true;
    while ((flag = getopt(argc, argv, "bhindsc:l:")) != EOF) {
        switch (flag) {
            case 'b':
                numbers = true;
                symbols = false;
                break;
            case 'c':
                count = atoi(optarg); break;
            case 'd':
                prompt = false;
                break;
            case 'i':
                break;
            case 'l':
                length = atoi(optarg);
                break;
            case 'n':
                numbers = true;
                break;
            case 's':
                symbols = true;
                break;
            default:
                cout << VERBOSE << endl;
                exit(1);
                break;
        }
        if (flag == 'i') {
            output = flag;
            //Stop checking the flags
            return true;
        }
    }
    return prompt;
}

int main(int argc, char * argv[]) {
    bool numbers(INCLUDE_NUMEBRS_DEFAULT), symbols(INCLUDE_SYMBOLS_DEFAULT);
    int num_passwords_to_write(PASSWORDS_TO_WRITE);
    int password_length(PASSWORD_DEFAULT_LENGTH), flag(0);
    bool advanced = false;

    if (argc == 1) {
      Passgen passgen(password_length, numbers,
          symbols, num_passwords_to_write);
      print_computation(true, num_passwords_to_write, password_length,
          numbers, symbols);
      passgen.write_passwords();
      return 0;
    }

    //Passgen [count] [length]
    if (argc == 3 && atoi(argv[1]) > 0 && atoi(argv[2]) > 0) {
        num_passwords_to_write = atoi(argv[1]);
        password_length = atoi(argv[2]);
        advanced = true;
    }

    bool prompt = true;

    if (!advanced)
        prompt = read_flags(argc, argv, num_passwords_to_write, password_length,
         numbers, symbols, flag);

    if (flag == 'i')
        interactive();

    Passgen passgen(password_length, num_passwords_to_write,
        numbers, symbols);
    if (prompt)  {
        print_computation(false, num_passwords_to_write, password_length,
            numbers, symbols);
    }

    passgen.write_passwords();

    return 0;
}
