RIGHTS = // Copyright[2021] <Hyago Gabriel>
NAME = Hyago Gabriel
MAIL = 170105067@aluno.unb.br

IDIR = ./include
SDIR = ./src
ODIR = ./obj

FILE = romano
TESTFILE = testa_romano
HEAD = ROMANO

CC=g++

CFLAGS= -g -I$(IDIR)

_DEPS = $(FILE).hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(FILE).o $(TESTFILE).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

compile: $(OBJ)
	$(CC) -o a.out $^ $(CFLAGS)

all: $(OBJ)
	@ echo "\n\t-------------------------\n\t|\tValgrind:\t|\n\t-------------------------\n";
	@ make valgrind;
	@ echo "\n\t-----------------------------------------\n\t|\tCppcheck: $(TESTFILE).cpp\t|\n\t-----------------------------------------\n";
	@ make checktest;
	@ echo "\n\t---------------------------------\n\t|\tCppcheck: $(FILE).cpp\t|\n\t---------------------------------\n";
	@ make checkfunc;
	@ echo "\n\t---------------------------------\n\t|\tCppcheck: $(FILE).hpp\t|\n\t---------------------------------\n";
	@ make checklib; 
	@ echo "\n\t-----------------------------------------\n\t|\tCpplint: $(TESTFILE).cpp\t|\n\t-----------------------------------------\n";
	@ make linttest;
	@ echo "\n\t---------------------------------\n\t|\tCpplint: $(FILE).cpp\t|\n\t---------------------------------\n";
	@ make lintfunc;
	@ echo "\n\t---------------------------------\n\t|\tCpplint: $(FILE).hpp\t|\n\t---------------------------------\n";
	@ make lintlib;

valgrind: $(OBJ)
	- @ make compile; valgrind -s --leak-check=full ./a.out

exec: $(OBJ)
	- @ make compile; ./a.out

checktest:
	- @ cppcheck $(SDIR)/$(TESTFILE).cpp --enable=warning
	
checkfunc:
	- @ cppcheck $(SDIR)/$(FILE).cpp --enable=warning

checklib:
	- @ cppcheck $(IDIR)/$(FILE).hpp --enable=warning

linttest:
	- @ cpplint $(SDIR)/$(TESTFILE).cpp

lintfunc:
	- @ cpplint $(SDIR)/$(FILE).cpp

lintlib:
	- @ cpplint $(IDIR)/$(FILE).hpp

create:
	@ mkdir $(IDIR);
	@ mkdir $(SDIR);
	@ mkdir $(ODIR);
	@ git init;
	@ git config user.email "$(MAIL)";
	@ git config user.name "$(NAME)";
	@ touch $(IDIR)/$(FILE).hpp;
	@ touch $(SDIR)/$(FILE).cpp;
	@ touch $(SDIR)/$(TESTFILE).cpp;
	@ echo "$(RIGHTS)" > $(IDIR)/$(FILE).hpp;
	@ echo "$(RIGHTS)\n#include \".$(IDIR)/$(FILE).hpp\"" > $(SDIR)/$(FILE).cpp;
	@ echo "$(RIGHTS)\n#include \".$(IDIR)/$(FILE).hpp\"" > $(SDIR)/$(TESTFILE).cpp;
	@ echo "#ifndef INCLUDE_$(HEAD)_HPP_\n#define INCLUDE_"$(HEAD)"_HPP_\n\n#endif  // INCLUDE_"$(HEAD)"_HPP_" >> $(IDIR)/$(FILE).hpp;
	@ git add $(IDIR)/$(FILE).hpp;
	@ git add $(SDIR)/$(FILE).cpp;
	@ git add $(SDIR)/$(TESTFILE).cpp;
	@ git commit -m "Inicial";

sublime:
	@ subl $(IDIR)/*.hpp;
	@ subl $(SDIR)/*.cpp;

clean:
	@ rm -f $(ODIR)/*.o; rm -f ./a.out;
