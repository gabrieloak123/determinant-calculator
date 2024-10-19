#ifndef CALCULATOR_H
# define CALCULATOR_H

# include "./common.h"

namespace det {

struct ElementarProductCols {
    std::vector<int> permutation;
    bool mods_even;
};

class Calculator {
  public:
    std::vector<int> get_numbers_range(int start, int end);
    void swap(int& a, int& b);
    void verify_minimum_changes(int order, std::vector<int>& permutation, int& changes, int start);
    void get_permuted_list(std::vector<int> current,
                           std::vector<ElementarProductCols>& permuted_lists,
                           int& count,
                           int start,
                           int end);
    int calc_determinant();

  private:
    Matrix m_matrix;
    int m_matrix_order;
    std::vector<ElementarProductCols> m_elementar_products;
};

}  // namespace det

#endif  // !CALCULATOR_H
#define CALCULATOR_H
