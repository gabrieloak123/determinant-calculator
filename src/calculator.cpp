#include <cstdlib>
#include <iostream>
#include <vector>

#include "include/calculator.h"
#include "include/common.h"

namespace det {

void Calculator::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

std::vector<int> Calculator::get_numbers_range(int start, int end) {
    std::vector<int> set_count;
    for (int i = start; i <= end; i++) {
        set_count.push_back(i);
    }
    return set_count;
}

void Calculator::verify_minimum_changes(int order,
                                        std::vector<int>& permutation,
                                        int& changes,
                                        int start) {
    if (start >= order - 1) {
        return;
    }

    int min_index = start;
    for (int i = start + 1; i < order; i++) {
        if (permutation[i] < permutation[min_index]) {
            min_index = i;
        }
    }

    if (min_index != start) {
        swap(permutation[min_index], permutation[start]);
        changes++;
    }

    verify_minimum_changes(order, permutation, changes, start + 1);
}

void Calculator::get_permuted_list(std::vector<int> current,
                                   std::vector<ElementarProductCols>& permuted_lists,
                                   int& count,
                                   int start,
                                   int end) {
    if (start == end) {
        ElementarProductCols temp;
        temp.permutation = current;

        // Calcular o número de trocas mínimas para ordenar a permutação
        int changes = 0;
        std::vector<int> perm_copy = current;

        verify_minimum_changes(current.size(), perm_copy, changes, 0);

        temp.mods_even = (changes % 2 == 0);  // Verificar se as trocas são pares

        permuted_lists.push_back(temp);
        count++;
    } else {
        for (int i = start; i <= end; i++) {
            swap(current[start], current[i]);
            get_permuted_list(current, permuted_lists, count, start + 1, end);
            swap(current[start], current[i]);
        }
    }
}

int Calculator::calc_determinant() {
    std::vector<int> rows_index = get_numbers_range(0, m_matrix_order - 1);
    int sum = 0;

    for (const auto& [permutation, is_even] : m_elementar_products) {
        int loop_result = 1;

        for (size_t i = 0; i < m_matrix_order; i++) {
            loop_result *= m_matrix[rows_index[i]][permutation[i]];
        }

        is_even ? sum += loop_result : sum -= loop_result;
    }

    return sum;
}

void print(const std::vector<ElementarProductCols>& mat) {
    for (const auto& vec : mat) {
        vec.mods_even ? std::cout << "Par - " : std::cout << "Ímpar - ";
        for (const auto& element : vec.permutation) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

}  // namespace det

int main() {
    /*int order = 0;*/
    /**/
    /*std::cin >> order;*/
    /**/
    /*std::vector<int> list_to_permute = get_numbers_range(1, order);*/
    /*std::vector<ElementarProductCols> permuted_arrays;*/
    /*int count = 0;*/
    /**/
    /*get_permuted_list(list_to_permute, 0, order - 1, permuted_arrays, count);*/
    /**/
    /*print(permuted_arrays);  // Exibe as permutaçõe*/
    return 0;
}
