#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

// прототипи функцій  
int main();  
int mainmenu();  
int backtomenu();  
int myinput();  
static int mystringinput(char* line, int bufsize);

//структури  

//*назва товару;  
//*назва магазину, у якому продається товар;  
//*вартість товару(у грн).  
struct PRICE  
{  
   char name[20];  
   char shop[20];  
   int price;  
};  

// перевірки вводу  
int myinput()  
{  
   char line[256];  
   int i = 0;  
   while (1)  
   {  
       if (fgets(line, sizeof(line), stdin)) {  
           if (1 == sscanf(line, "%d", &i)) {  
               // 1 - кількість зчитаних змінних  
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
        // очищуємо буфер  
        memset(line, 0, bufsize);
        // зчитуємо рядок з клавіатури  
        fgets(line, bufsize, stdin);

		if (strchr(line, '\n'))
		{
			// видаляємо символ нового рядка з кінця рядка
			line[strcspn(line, "\n")] = 0;
		}
		else
		{
			// очищуємо буфер, якщо рядок не помістився в буфер
			while (getchar() != '\n');
		}
        // перевіряємо, чи рядок не порожній
        if (strlen(line) == 0) {
            fprintf(stdout, "Empty string, please enter a valid string:\n");
        }
		else {
			break;
		}
    }

	// виводимо рядок на екран
	fprintf(stdout, "Parsed string: %s \n", line);

   return 0;  
}  


// навігація  

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

// функції  

#define PRISENUM 5 

//1. * *Описати структуру з іменем `PRICE`, що містить такі поля : **  
//  
//*назва товару;  
//*назва магазину, у якому продається товар;  
//*вартість товару(у грн).  
//  
//2. * *Написати програму, що виконує наступні дії : **  
//  
//*введення з клавіатури даних у масив із 5 структур типу `PRICE`;  
//* упорядкування записів за алфавітом за назвами магазинів;  
//*виведення на екран інформації про товари, що продаються в магазині, назву якого введено з клавіатури; якщо таких товарів немає, вивести на екран відповідне повідомлення.  
int task1()  
{  
   fprintf(stdout, "Task 1. Write a program that performs the following tasks:\n");  
   fprintf(stdout, "input data from the keyboard into an array of 5 structures of type PRICE\n");  
   fprintf(stdout, "sort records alphabetically by store names\n");  
   fprintf(stdout, "output information about the goods sold in the store, the name of which was entered from the keyboard\n");  
   fprintf(stdout, "if there are no such goods, display a message on the screen\n");  


   // створюємо масив структур  
   struct PRICE price[PRISENUM]= {0};

   // вводимо дані  
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
   // сортуємо масив структур за алфавітом за назвами магазинів  
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

   // виводимо масив структур на екран  
   fprintf(stdout, "Products sorted by store names:\n");  
   for (int i = 0; i < PRISENUM; i++)  
   {  
       fprintf(stdout, "Product name: %s, Store name: %s, Price: %d\n", price[i].name, price[i].shop, price[i].price);  
   }  

   // запитуємо назву магазину  
   fprintf(stdout, "Enter store name to search for products:\n");  
   char shop[20];  
   mystringinput(shop, sizeof(shop));
   // шукаємо товари в магазині  
   int found = 0;  
   for (int i = 0; i < PRISENUM; i++)  
   {  
       if (strcmp(price[i].shop, shop) == 0)  
       {  
           fprintf(stdout, "Product name: %s, Store name: %s, Price: %d\n", price[i].name, price[i].shop, price[i].price);  
           found = 1;  
       }  
   }  
   // якщо товарів немає, виводимо повідомлення  
   if (found == 0)  
   {  
       fprintf(stdout, "No products found in store %s\n", shop);  
   }  


   return 0;	  
}
