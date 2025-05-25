def main():
    crypted="UDMHUNHCUHBH"
    decrypted=""
    shift=-25
    for char in list(crypted):
        position=ord(char)
        newposition=position+shift
        if newposition>122:
            newposition-=26
        if newposition<97:
            newposition+=26
        newchar=chr(newposition)
        decrypted+=newchar
    print(decrypted)


main()