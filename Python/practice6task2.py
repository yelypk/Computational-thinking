def indexinput():
    str=input().upper()
    index=[]
    if len(str)!=3:
        print('Correct index contains 3 letters, please, try again!')
        indexinput()

    for c in str:
        index.append(c)

    if not index[0].isalpha() or not index[2].isalpha():
        print('The first and third letter should be an alphabetical, please, try again!')
        indexinput()

    if index[0] in ["D", "F", "I", "O", "Q", "U", "W", "Z"]:
        print('Such province code doesnt exist! please, try again!')
        indexinput()

    if not index[1].isnumeric():
        print('Second letter sholud be a number, please, try again!')
        indexinput()

    return index

def main():
    print('Enter your canadian index:')
    index=indexinput()

    provinces = {
        "A":"Newfoundland",
        "B":"Nova Scotia",
        "C":"Prince Edward Island",
        "E":"New Brunswick",
        "G":"Quebec",
        "H":"Quebec",
        "J":"Quebec",
        "K":"Ontario",
        "L":"Ontario",
        "M":"Ontario",
        "N":"Ontario",
        "P":"Ontario",
        "R":"Manitoba",
        "S":"Saskatchewan",
        "T":"Alberta",
        "V":"British Columbia",
        "X":"Nunavut and Northwest Territories",
        "Y":"Yukon"
    }

    print("You are located in the provence called "+provinces[index[0]])
    if index[1]==0:
        print("and you are in the village")
    else:
        print("and you are in the city")

main()

    