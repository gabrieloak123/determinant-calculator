#include <cstdlib>
#include <iostream>
#include <vector>

#include "include/calculator.h"
#include "include/common.h"

namespace det {

/**
 * @brief Troca, dentro da memória o valor de 2 variáveis
 *
 * @param a Primeiro inteiro
 * @param b Segundo inteiro
 *
 */
void Calculator::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Inicializa os atributos da classe
 *
 * Dada a matriz que será entrada do programa, preenche o campo "ordem" e o vetor de produtos
 * elementares
 *
 * @param matrix A matriz em que os cálculos serão realizados
 */
void Calculator::setup(const Matrix& matrix) {
    m_matrix = matrix;
    m_matrix_order = matrix[0].size();

    std::vector<ElementarProductCols> permuted_lists;
    std::vector<int> indexes = get_numbers_range(0, m_matrix_order - 1);
    int count = 0;

    get_permuted_list(indexes, permuted_lists, count, 0, indexes.size() - 1);
    m_elementar_products = permuted_lists;
}

/**
 * @brief Mostra na tela o resultado
 *
 * Exibe a matriz de entrada e o seu determinante
 */
void Calculator::print_result() {
    for (const auto& vec : m_matrix) {
        for (const auto element : vec) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "E o determinante é: " << m_det << std::endl;
}

/**
 * @brief Provê uma lista com todos os inteiros entre dois números
 *
 * @param start O primeiro número do intervalo
 * @param end O último número do intervalo
 *
 * @return O vetor referente ao intervalo
 */
std::vector<int> Calculator::get_numbers_range(int start, int end) {
    std::vector<int> set_count;
    for (int i = start; i <= end; i++) {
        set_count.push_back(i);
    }
    return set_count;
}

/**
 * @brief Diz quantas alterações são necessárias para uma lista virar outra
 *
 * Dada uma lista, verifica recursivamente do mínimo de alterações
 */
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

/**
 * @brief Dá todas as permutações possíveis de uma lista
 *
 * Verifica recursivamente todas as possibilidades de permutação de uma lista
 *
 * @param current A permutação que está sendo construída
 * @param permuted_lists A lista que armazena as combinações possíveis
 * @param count Conta quantas permutações foram geradas
 * @param start Índice do começo da lista que está sendo trabalhada no momento
 * @param end Índice do fim da lista que está sendo trabalhada no momento
 */
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

/**
 * @brief Calcula o determinante da matriz
 *
 * Usa o método de soma dos produtos elementares para calcular o determinante
 */
void Calculator::calc_determinant() {
    std::vector<int> rows_index = get_numbers_range(0, m_matrix_order - 1);
    int sum = 0;

    for (size_t i = 0; i < m_elementar_products.size(); i++) {
        std::vector<int> column_indexes = m_elementar_products[i].permutation;
        bool is_positive = m_elementar_products[i].mods_even;
        int loop_result = 1;

        for (size_t j = 0; j < m_matrix_order; j++) {
            loop_result *= m_matrix[rows_index[j]][column_indexes[j]];
        }

        is_positive ? sum += loop_result : sum -= loop_result;
    }

    m_det = sum;
}

}  // namespace det
