#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Assignment2Product.h"
//this is product edit
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;
using std::setw;


Product::Product()
{
	strcpy(ProductCode,"");
	strcpy(ProductName,"");
	setPrice(0.00);
	setQuantity(0);
}


Product::Product(char* pcode,char*pname,double price,int quantity)
{
	strcpy(ProductCode,pcode);
	strcpy(ProductName,pname);
	setPrice(price);
	setQuantity(quantity);
}
char* Product::getProductCode()
{
	return ProductCode;
}

char* Product::getName()
{
	return ProductName;
}

double Product::getPrice()
{
	return ProductPrice;
}

int Product::getQuantity()
{
	return QuantityInStock;
}

void Product::setPrice(double price)
{
	if(price>0)
	{
		ProductPrice=price;
	}
	else
	{
		ProductPrice=0.00;
	}
}

void Product::setQuantity(int quantity)
{
	if(quantity>0)
	{
		QuantityInStock=quantity;
	}
	else
	{
		QuantityInStock=0;
	}
}

int Product::fulfillOrder(int orderamt)
{
	if (orderamt<0)
	{
		QuantityInStock=QuantityInStock;
		return 0;
	}
	else if (orderamt<=QuantityInStock)
	{
		QuantityInStock=QuantityInStock-orderamt;
		return orderamt;
	}
	else // if (orderamt>QuantityInStock)
	{
		int temp=QuantityInStock;
		QuantityInStock=0;
		return temp;
	}
}

void Product::print()
{
	cout<<setw(14)<<std::left<<ProductCode<<endl;
	cout<<setw(46)<<std::left<<ProductName<<endl;
	cout<<setw(6)<<std::right<<std::fixed<<std::setprecision(2)<<ProductPrice<<endl;
	cout<<setw(6)<<std::right<<QuantityInStock<<endl;
}

