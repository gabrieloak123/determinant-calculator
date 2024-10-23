/**
 * @file parser.h
 *
 * @brief Declara a classe Parser
 */

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

#include "./common.h"

namespace det {

/**
 * @class Parser
 *
 * @brief Faz a conversão do .txt para dados na memória
 */
class Parser {
  public:
    static Matrix parse_file(const std::string& file_path);

  private:
    static bool are_lengths_the_same(const Matrix& matrix, const std::vector<int>& vec);
    static int safe_stoi(const std::string& stoi_candidate);
    static std::vector<int> string_to_vector(const std::string& line);
    static std::ifstream open_file(const std::string& file_path);
    static std::string remove_extra_spaces(const std::string& line);
    static std::string trim(std::string line);
};
}  // namespace det
#endif  // !PARSER_H
