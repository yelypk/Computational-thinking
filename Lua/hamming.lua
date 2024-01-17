local Hamming = {}
function Hamming.compute(a,b)
local ha = 0
if string.len(a) ~= string.len(b) then
            return -1
         end
            for i=1,string.len(a)  do
            if a:sub(i,i) ~= b:sub(i,i)
                then ha = ha + 1
end
    end       
    return ha
end
return Hamming