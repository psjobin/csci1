#ifndef PRODUCT_H
#define PRODUCT_H

   //*****************************************************************
   // FILE:      Product.h
   // AUTHOR:    Jobin Scaria	
   // LOGON ID:  Z1262764
   // DUE DATE:  mm/dd/yyyy
   // 
   // PURPOSE:   Contains the declaration for the Product class.
   //*****************************************************************

   class Product
   {
   private:

	   char ProductCode[12];
	   char ProductName[46];
	   double ProductPrice;
	   int QuantityInStock;

   public:

	   Product();
	   Product(char* pcode,char*pname,double price,int quantity);
	   char* getProductCode();
	   char* getName();
	   double getPrice();
	   int getQuantity();
	   void setPrice(double price);
	   void setQuantity(int quantity);
	   int fulfillOrder(int orderamt);
	   void print();
   };

#endif

