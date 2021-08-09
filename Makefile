build : GenericAdd.o
	g++ -o build GenericAdd.o
GenericAdd.o : GenericAdd.cc
	g++ -g -c GenericAdd.cc
clean :
	rm GenericAdd.o build