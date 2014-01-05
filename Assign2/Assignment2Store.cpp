#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
#include "Assignment2Store.h"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

ifstream inFile;
ofstream outFile;


Store::Store()
{
	count=0;
}

Store::Store(const char* filename)
{
	inFile.open(filename, ios::binary);
	if (inFile.fail())
	{
		cout<<" ***ERROR*** File not found ***ERROR*** "<<endl;
		exit(1);
	}

	inFile.read((char*) this, sizeof(Store));

	inFile.close();

	sortProducts();
}

void Store::print()
{
	cout<<"Product Inventory Listing"<<endl<<endl;
	for (int i=0;i<count;i++)
	{
		NoOfProducts[i].print();
	}
}

void Store::sortProducts()
{
   int i, j;
   Product bucket;

   for (i = 1; i < count; i++)
      {
      bucket = NoOfProducts[i];
      for (j = i; (j > 0) && (strcmp(NoOfProducts[j-1].getProductCode(), bucket.getProductCode())>0); j--)
	  {
		  NoOfProducts[j] = NoOfProducts[j-1];
	  }
	  NoOfProducts[j] = bucket;
   }
}

int Store::searchForProduct(char* searchcode)
{
	int low=0;
	int high = count-1;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(strcmp(searchcode,NoOfProducts[mid].getProductCode())==1)	//searchcode==NoOfProducts[mid].getProductCode)
		{
			return mid;
		}
		else if (strcmp(searchcode,NoOfProducts[mid].getProductCode())<1)  //searchcode<NoOfProducts[mid].getProductCode)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return -1;
}


void Store::processOrders(const char* filename)
{
	ifstream infile;
	char orderNumber[7];
	char productCode[12];
	int orderQuantity;
	int numShipped;

	infile.open(filename);
	if (infile.fail())
	{
		cout<<"Failed to open file."<<endl;
		exit(1);
	}

	infile>>orderNumber;
	while(infile)
	{
		infile>>productCode;
		infile>>orderQuantity;

		int index=searchForProduct(productCode);
		if (index==-1)
		{
			cout<<"Product can not be located."<<endl;
		}
		else
		{
			numShipped=NoOfProducts[index].fulfillOrder(orderQuantity);
			print();
		}

		infile>>orderNumber;
	}

	infile.close();
}

