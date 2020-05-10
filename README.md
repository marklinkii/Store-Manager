## Store-Manager

This program takes two text documents, one for a store and one for customer orders, and creates a results file that prints the contents of the store before and after filling the orders as well as the status of all the orders before and after being filled.

To run this program, download all files, then navigate to the directory with the makefile on a command prompt. From here, type the command "make" to compile the program. Then, type the command "make run STORE=store.txt ORDERS=orders.txt". This will produce a results file that shows the status of the store and orders after all transactions. store.txt and orders.txt are provided, but they can be modified using the format defined below.

The store.txt file takes this format: 
- "Food Name" Food_Type Price
  - Food Name must be in quotes and can be anything (e.g. "Cosmic Brownies")
  - Food_Type must take one of the following: fruit, meat, sweet, starch
  - Price can be any amount in the traditional dollar.cents format (e.g. 1.12)
  
The orders.txt file takes this format:
- "First-Name Last-Name" Accepts-Partial-Orders Food_Type...
  - First-Name Last-Name must be in quotes and can be anything (e.g. "Mark Link")
  - Accepts-Partial-Orders is a yes/no field that determines if the customer will accept a partially full order
  - Food_Type can take any of the following: fruit, meat, sweet, starch
    - This is a list of desired food types, separated by spaces (e.g. fruit fruit starch meat)
