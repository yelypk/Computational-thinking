function Determinate(num)
local lastnum = num%10
if num % 2 == 0 then
    print(lastnum,'остання цифра - ч')
end
if num % 2 == 1 then
    print (lastnum, 'остання цифра - неч')
end
end