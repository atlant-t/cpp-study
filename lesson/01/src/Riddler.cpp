/* Lesson 01
 * C++ Basics
 *
 * This program conceives a random number.
 * Then the program tells the user what manipulations
 * was performed with these number and what she got in the end.
 * The user must know the conceived number.
 */
#include <iostream>

int main() {
    // The pseudo-random number generator is initialized using the argument passed as seed.
    // http://www.cplusplus.com/reference/cstdlib/rand/
    srand(time(NULL));

    std::cout << "I conceived a two-digit number.\n";

    int secretNumber{(rand() % 90 + 10)};
    int calculatedNumber{0};

    std::cout << "Multiplied the number of tens by 2.\n";
    calculatedNumber = secretNumber / 10 * 2;

    std::cout << "Added 5 to the result.\n";
    calculatedNumber = calculatedNumber + 5;

    std::cout << "Multiplied this amount by 5.\n";
    calculatedNumber = calculatedNumber * 5;

    std::cout << "Added 10 and units from the conceived number.\n";
    calculatedNumber = calculatedNumber + 10;
    calculatedNumber = calculatedNumber + (secretNumber % 10);

    std::cout << "As a result, I got the number " << calculatedNumber << ".\n";

    std::cout << "What number did I conceived? ";

    int answer;
    std::cin >> answer;

    std::cout << (answer == secretNumber ? "Aright!" : "Wrong.") << " "
              << "I conceived " << secretNumber << ".\n";

    return 0;
}
