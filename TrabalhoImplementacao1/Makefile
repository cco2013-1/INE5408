OBJS = GeradorAleatorio.o Cliente.o ListaEncadeada.hpp FilaCliente.o \
	Caixa.o ListaCircular.hpp ListaCaixa.o SuperMercado.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

sim : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)

GeradorAleatorio.o : GeradorAleatorio.h GeradorAleatorio.cpp
	$(CC) $(CFLAGS) GeradorAleatorio.cpp

Cliente.o : Cliente.h Cliente.cpp GeradorAleatorio.h
	$(CC) $(CFLAGS) Cliente.cpp

ListaEncadeada.o : ListaEncadeada.hpp
	$(CC) $(CFLAGS) ListaEncadeada.hpp

FilaCliente.o : FilaCliente.h FilaCliente.cpp Cliente.h ListaEncadeada.hpp
	$(CC) $(CFLAGS) FilaCliente.cpp

Caixa.o : Caixa.h Caixa.cpp FilaCliente.h
	$(CC) $(CFLAGS) Caixa.cpp

ListaCircular.o : ListaCircular.hpp
	$(CC) $(CFLAGS) ListaCircular.hpp

ListaCaixa.o : ListaCaixa.h ListaCaixa.cpp ListaCircular.hpp Caixa.h
	$(CC) $(CFLAGS) ListaCaixa.cpp

SuperMercado.o : SuperMercado.h SuperMercado.cpp GeradorAleatorio.o ListaCaixa.h Caixa.h Cliente.h
	$(CC) $(CFLAGS) SuperMercado.cpp

main.o : main.cpp SuperMercado.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o *~ *.out *.gch
