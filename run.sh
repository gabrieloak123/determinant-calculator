#!/bin/bash

##
# @file run.sh
# 
# @brief Esse arquivo compila e executa o programa principal de maneira segura
#
# Este script solicita ao usuário o nome de um arquivo, verifica a existência
# do diretório `build`, compila o projeto e executa o binário principal com o
# arquivo fornecido como argumento.
##

echo "Digite o nome do arquivo: "
read file

# Verifica se o diretório 'build' não existe e cria se necessário
if [[ ! -d "build" ]]; then
  mkdir build
fi

# Entra no diretório 'build'
cd build 

# Executa CMake e Make
cmake ..
make 

# Executa o programa passando o arquivo como argumento
./determinant-calculator "$file"
