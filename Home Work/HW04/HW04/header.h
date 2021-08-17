#ifndef _Header
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define _Header
#define MaxProdName 51 // max length for product name
#define Tables 50 // count of tables

/*struct for kitchen products*/
typedef struct Product
{
	struct Product* next;
	char* Name;
	int Quantity;
	float Price;
}Product;

/*struct for manage menu*/
typedef struct Menu
{
	struct Product* head;
	struct Product* tail;
}Menu;

/*struct  for tables*/
typedef struct Table
{
	int has_canceled_order; // flag for check canceled orders
	struct Product* head; // head of orders list
}Table;

void CreateProduct(FILE* in, Menu* menu, Table* table); // func for creating product
void AddItem(char *ProductName, int Quantity, Menu menu); // func for adding count of product
void OrderItem(int number, Table *tables[], char* ProductName, int Quantity, Menu menu); // func for creating order to table
void RemoveItem(int TableNumber, Table *tables[]); // func for deleting last order for current table
void RemoveTable(int TableNumber, Table* tables[]); // func for check billing for table
void ErrorMsg(char* msg); // func for printing error
Product* CheckName(Menu menu, char* name); // func for check name in menu
void CleanUp(Menu *menu, Table* table[]); // func for memory clean
void FreeTable(Table* table); // funf for free memory per table;
#endif