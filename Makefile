OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Bici.o Estacion.o Cjt_Bicis.o Bicing.o
	g++ -o program.exe program.o Bici.o Estacion.o Cjt_Bicis.o Bicing.o $(OPCIONS)

Bici: Bici.cc
	g++ -c Bici.o Bici.cc $(OPCIONS)

Estacion: Estacion.cc
	g++ -c Estacion.o Estacion.cc $(OPCIONS)

Cjt_Bicis: Cjt_Bicis.cc
	g++ -c Cjt_Bicis.o Cjt_Bicis.cc $(OPCIONS)

Bicing: Bicing.cc
	g++ -c Bicing.o Bicing.cc $(OPCIONS)

program: program.cc
	g++ -c program.o program.cc $(OPCIONS)

practica.tar: program.cc Bici.cc Estacion.cc Cjt_Bicis.cc Bicing.cc Bici.hh Estacion.hh Cjt_Bicis.hh Bicing.hh BinTree.hh
	tar -cvf practica.tar program.cc Bici.cc Estacion.cc Cjt_Bicis.cc Bicing.cc Bici.hh Estacion.hh Cjt_Bicis.hh Bicing.hh BinTree.hh Makefile html.zip JustificacionPracticaPRO2MarcRibasAcon.pdf

doxygen:
	doxygen Doxyfile

clean:
	rm -f *.o *.exe *.tar
