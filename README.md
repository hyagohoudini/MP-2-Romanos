# Aluno: Hyago Gabriel Oliveira Figueiredo
# Matrícula: 170105067

    ## Padrão adotado:
 - Classes: Com letras maiúsculas
 - Nome dos métodos: Com as iniciais maiúsculas
 - Nome das variáveis: Assim como os métodos, com as iniciais maiúsculas   

## Alterar Implementação:
### Como alterar a implementação:
    #### Basta alterar o define na .hpp
 - define BUSCA_HPP_:	implementação sem calculo, baseado nos dados presentes no txt;
 - define CONVERTER_HPP_: implementação que realmente faz controle dos dados inseridos, com base em contas e exceções, sem depender dos dados baseados no txt;
			
**OBS: IMPLEMENTAÇÃO PADRÃO É: CONVERTER_HPP_**

## COMO RODAR:
### RECOMENDAÇÃO: 
    #### UTILIZAR "make all" no root da pasta do trabalho
 - "make"			- No root da pasta do trabalho para compilar o programa

 - "make exec"		- Para compilar e rodar o trabalho de uma vez só

 - "make valgrind"		- Executa o valgrind (c/ flag -s) no executável do trabalho

 - "make checktest"	- Executa o cppcheck no arquivo testa_.cpp

 - "make checkfunc" 	- Executa o cppcheck no arquivo .cpp

 - "make checklib" 	- Executa o cppcheck no arquivo .hpp

 - "make lintteste" 		- Executa o cpplint no arquivo testa_.cpp

 - "make lintfunc" 		- Executa o cpplint no arquivo .cpp

 - "make lintlib" 		- Executa o cpplint no arquivo .hpp

 - "make all"		- Executa a compilação do programa, junto com as demais verificações ao mesmo tempo
 	  
**IMPORTANTE QUE NÃO HAJA MUDANÇA NOS DIRETÓRIOS PARA UM BOM FUNCIONAMENTO DO PROGRAMA**

## Saída do Programa:
    Resultados de teste do catch
