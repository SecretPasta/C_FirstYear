#include "header.h"

// func for printing error
void ErrorMsg( char* msg)
{
	printf("\n%s\n", msg);
	exit(1);
}

/*func for creation list of products in kitchen*/
void CreateProduct(FILE* in,Menu *menu,Table* table)
{
    char temp_prod_name[MaxProdName]; //buffer variable for product name
    Product* temp;
    float price;
    int quantity;
    while (
        fscanf(in, "%s%d%f", temp_prod_name, &quantity, &price) == 3) // get data per product
    {
        if (CheckName(*menu, temp_prod_name))// if exist element in menu with same name
        {
            printf("Error. The name: \"%s\" currently exist in menu.\n", temp_prod_name);
            break;
        }
        if (quantity <= 0 || price <= 0) // check if values per product are legal
        {
            printf("Error. Price or quantity are not correct for product:%s\n", temp_prod_name);
            break;
        }
        temp = (Product*)malloc(sizeof(Product));
        if (!temp)// product allocation error
        {
            CleanUp(&menu, table); // clear list
            ErrorMsg("Memory Allocation Error...\n");
        }
        temp->Name = (char*)malloc((sizeof(temp_prod_name) + 1));
        if (!temp->Name)// name allocation error
        {
            free(temp); // free temp allocation
            CleanUp(&menu, table); // clear list
            ErrorMsg("Memory Allocation Error...\n");
        }
        strcpy(temp->Name, temp_prod_name); // copy data from temp to element
        temp->Price = price;
        temp->Quantity = quantity;

        // add new element to menu list
        if (!menu->head)// if first element in list
        {
            menu->head = temp;
        }
        else // second and others elements
        {
            menu->tail->next = temp;
        }
        menu->tail = temp;
        temp->next = NULL;
    }
    printf("Kitchen was created\n");
}

/*Check if element with name exist in menu and return pointer to it
if does not exist return NULL*/
Product* CheckName(Menu menu,char* name)
{
    Product* temp = menu.head;
    while (temp)
    {
        if (strcmp(temp->Name, name)==0 )
            return temp;
        temp = temp->next;
    }
    return NULL; // if name is not in menu
}
/*function clear menu list and table list*/
void CleanUp(Menu *menu,Table* tables[])
{
    int i;
    Product* temp = menu->head;
    while (temp) // clear menu list
    {
        free(temp->Name); // free names per list
        menu->head = menu->head->next;
        free(temp); // free element in list
        temp = menu->head;
    }
    for (i = 0; i < Tables; i++) // clear array of tables
        free(tables[i]);
}

/*function for adding count of specific element*/
void AddItem(char* ProductName, int Quantity,Menu menu)
{
    Product* temp = CheckName(menu, ProductName);
    if (Quantity < 1) // if value is illegal
    {
        printf("The quantity should be grater than zero\n");
        return;
    }
    if (!temp) // if name does not exist in menu
    {
        printf("We don't have %s, sorry!\n", ProductName);
        return;
    }
    // if all fine add Quantity to count of element in menu
    temp->Quantity += Quantity;
    printf("%d %s were added to the kitchen\n", Quantity, temp->Name);
    return;
}

