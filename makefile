compile : container.cpp
	g++ container.cpp -o "container"

run : container
	./container