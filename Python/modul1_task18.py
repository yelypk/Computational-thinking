 #**************** перевірки *******************

#xInput - переверяю введення натуральних чисел
def nInput():
     result=0

     input_str=input()
     if input_str.isnumeric():
               result=int(input_str)
     else: 
          print('будь ласка введіть числове значення')
          result=nInput()

     if result==0: 
          print('будь ласка введить не нульове значення')
          result=nInput()

     return result

#**************** завдання *******************

def task1modul1():
     print('Обрано завдання 1')
     print('Умова: Знайти суму членів арифметичної прогресії, якщо відомі її перший член, знаменник і число членів прогресії.')
     print('ввести перше значення')
     first = nInput()
     print('ввести знаменник')
     incriment = nInput()
     print('ввести число членів прогресії')
     n = nInput()

     sum = (2*first+incriment*(n-1))*n/2
     print('сума прогресії дорівнює:'+str(sum)) #щоб додавати стрінги, суму треба перетворити на стрінг 
     backmenu()

def task2modul1():
     print('Обрано завдання 2')
     print('Умова:  Написати програму-фільтр, яка при натисканні будь-яких клавіш виводить на екран тільки букви і цифри, при цьому вказуючи, що виводиться: буква або цифра.')
     print('введіть q щоб завершити програму або продовжуйте вводити символи')
     while True:
          input_str=input() 
          if len(input_str)==1:
               
            if input_str.isnumeric():
               print('то є цифра')
            elif input_str.isalpha():
               print('то є літера')
               if input_str=='q':        
                    break
     backmenu()

#**************** навігація *******************

def mainmenu():
    print('======== головне меню =========')
    print('введіть потрібне значення')
    print('1 - це перше завдання, 2 - це завдання друге, а 3 - завершення програми')
    choose=nInput()
    if choose==1:
        task1modul1()
    elif choose==2:
          task2modul1()
    elif choose==3:
          return 0
    else:
          print('введено невідоме значення, почнемо з початку')
          mainmenu()

def backmenu():
    print('ххххххх кінець ххххххх')
    print('введить потрібне значення')
    print('1 - повернутися в головне меню, 2 - завершення програми')
    choose=nInput()
    if choose==1:
        mainmenu()
    elif choose==2:
          return 0
    else:
          print('введено невідоме значення, почнемо з початку')
          backmenu()

def main():
    print('''                              Тема модуля1: Програмування лінійних алгоритмів та
                                            та розгалужених процесів
                                     Виконала студентка гр.КМ-42 Пошелюк Єлизавета Андрійовна
                                                        Варіант №18''')
    mainmenu()

main()
    