/*function for creat ordered element to table list*/
void OrderItem(int number,Table *tables[], char* ProductName, int Quantity, Menu menu)
{
    Product* temp = CheckName(menu, ProductName),*temp_prod;
    int i;
    if (!temp) // if name does not exist in menu
    {
        printf("We don't have %s, sorry!\n", ProductName);
        return;
    }
    if ((number > Tables) || (number < 1)) // if number of table is illegal
    {
        printf("The table #%d is not exist\n", number + 1);
        return;
    }
    if (Quantity<1) // if quantity of oredered item is illegal
    {
        printf("The quantity has wroge value\n");
        return;
    }
    if (temp->Quantity < Quantity) // if quantity of oredered item more then count in the kitchen
    {
        printf("There is not enough \"%s\" on kitchen\n", ProductName);
        return;
    }
    //add prod for needed table
    if (tables[number - 1]->head==NULL)// if first order for this table
    {
        tables[number - 1]->head = (Product*)malloc(sizeof(Product)); // creat new element
        if (!tables[number - 1]->head) // if allocation was faild
        {
            for (i = 0; i < Tables; i++)
                FreeTable(tables[i]); // free memory for order list per table
            CleanUp(&menu, tables);
            ErrorMsg("Allocation Memory Error\n");
        }
        tables[number - 1]->head->Name = temp->Name; // set name of ordered product
        tables[number - 1]->head->Quantity = Quantity; // set ordered count of product
        tables[number - 1]->head->Price = temp->Price; // set price of ordered product
        temp->Quantity -= Quantity; // edit availible count of product
        tables[number - 1]->head->next = NULL; // set next element NULL
    }
    else // if second and next element
    {
        temp_prod = tables[number - 1]->head;
        tables[number - 1]->head = (Product*)malloc(sizeof(Product)); // creat new element
        if (!tables[number - 1]->head) // if allocation was faild
        {
            for (i = 0; i < Tables; i++)
                FreeTable(tables[i]); // free memory for order list per table
            CleanUp(&menu, tables); // clear list
            ErrorMsg("Allocation Memory Error\n");
        }
        tables[number - 1]->head->Name = temp->Name; // set name of ordered product
        tables[number - 1]->head->Quantity = Quantity; // set ordered count of product
        tables[number - 1]->head->Price = temp->Price; // set price of ordered product
        temp->Quantity -= Quantity; // edit availible count of product
        tables[number-1]->head->next = temp_prod; // set next element NULL
    }
    printf("%d %s were added to the table number %d\n", Quantity, temp->Name, number);
}

/*function to cancel last order*/
void RemoveItem(int TableNumber, Table *tables[])
{
    Product* temp;
    if ((TableNumber > Tables) || (TableNumber < 0)) // if number of table is illegal
    {
        printf("The table #%d does not exist\n", TableNumber);
        return;
    }
    if (!tables[TableNumber-1]->head) // if table has no orders
    {
        printf("The table number %d does not ordered yet\n", TableNumber);
        return;
    }
    if (tables[TableNumber - 1]->has_canceled_order==1) // if table already canceled one order
        {
        printf("The table number %d already canceled one order\n", TableNumber);
        return;
        }
    if (!tables[TableNumber - 1]->head->next)// if table has only one order
    {
        tables[TableNumber - 1]->has_canceled_order++;// set one to returned order
        printf("%d %s was returned to the kitchen from table number %d\n",
            tables[TableNumber - 1]->head->Quantity,
            tables[TableNumber - 1]->head->Name, TableNumber);
        free(tables[TableNumber - 1]->head); // free order
        tables[TableNumber - 1]->head = NULL; // set table order list empty
        return;
    }
    tables[TableNumber - 1]->has_canceled_order++; // set one to returned order
    temp = tables[TableNumber - 1]->head->next; // save next element
    printf("%d %s was returned to the kitchen from table number %d\n",
        tables[TableNumber - 1]->head->Quantity,
        tables[TableNumber - 1]->head->Name, TableNumber);
    free(tables[TableNumber - 1]->head); // free last order
    tables[TableNumber - 1]->head = temp; // set new last order
    return;
}

/*func for get bill and empty order list per table*/
void RemoveTable(int TableNumber, Table* tables[])
{
    Product* temp;
    float sum=0;
    if ((TableNumber > Tables) || (TableNumber < 0)) // if number of table is illegal
    {
        printf("The table #%d does not exist\n", TableNumber);
        return;
    }
    if (!tables[TableNumber - 1]->head) // if table has no orders
    {
        printf("The table number %d does not ordered yet\n", TableNumber);
        return;
    }
    temp = tables[TableNumber - 1]->head;
    while (temp)
    {
        printf("%d %s. ",temp->Quantity,temp->Name);
        sum += (temp->Quantity *temp->Price); // calculating price per order
        temp = temp->next;
    }
    printf("%.2f nis+%.2f nis for tips,please! (table number: %d)\n",sum,(sum*0.15), TableNumber);
    FreeTable(tables[TableNumber - 1]); // free list of reders per table
}

/*free orders list for table*/
void FreeTable(Table* table)
{
    Product* temp;
    temp=table->head;
    while (temp)
    {
        table->head = table->head -> next;
        free(temp);
        temp = table->head;
    }
}