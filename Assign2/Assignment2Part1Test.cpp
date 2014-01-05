#include <iostream>
#include "Assignment2Product.h"

   using std::cout;
   using std::endl;

   int main()
      {
      char code1[12] = "11111111111";
      char name1[46] = "widget";
      char code2[12] = "22222222222";
      char name2[46] = "gizmo";
      int numShipped;

      // Test default constructor
      Product product1;

      // Test alternate constructor
      Product product2(code1, name1, 120.99, 5);

      // Test data validation
      Product product3(code2, name2, -12.99, -6);

      // Test print() method and whether constructors
      // properly initialized objects
      cout << "Printing product1\n\n";
      product1.print();
      cout << endl << endl;

      cout << "Printing product2\n\n";
      product2.print();
      cout << endl << endl;

      cout << "Printing product3\n\n";
      product3.print();
      cout << endl << endl;

      // Test accessor methods
      cout << product2.getProductCode() << endl;
      cout << product2.getName() << endl;
      cout << product2.getPrice() << endl;
      cout << product2.getQuantity() << endl<<endl;

      // Test the fulfillOrder() method
	  cout<<"ordering -5 "<<endl;
      numShipped = product2.fulfillOrder(-5);
      cout << "Shipped " << numShipped << endl;
      cout << "Quantity now " << product2.getQuantity() << endl<<endl;
      
	  cout<<"ordering 3"<<endl;
      numShipped = product2.fulfillOrder(3);
      cout << "Shipped " << numShipped << endl;
      cout << "Quantity now " << product2.getQuantity() << endl<<endl;

      cout<<"ordering 4"<<endl;
	  numShipped = product2.fulfillOrder(4);
      cout << "Shipped " << numShipped << endl;
      cout << "Quantity now " << product2.getQuantity() << endl;

	  return 0;
      }

