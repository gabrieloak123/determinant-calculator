#include <iostream>
#include <stdexcept>
#include <string>
#include <strstream>
#include "include/calculator.h"
#include "include/common.h"
#include "include/parser.h"

using namespace det;

int main(int argc, char* argv[]) {
    try {
        if (argc == 2) {
            Calculator calculator;
            std::ostrstream oss;
            oss << "../files/" << argv[1];

            calculator.setup(Parser::parse_file(oss.str()));
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
