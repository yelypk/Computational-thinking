local Outp = {}
function Outp.compute(N)

for i = 1, N, 1 do 
    for j = 1,i,1 do
        io.write('*')
    end
print("\n")
end
end
Outp.compute(4)