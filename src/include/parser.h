#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

#include "./common.h"

namespace det {

class Parser {
  public:
    static Matrix parse_file(const std::string& file_path);
    static std::vector<int> string_to_vector(const std::string& line);
    static std::ifstream open_file(const std::string& file_path);
    static std::string remove_extra_spaces(const std::string& line);
    static int safe_stoi(const std::string& stoi_candidate);
};
}  // namespace det
#endif  // !PARSER_H
