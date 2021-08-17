#include "header.h"

void main()
{
	int i,j,cur_func;
	char temp_name[MaxProdName];
	Table *tables[Tables]; // list of tables pointers
	//Product* Menu;
	Menu menu; // list of products
	menu.head = NULL; menu.tail = NULL; // set empty list
	//Menu = NULL;

	

	FILE* portions = fopen("Manot.txt", "rt");
	if (!portions)
		ErrorMsg("Cant open file \"Manot.txt\" to reading\n");
	FILE* instr = fopen("Instructions.txt", "rt");
	if (!instr)
		ErrorMsg("Cant open file \"Instructions.txt\" to reading\n");
	// filling tables pointers array
	for (i = 0; i < Tables; i++)
	{
		tables[i] = (Table*)malloc(sizeof(Table));
		tables[i]->head = NULL;
		tables[i]->has_canceled_order = 0;
		if (!tables[i])
		{
			for (j = 0; j < i; j++)
				free(tables[j]);
			ErrorMsg("Memory Allocation Error.\n");
		}
	}
	while (fscanf(instr, "%d", &cur_func) == 1)
	{
		if ((cur_func != 1) && !menu.head) // check if first command is "1"
		{
			ErrorMsg("Kitchen is empty.\n");
		}
		switch (cur_func)
		{
		case 1:
			CreateProduct(portions, &menu, tables);
			break;
		case 2:
			fscanf(instr, "%s%d", temp_name,&i);
			AddItem(temp_name, i, menu);
			break;
		case 3:
			fscanf(instr, "%d%s%d", &i,temp_name, &j);
			OrderItem(i, tables,temp_name,j,menu);
			break;
		case 4:
			fscanf(instr, "%d", &i);
			RemoveItem(i, tables);
			break;
		case 5:
			fscanf(instr, "%d", &i);
			RemoveTable(i, tables);
			break;
		default:
			printf("Wrong procedure number was received.\n");
		}
	}
	for (i = 0; i < Tables; i++)
		FreeTable(tables[i]); // free memory for order list per table
	CleanUp(&menu, tables); // clear menu and table list
	fclose(portions); //closing all opened files
	fclose(instr);
}