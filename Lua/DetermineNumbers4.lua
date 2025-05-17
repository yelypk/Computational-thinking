function Determine(n)
local a = n//10
local b = n%10
if a > b then
   print('перше більше')
end
if a < b then
    print('друге більше')
end
end