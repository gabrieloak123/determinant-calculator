#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "include/common.h"

std::string remove_extra_spaces(const std::string& line) {
    std::stringstream oss;
    bool in_space = false;

    for (char character : line) {
        if (character != ' ') {
            oss << character;
            in_space = false;
        } else if (!in_space) {
            oss << " ";
            in_space = true;
        }
    }

    return oss.str();
}

int safe_stoi(const std::string& stoi_candidate) {
    try {
        return std::stoi(stoi_candidate);
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Bad input");
    }
}
std::vector<int> string_to_vector(const std::string& line) {
    std::vector<int> vec;
    std::ostringstream oss;

    for (size_t i = 0; i < line.length(); ++i) {
        if (line[i] == ' ') {
            if (!oss.str().empty()) {
                vec.push_back(safe_stoi(oss.str()));

                // Cleaning buffer
                oss.str("");
                oss.clear();
            }
        } else {
            oss << line[i];

            // To push the last value
            if (i == line.length() - 1 && !oss.str().empty()) {
                vec.push_back(std::stoi(oss.str()));
            }
        }
    }

    return vec;
}

std::ifstream open_file(const std::string& file_path) {
    std::ifstream file(file_path);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file " + file_path);
    }

    return file;
}

std::string trim(std::string line) {
    line.erase(0, line.find_first_not_of(' '));
    line.erase(line.find_last_not_of(' ') + 1);
    return line;
}

bool are_lengths_the_same(const det::Matrix& matrix, const std::vector<int>& vec) {
    for (const auto& matrix_vec : matrix) {
        if (vec.size() != matrix_vec.size()) {
            return false;
        }
    }

    return true;
}

det::Matrix parse_file(const std::string& file_path) {
    det::Matrix matrix;
    std::ifstream file = open_file(file_path);
    std::string line;

    while (getline(file, line)) {
        // trim sides
        if (!trim(line).empty()) {
            std::vector<int> line_vector = string_to_vector(line);

            if (!are_lengths_the_same(matrix, line_vector)) {
                throw std::logic_error("Different size lines inputed");
            }
            // TODO: crash if not square
            matrix.push_back(string_to_vector(line));
        }
    }
    if (matrix[0].size() != matrix.size()) {
        throw std::logic_error("Cant calculate the determinant of a non square matrix");
    }
    return matrix;
}
void print_matrix(const det::Matrix& matrix) {
    for (const auto& vec : matrix) {
        for (const auto& element : vec) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    det::Matrix mat = parse_file("test.txt");

    print_matrix(mat);
    return 0;
}
