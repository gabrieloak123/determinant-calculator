#include <algorithm>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "include/parser.h"

namespace det {

/**
 * @brief Remove os espaços em brancos dentro de uma string
 *
 * @param line A string que deve ser formatada
 *
 * @return A string formatada
 */
std::string Parser::remove_extra_spaces(const std::string& line) {
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

/**
 * @brief Faz conversão de string para inteiro
 *
 * Função feita apenas para personalizar o tratamento de erros padrão da stoi
 * @param stoi_candidate A string que pode ser convertida
 *
 * @return O inteiro resultante da string
 */
int Parser::safe_stoi(const std::string& stoi_candidate) {
    try {
        return std::stoi(stoi_candidate);
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Bad input");
    }
}

/*
 * @brief Criar um vetor a partir de uma string
 *
 * @param line A string que pode ser convertida
 *
 * @return O vetor de inteiros correspondente
 */
std::vector<int> Parser::string_to_vector(const std::string& line) {
    std::vector<int> vec;
    std::ostringstream oss;

    for (size_t i = 0; i < line.length(); ++i) {
        if (line[i] == ' ') {
            if (!oss.str().empty()) {
                vec.push_back(safe_stoi(oss.str()));

                // Limpando buffer
                oss.str("");
                oss.clear();
            }
        } else {
            oss << line[i];

            // Forçando os últimos elementos a serem adicionados
            if (i == line.length() - 1 && !oss.str().empty()) {
                vec.push_back(std::stoi(oss.str()));
            }
        }
    }

    return vec;
}

/*
 * @brief Começa um stream de arquivos
 *
 * Função feita para personalizar o tratamento de erros do stream padrão
 * @param file_path O caminho do arquivo da operação
 *
 * @return Um stream do arquivo
 */
std::ifstream Parser::open_file(const std::string& file_path) {
    std::ifstream file(file_path);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file " + file_path);
    }

    return file;
}

/**
 * @brief Tira os espaços em branco das extremidades de uma string
 *
 * @param line A string que deve ser formatada
 *
 * @return A string formatada
 */
std::string Parser::trim(std::string line) {
    line.erase(0, line.find_first_not_of(' '));
    line.erase(line.find_last_not_of(' ') + 1);
    return line;
}

/**
 * @brief Verifica de um vetor tem o mesmo tamanho de todas as linhas de uma matriz
 *
 * @param matrix A matrix da operação
 * @param vec O vetor da operação
 *
 * @return O booleano correpondente
 */
bool Parser::are_lengths_the_same(const Matrix& matrix, const std::vector<int>& vec) {
    for (const auto& matrix_vec : matrix) {
        if (vec.size() != matrix_vec.size()) {
            return false;
        }
    }

    return true;
}

/**
 * @brief Converte um arquivo em uma matriz
 *
 * @param file_path O caminho do arquivo a ser convertido
 *
 * @return A matriz correspondente
 */
Matrix Parser::parse_file(const std::string& file_path) {
    Matrix matrix;
    std::ifstream file = open_file(file_path);
    std::string line;

    while (getline(file, line)) {
        // trim sides
        if (!trim(line).empty()) {
            std::vector<int> line_vector = string_to_vector(line);

            // Verifying if rows of different sizes were inputed
            if (!are_lengths_the_same(matrix, line_vector)) {
                throw std::logic_error("Different size lines inputed");
            }
            matrix.push_back(string_to_vector(line));
        }
    }

    // Verifying if the number of cols match the number of rows
    if (matrix[0].size() != matrix.size()) {
        throw std::logic_error("Cant calculate the determinant of a non square matrix");
    }

    return matrix;
}
};  // namespace det
