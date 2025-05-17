local Outp = {}
function Outp.compute(N)

for i = 0, N, 1 do 
    for j = 0,N,1 do
        if j < N - i then
            io.write(' ')
        else
            io.write('*')
        end
    end
    for j = 1,i,1 do
        io.write('*')
    end
print("\n")
end
end
Outp.compute(4)