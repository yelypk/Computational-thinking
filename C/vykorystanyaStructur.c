#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

// ��������� �������  
int main();  
int mainmenu();  
int backtomenu();  
int myinput();  
static int mystringinput(char* line, int bufsize);

//���������  

//*����� ������;  
//*����� ��������, � ����� ��������� �����;  
//*������� ������(� ���).  
struct PRICE  
{  
   char name[20];  
   char shop[20];  
   int price;  
};  

// �������� �����  
int myinput()  
{  
   char line[256];  
   int i = 0;  
   while (1)  
   {  
       if (fgets(line, sizeof(line), stdin)) {  
           if (1 == sscanf(line, "%d", &i)) {  
               // 1 - ������� �������� ������  
               break;  
           }  
           else  
           {  
               fprintf(stdout, "Incorrect number format, lets try again:\n");  
           }  
       }  
       else  
       {  
           fprintf(stdout, "Input error, lets try again:\n");  
       }  
   }  
   fprintf(stdout, "Parsed decimal number: %d \n", i);  
   return i;  
}  

static int mystringinput(char* line, int bufsize)  
{
    while (1)
    {
        // ������� �����  
        memset(line, 0, bufsize);
        // ������� ����� � ���������  
        fgets(line, bufsize, stdin);

		if (strchr(line, '\n'))
		{
			// ��������� ������ ������ ����� � ���� �����
			line[strcspn(line, "\n")] = 0;
		}
		else
		{
			// ������� �����, ���� ����� �� ��������� � �����
			while (getchar() != '\n');
		}
        // ����������, �� ����� �� �������
        if (strlen(line) == 0) {
            fprintf(stdout, "Empty string, please enter a valid string:\n");
        }
		else {
			break;
		}
    }

	// �������� ����� �� �����
	fprintf(stdout, "Parsed string: %s \n", line);

   return 0;  
}  


// ��������  

int main()  
{  
   fprintf(stdout, "Modul 5 topic: Tipi danih viznacheni korystuvachem\n");  
   fprintf(stdout, "Created by student KM-42 Posheliuk Elizaveta Andriyovna\n");  
   fprintf(stdout, "Task 18\n");  
   mainmenu();  

   return 0;  
}  

int mainmenu()  
{  
   fprintf(stdout, "============ main menu ============\n");  
   fprintf(stdout, "enter number for your navigation choise:\n");  
   fprintf(stdout, "1 - task 1, 3 - end and exit\n");  


   while (1)  
   {  
       int choice = myinput();  
       int stop = 0;  
       switch (choice)  
       {  
       case 1:  
           task1();  
           backtomenu();  
           stop = 1;  
           break;  
       case 3:  
           return 0;  
       default:  
           fprintf(stdout, "Wrong input, lets try again:\n");  
           break;  
       }  
       if (stop == 1)  
       {  
           break;  
       }  
   }  


   return 0;  

}  

int backtomenu()  
{  
   fprintf(stdout, "xxxxxxxx end task xxxxxxxx\n");  
   fprintf(stdout, "enter number for your navigation choise:\n");  
   fprintf(stdout, "1 - return to main menu, 3 - end and exit\n");  

   while (1)  
   {  
       int choice = myinput();  
       int stop = 0;  

       switch (choice)  
       {  
       case 1:  
           stop = 1;  
           break;  
       case 3:  
           return 0;  
       default:  
           fprintf(stdout, "Wrong input, lets try again:\n");  
           break;  
       }  
       if (stop == 1)  
       {  
           break;  
       }  
   }  

   mainmenu();  
   return 0;  
}  

// �������  

#define PRISENUM 5 

//1. * *������� ��������� � ������ `PRICE`, �� ������ ��� ���� : **  
//  
//*����� ������;  
//*����� ��������, � ����� ��������� �����;  
//*������� ������(� ���).  
//  
//2. * *�������� ��������, �� ������ ������� 䳿 : **  
//  
//*�������� � ��������� ����� � ����� �� 5 �������� ���� `PRICE`;  
//* ������������� ������ �� �������� �� ������� ��������;  
//*��������� �� ����� ���������� ��� ������, �� ���������� � �������, ����� ����� ������� � ���������; ���� ����� ������ ����, ������� �� ����� �������� �����������.  
int task1()  
{  
   fprintf(stdout, "Task 1. Write a program that performs the following tasks:\n");  
   fprintf(stdout, "input data from the keyboard into an array of 5 structures of type PRICE\n");  
   fprintf(stdout, "sort records alphabetically by store names\n");  
   fprintf(stdout, "output information about the goods sold in the store, the name of which was entered from the keyboard\n");  
   fprintf(stdout, "if there are no such goods, display a message on the screen\n");  


   // ��������� ����� ��������  
   struct PRICE price[PRISENUM]= {0};

   // ������� ���  
   fprintf(stdout, "Enter data for 5 products:\n");  
   for (int i = 0; i < PRISENUM; i++)  
   {  
       fprintf(stdout, "Enter product name:\n");  
       mystringinput(price[i].name, sizeof(price[i].name));
       fprintf(stdout, "Enter store name:\n");  
       mystringinput(price[i].shop, sizeof(price[i].shop));
       fprintf(stdout, "Enter product price:\n");  
       price[i].price = myinput();  
   }  
   // ������� ����� �������� �� �������� �� ������� ��������  
   for (int i = 0; i < PRISENUM; i++)  
   {  
       for (int j = i + 1; j < PRISENUM; j++)  
       {  
           if (strcmp(price[i].shop, price[j].shop) > 0)  
           {  
               struct PRICE temp = price[i];  
               price[i] = price[j];  
               price[j] = temp;  
           }  
       }  
   }  

   // �������� ����� �������� �� �����  
   fprintf(stdout, "Products sorted by store names:\n");  
   for (int i = 0; i < PRISENUM; i++)  
   {  
       fprintf(stdout, "Product name: %s, Store name: %s, Price: %d\n", price[i].name, price[i].shop, price[i].price);  
   }  

   // �������� ����� ��������  
   fprintf(stdout, "Enter store name to search for products:\n");  
   char shop[20];  
   mystringinput(shop, sizeof(shop));
   // ������ ������ � �������  
   int found = 0;  
   for (int i = 0; i < PRISENUM; i++)  
   {  
       if (strcmp(price[i].shop, shop) == 0)  
       {  
           fprintf(stdout, "Product name: %s, Store name: %s, Price: %d\n", price[i].name, price[i].shop, price[i].price);  
           found = 1;  
       }  
   }  
   // ���� ������ ����, �������� �����������  
   if (found == 0)  
   {  
       fprintf(stdout, "No products found in store %s\n", shop);  
   }  


   return 0;	  
}
