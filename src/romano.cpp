// Copyright[2021] <Hyago Gabriel>
#include "../include/romano.hpp"

#ifdef BUSCA_HPP_

bool entradaValida(std::string roman) {
    if (roman.empty()) return false;

    if (roman == " ") return false;

    if (roman.length() < 1 || roman.length() > 30) {
        return false;
    }

    for (unsigned int i = 0; i < roman.length(); i++) {
        if (std::isdigit(roman.at(i))) {
            return false;
        }
    }

    return true;
}

void search(std::string roman) {
    // command é declarado como o comando que sera mandado para o terminal
    std::string command = "grep  ./dados/data.txt -w > ./dados/busca.txt";
    // a string é inserida no comando listado na linha de cima
    command.insert(5, roman);
      // o comando é enviado ao terminal
    system(command.c_str());
}

int romanToArabic(std::string roman) {
    if (!entradaValida(roman)) {
        return -1;
    }

    // a string é buscada no arquivo txt
    search(roman);

    std::ifstream file;
    int aux = 0;
    file.open("./dados/busca.txt");

    if (!file.is_open()) return -1;

    char numero[10] = {'0'};
    // a primeira palavra do arquivo busca.txt é atribuida ao numero
    file >> numero;
    file.close();
    // a string em numero é convertida para algarismos arabicos
    std::istringstream(numero) >> aux;
    // se parâmetro não for encontrada, o arquivo busca.txt estará vazio
    if (aux == 0 )
        aux = -1;
        // logo, precisamos alterar para o retorno considerado como erro
    return aux;
}

#endif  // BUSCA_HPP_


#ifdef CONVERTE_HPP_

int romanToArabic(std::string roman) {
    if (!entradaValida(roman)) return -1;
    int soma = 0, numero;

    // há um mapeamento de equivalência entre os char e os inteiros
    std::map<char, int> valor;
    valor.insert(std::make_pair('I', 1));
    valor.insert(std::make_pair('V', 5));
    valor.insert(std::make_pair('X', 10));
    valor.insert(std::make_pair('L', 50));
    valor.insert(std::make_pair('C', 100));
    valor.insert(std::make_pair('D', 500));
    valor.insert(std::make_pair('M', 1000));

    for (unsigned int i = 0; i < roman.length(); ) {
        if (i == (roman.length()-1) || valor[roman[i]] >= valor[roman[i+1]]) {
            numero = valor[roman[i]];
            i++;
        } else {
            numero = valor[roman[i+1]] - valor[roman[i]];
            i+=2;
        }
        soma += numero;
    }

    if (soma > 3000) return -1;
    return soma;
}

bool entradaValida(std::string roman) {
    if (roman.length()< 1 || roman.length()>30) return false;
    // contadores de ocorrencia para cada algarismo primario
    int contaI, contaX, contaC, contaM;
    contaI = contaX = contaC = contaM = 0;
    for (unsigned int i = 0; i < roman.length(); i++) {
        switch (roman.at(i)) {
            case 'I':
                if (!(i == roman.length()-1)) {
                    // verifica se há ocorrência de algum char não permitido
                    if (strchr("LCDM", roman.at(i+1)) != NULL)
                        return false;
                }
                contaI++;
                if (contaI == roman.length() && contaI >3)
                    return false;
                if (contaI == 2) {
                    if (!(i == roman.length()-1) && roman.at(i+1) != 'I')
                        return false;
                    else if (roman.at(i-1) != 'I')
                        return false;
                }
                break;
            case 'V':
                if (i == roman.length()-1) break;
                if (strchr("VXLCDM", roman.at(i+1)) != NULL)  // idem linha 96
                    return false;
                break;
            case 'X':
                if (!(i == roman.length()-1)) {
                    if (strchr("DM", roman.at(i+1)) != NULL)  // idem linha 96
                        return false;
                }
                contaX++;
                if (contaX == roman.length() && contaX >3)
                    return false;
                else if (!(i == roman.length()-1) && contaX == 2)
                    if (strchr("LCDM", roman.at(i+1)))  // idem linha 96
                        return false;
                break;
            case 'L':
                if (i == roman.length()-1) break;
                if (!(i == roman.length()-1)) {
                    if (strchr("LCDM", roman.at(i+1)) != NULL)  // idem linha 96
                        return false;
                }
                break;
            case 'C':
                contaC++;
                if (contaC == roman.length() && contaC >3)
                    return false;
                break;
            case 'D':
                if (i == roman.length()-1) break;
                if (strchr("DM", roman.at(i+1)) != NULL)  // idem linha 96
                    return false;
                if (roman.at(i) == roman.at(i+1))
                    return false;
                break;
            case 'M':
                contaM++;
                if (contaM >3)
                    return false;
                break;
            default:
                return false;
        }
    }
    return true;
}

#endif  // CONVERTER_HPP_
