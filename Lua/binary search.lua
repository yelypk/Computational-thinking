return function(array, target)
    local tar = 1
    local ar = #array
    if ar == 1 then
        if array[1] == target then
            return 1 else
            return -1
        end
    end
    while (tar <= ar) do
        local tarar = math.floor((ar + tar)/2)
        if (array[tarar] < target) then 
            tar = tarar + 1
        elseif (array[tarar] > target) then 
            ar = ar - tarar
        else
            return tarar
        end
    end
return -1
end
