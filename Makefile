Project: main.o scaner.o store.o train.o
	g++ main.o scaner.o store.o train.o -o Project

main.o: main.cpp
	g++ -c main.cpp -o main.o

scaner.o: TextScan.cpp
	g++ -c TextScan.cpp -o scaner.o

store.o: Storage.cpp
	g++ -c Storage.cpp -o store.o

train.o: Train.cpp
	g++ -c Train.cpp -o train.o

clear: Project
