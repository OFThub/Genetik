hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Gen.o -c ./src/Gen.cpp
	g++ -I ./include/ -o ./lib/Kromozom.o -c ./src/Kromozom.cpp
	g++ -I ./include/ -o ./lib/DNA.o -c ./src/DNA.cpp
	g++ -I ./include/ -o ./bin/DnaIslemleri ./lib/Gen.o ./lib/Kromozom.o ./lib/DNA.o ./src/Main.cpp
	
calistir:
	./bin/DnaIslemleri