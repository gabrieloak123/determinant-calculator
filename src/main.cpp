#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "include/calculator.h"
#include "include/common.h"
#include "include/parser.h"

using namespace det;

int main(int argc, char* argv[]) {
    try {
        if (argc == 1) {
            Parser parser;
            Calculator calculator;

            calculator.setup(parser.parse_file(argv[0]));
            calculator.calc_determinant();
            calculator.print_result();

        } else {
            throw std::length_error("Invalid arguments");
        }
    }

    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
