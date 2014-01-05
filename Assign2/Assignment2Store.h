#ifndef STORE_H
#define STORE_H

//*****************************************************************
   // FILE:      Store.h
   // AUTHOR:    Jobin Scaria	
   // LOGON ID:  Z1262764
   // DUE DATE:  mm/dd/yyyy
   // 
   // PURPOSE:   Contains the declaration for the Store class.
   //*****************************************************************

#include "Assignment2Product.h"

   class Store
   {
   private:

	   Product NoOfProducts[30];
	   int count; // actual number of pruducts stored in the array

   public:

	   Store();
	   Store(const char*);
	   void print();
	   void sortProducts();
	   int searchForProduct(char*);
	   void processOrders(const char*);
   };


#endif