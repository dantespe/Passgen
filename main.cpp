#include "Passgen.h"
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <GetOpt.h>
using namespace std;

const bool INCLUDE_NUMEBRS_DEFAULT = false;
const bool INCLUDE_SYMBOLS_DEFAULT = false;
const int PASSWORD_DEFAULT_LENGTH = 128;
const int PASSWORDS_TO_WRITE = 1;
const char *VERBOSE =
    "Usage: Passgen\n"
    "-c           The number of passwords to generate.\n"
    "-i           Open Passgen in interactive mode.\n"
    "-l           Length of the generated password.\n"
    "-n           Include numbers in generated passwords.\n"
    "-s           Include symbols in generated passwords.\n";

bool yes_or_no_to_bool(char i) {
    if (i == 'y' || i == 'Y')
        return true;
    return false;
}

void interactive(Passgen & passgen) {
    int x; char y;
    cout << "How many passwords should I write: ";
    cin >> x;
    passgen.pass_to_write = x;

    cout << "How long should each password be: ";
    cin >> x;
    passgen.set_length(x);

    cout << "Should I include numbers [Y/n]: ";
    cin >> y;
    passgen.set_numbers(yes_or_no_to_bool(y));

    cout << "Should I include symbols [Y/n]: ";
    cin >> y;
    passgen.set_spc(yes_or_no_to_bool(y));
    return;
}

int main(int argc, char * argv[]) {
    srand(time(0)); //Needed to generate "random" numbers
    bool numbers(INCLUDE_NUMEBRS_DEFAULT), symbols(INCLUDE_SYMBOLS_DEFAULT);
    int num_passwords_to_write(PASSWORDS_TO_WRITE);
    int password_length(PASSWORD_DEFAULT_LENGTH);

    //Create PAssgen
    if argc == 1;
    int operation;

    while ((operation = getopt(argc, argv, "c:il:ns") != EOF) {
        switch (operation) {
            case 'c':
                num_passwords_to_write
        }
    }
    passgen.write_passwords();
    return 0;
}
