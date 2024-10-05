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

#xInput - переверяю введення дійсних чисел і ділення на 0
def xInput(n):
     result=0

     try:
          result=float(input())
     except: 
          print('введить правильне дійсне число')
          result=xInput(n)

     
     if result==n:
         print('увага! ділення на нуль. Введить інше х')
         result=xInput(n)
     return result

#**************** завдання *******************

def task1modul2():
     print('Обрано завдання 1')
     print('Умова: розрахувати суму по і від 1 до n: x^i/(x-n)')
     print('ввести n')
     n = nInput()
     print('ввести x')
     x = xInput(n)

     sum = 0 
     for i in range(1,n+1):
          sum+=pow(x,i)/(x-n)
     print('сума дорівнює:'+str(sum)) #щоб додавати стрінги, суму треба перетворити на стрінг 
     backmenu()

def task2modul2():
    print('Обрано завдання 2')
    print('Умова:  Увести ціле число N(>1). Знайти найбільше ціле число K, при якому виконується нерівність 3K<N')
    print('введить ціле число N')
    N = nInput()
    K = 0
    while 3*K<N:
     K+=1
    K-=1
    #зменшуємо на 1, бо останнє значення вже завелике 
    print("к дорівнює "+str(K))
    backmenu()

#**************** навігація *******************

def mainmenu():
    print('======== головне меню =========')
    print('введіть потрібне значення')
    print('1 - це перше завдання, 2 - це завдання друге, а 3 - завершення програми')
    choose=nInput()
    if choose==1:
        task1modul2()
    elif choose==2:
          task2modul2()
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
    print('''                              Тема модуля2: Програмування циклічних алгоритмів 
                                     Виконала студентка гр.КМ-42 Пошелюк Єлизавета Андрійовна
                                                        Варіант №19''')
    mainmenu()

main()
    