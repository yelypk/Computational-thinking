#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// прототипи функцій
int myinput();
char myLimitedinput();
int mainmenu();
int backtomenu();
int task1();
int task2();
unsigned int BitPack(unsigned char a, unsigned char b, unsigned char c);
int BitUnpack(char* unpacked, unsigned int packed);

// перевірки вводу

int myinput()
{
   char line[256];
   int i;
   while (1)
   {
	   if (fgets(line, sizeof(line), stdin)) {
		   if (1 == sscanf(line, "%d", &i)) {
			   // 1 - кількість зчитаних змінних
			   break;
		   }
		   else
		   {
			   fprintf(stdout, "Ne virnyi format chysla, sprobuemo znovu\n");
		   }
	   }
	   else
	   {
		   fprintf(stdout, "Pomylka vvodyu, sprobuemo znovu\n");
	   }
   }
   fprintf(stdout, "Vvedeno tsile chyslo: %d \n", i);
   return i;
}

char myLimitedinput()
{
   char line[256];
   unsigned char i=0;
   while (1)
   {
	   if (fgets(line, sizeof(line), stdin)) {
		   if (1 == sscanf(line, "%hhd", &i)) {
			   // 1 - кількість зчитаних змінних
			   break;
		   }
		   else
		   {
			   fprintf(stdout, "Ne virnyi format, sprobuemo znovu\n");
		   }
	   }
	   else
	   {
		   fprintf(stdout, "Pomylka vvodyu, sprobuemo znovu\n");
	   }
	   unsigned char prepared = (i & 0x1F);
	   if (prepared != i)
	   {
		   fprintf(stdout, "Chyslo perevyshchuye maksymalnu kilkist bitiv, sprobuemo znovu\n");
	   }
   }


   fprintf(stdout, "Vvedeno chyslo: %d \n", i);
   return i;
}

// навігація

int main()
{
    fprintf(stdout, "Tema modulya 1: Bazovi typi dannih, vvedenya-vivedennya, bitovi opatsii, operatsii zsuvu\n");
    fprintf(stdout, "Vikonala studentka gr.KM-42 Posheliuk Elizaveta Andriyovna\n");
    fprintf(stdout, "Variant 18\n");
    mainmenu();

    return 0;
}

int mainmenu()
{
    fprintf(stdout, "============ golovne menu ============\n");
	fprintf(stdout, "vvedit' znachennya dlya navigatsii\n");
    fprintf(stdout, "1 - pershe zavdannya, 2 - druge zavdannya, 3 - zavershennya programi\n");
	int choice = myinput();

	switch (choice)
	{
	case 1:
		task1();
		backtomenu();
		break;
	case 2:
		task2();
		backtomenu();
		break;
	case 3:
		return 0;
	default:
		fprintf(stdout, "Ne virnyi vybir, sprobuemo znovu\n");
		mainmenu();
		break;
	}
	return 0;

}

int backtomenu()
{
	fprintf(stdout, "xxxxxxxx kinets xxxxxxxx\n");
	fprintf(stdout, "vvedit' znachennya dlya navigatsii\n");
	fprintf(stdout, "1 - povernutisya v golovne menu, 3 - zavershennya programi\n");
	int choice = myinput();
	switch (choice)
	{
	case 1:
		mainmenu();
		break;
	case 3:
		return 0;
	default:
		fprintf(stdout, "Ne virnyi vybir, sprobuemo znovu\n");
		backtomenu();
		break;
	}
	return 0;
}

// функції



int task1()
{
   fprintf(stdout, "Zavdannia 1. Dano dva chysla. Znayty serednje arifmetychne kubiv tsykh chysel i serednje heometriyne moduly tsikh chysel.\n");

   fprintf(stdout, "Vvedit perse chyslo: ");
   int a = myinput();
   fprintf(stdout, "Vvedit druhe chyslo: ");
   int b = myinput();

   double avg1 = (pow(a, 3) + pow(b, 3)) / 2;
   double avg2 = sqrt(abs(a) * abs(b));

   fprintf(stdout, "Serednje arifmetychne kubiv tsykh chysel: %f i serednje heometriyne moduly tsikh chysel: %f \n", avg1, avg2);

   return 0;
}

int task2()
{
   fprintf(stdout, "Zavdannia 2. Obchyslyty ob'yem pryamokutnoho paralelepipeda.\n");
   fprintf(stdout, "Vvedit storonu a (0-31): ");
   unsigned char a = myLimitedinput();
   fprintf(stdout, "Vvedit storonu b (0-31): ");
   unsigned char b = myLimitedinput();
   fprintf(stdout, "Vvedit storonu c (0-31): ");
   unsigned char c = myLimitedinput();

   unsigned int packed = BitPack(a, b, c);
   fprintf(stdout, "Upakovane chyslo: %04x \n", packed);

   char unpacked[3] = {0,0,0};
   BitUnpack(unpacked, packed);
   fprintf(stdout, "Rozpakovani chysla: %d %d %d \n", unpacked[0], unpacked[1], unpacked[2]);

   int volume = ((int)unpacked[0])* ((int)unpacked[1]) * ((int)unpacked[2]);
   fprintf(stdout, "Ob'yem pryamokutnoho paralelepipeda: %d \n", volume);
   return 0;
}

unsigned int BitPack(unsigned char a, unsigned char b, unsigned char c)
{
   unsigned int packed = 0;
   packed = (a & 0x1F) << 11;
   packed |= (b & 0x1F) << 6;
   packed |= (c & 0x1F) << 1;
   return packed;
}

int BitUnpack(char * unpacked,unsigned int packed)
{
   unpacked[0] = (packed >> 11) & 0x1F;
   unpacked[1] = (packed >> 6) & 0x1F;
   unpacked[2] = (packed >> 1) & 0x1F;
   return 0;
}