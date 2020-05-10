all: Driver.o Food.o Order.o Orders.o Store.o Manager.o
	g++ -g -Wall Driver.o Food.o Order.o Orders.o Store.o Manager.o -o Driver.out

driver.o: Driver.cpp Manager.o Store.o Orders.o Order.o Food.o
	g++ -Wall -c driver.cpp

Manager.o: Manager.cpp Manager.h Store.o Orders.o Order.o Food.o
	g++ -Wall -c Manager.cpp

Store.o : Store.cpp Store.h Orders.o Order.o Food.o
	g++ -Wall -c Store.cpp
	
Orders.o : Orders.cpp Orders.h Order.o Food.o
	g++ -Wall -c Orders.cpp
	
Order.o : Order.cpp Order.h Food.o 
	g++ -Wall -c Order.cpp
	
Food.o : Food.cpp Food.h 
	g++ -Wall -c Food.cpp

# -f removes any error messages if the file is not present
clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

run:
	./Driver.out $(STORE) $(ORDERS)