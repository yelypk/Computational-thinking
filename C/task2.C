#include <vector>
#include <iostream>

int main() //главная функция, которая по умолчанию вызывается компилятором. точка входа в программу 
{
    double seven = 0; 
std::vector<double> array = {1, 4, 7, 8, 11}; // вектор - это есть массив 
for(int i=0; i<array.size();i++){
        seven = seven + array[i]; //ищем сумму всех элементов. на каждом шагу прибавляем к сумме значение следующего элемента массива
}

seven = seven/array.size(); //делим сумму всех элементов на их колличество - среднее арифметическое
//для всех элементов что меньше за среднее арифметическое - увеличиваем их в два раза
for(int i=0; i<array.size();i++){
    if (array[i]<seven){
        array[i]=array[i]*2;
    }  
}

for(int i=0; i<array.size();i++){
    std::cout << array[i] << std::endl;
}
return 0;
}