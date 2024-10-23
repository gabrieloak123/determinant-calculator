/**
 * @file calculator.h
 *
 * @brief Declara a classe Calculator
 */

#ifndef CALCULATOR_H
# define CALCULATOR_H

# include "./common.h"

namespace det {

/**
 * @struct ElementarProductCols
 *
 * @brief Armazena uma permutação possível e se é necessário um número par de alterações para chegar
 * nela
 */
struct ElementarProductCols {
    /*
     * @brief Lista ordenada que armazena a permutação
     */
    std::vector<int> permutation;
    /*
     * @brief Se o número de alterações para ordenar a permutação é par ou não
     */
    bool mods_even;
};

/**
 * @class Calculator
 *
 * @brief Faz a matemática da matriz
 *
 * É responsável por fazer as operações que tornam possível calcular o determinante
 */
class Calculator {
  public:
    void setup(const Matrix& matrix);
    void calc_determinant();
    void print_result();

  private:
    Matrix m_matrix;
    size_t m_matrix_order;
    int m_det;
    std::vector<ElementarProductCols> m_elementar_products;

    std::vector<int> get_numbers_range(int start, int end);
    void swap(int& a, int& b);
    void verify_minimum_changes(int order, std::vector<int>& permutation, int& changes, int start);
    void get_permuted_list(std::vector<int> current,
                           std::vector<ElementarProductCols>& permuted_lists,
                           int& count,
                           int start,
                           int end);
};

}  // namespace det

#endif  // !CALCULATOR_H
#define CALCULATOR_H
