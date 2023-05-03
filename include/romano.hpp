// Copyright[2021] <Hyago Gabriel>
#ifndef INCLUDE_ROMANO_HPP_
#define INCLUDE_ROMANO_HPP_

#include <iostream>
#include <string>

// Mudar implementação da conversão
#define BUSCA_HPP_
// #define CONVERTE_HPP_

#ifdef CONVERTE_HPP_

#include <cstring>
#include <map>

// Método onde uma string no formato de números romanos é inserida
// Retorno: numero int correspondente ao numero romano inserido
int romanToArabic(std::string);

// Método onde uma string no formato de números romanos é inserida
// Retorno true se a string passar na verificação de entrada válida
bool entradaValida(std::string);

#endif  // CONVERTE_HPP_

#ifdef BUSCA_HPP_

#include <fstream>
#include <sstream>

// Método onde uma string no formato de números romanos é inserida
// Retorno true se a string passar na verificação de entrada válida
bool entradaValida(std::string roman);

// Método sem retorno que procura o parametro string dentro de
// (...) um arquivo txt com os numeros romanos de 1-3000
// O resultado da busca é posto dentro de outro arquivo txt
void search(std::string roman);

// Método onde uma string no formato de números romanos é inserida
// Retorno: numero int correspondente ao numero romano inserido
int romanToArabic(std::string roman);

#endif  // BUSCA_HPP_

#endif  // INCLUDE_ROMANO_HPP_
