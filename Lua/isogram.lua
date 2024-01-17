return function(s)
    local str = string.lower(s)
    str = str:gsub("%s", "")
    str = str:gsub("%p", "")
    local i = 1
            for w in string.gmatch(str, "%a") do 
                i = i + 1
                if str:find(w, i) ~= nil then return false
                end
        
    end
        return true
    end