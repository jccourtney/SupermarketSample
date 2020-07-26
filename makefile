#Name: John Courtney
#Assignment: 4 base
#Target is SupermarketPrice


#====== Targets ======#
SupermarketPrice: main.o Checkout.o	Item.o	 PriceScheme.o	Product.o
	g++ -std=c++11 main.o	Checkout.o	PriceScheme.o	Product.o	Item.o -o SupermarketPrice


main.o: main.cpp	Checkout.h	Item.h	Product.h	PriceScheme.h
	g++ -std=c++11 -c	main.cpp

Checkout.o:	Checkout.cpp	Item.h
	g++	-std=c++11	-c	Checkout.cpp

PriceScheme.o:	PriceScheme.cpp	PriceScheme.h
	g++	-std=c++11	-c	PriceScheme.cpp

Product.o:	Product.cpp	Product.h
	g++	-std=c++11	-c	Product.cpp

Item.o:	Item.cpp	Item.h
	g++	-std=c++11	-c	Item.cpp

clean: 
	rm *.o
	rm SupermarketPrice


run:	SupermarketPrice
	./SupermarketPrice