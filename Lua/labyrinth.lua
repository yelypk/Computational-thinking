local file = "maze.txt"
local maze = {}
for line in io.lines(file) do 
    local t={}
    line:gsub(".",function(c) table.insert(t,c) end)

    maze[#maze+ 1] = t
end

local starti,startj,endi,endj
local stop=false

for i = 1, #maze, 1 do 
    for j = 1,#maze[i],1 do
        if maze[i][j]=='I' then
            starti=i
            startj=j
            stop=true
            break
        end
    end
    if stop then
        break
    end
end

stop=false
local endwave=0

function wave(i,j,N)
if(stop) then
    return
end
    if (maze[i][j]=='E') then
        stop=true
        endwave=N-1
        endi=i
        endj=j
        return
    end
    if (maze[i][j]==' ') then
        maze[i][j]=N
    else
        return
    end

    wave(i-1,j,N+1)
    wave(i+1,j,N+1)
    wave(i,j-1,N+1)
    wave(i,j+1,N+1)
end

wave(starti-1,startj,1)
wave(starti+1,startj,1)
wave(starti,startj-1,1)
wave(starti,startj+1,1)

stop=false
local curwave=endwave+1

function backwave(i,j,N)
    if(stop) then
        return
    end

    if(curwave<=N) then
        return
    end

    if (maze[i][j]=='I') then
        stop=true
        return
    end
    if (maze[i][j]==N) then
        maze[i][j]='*'
        curwave=N
    else
        return
    end

    backwave(i-1,j,N-1)
    backwave(i+1,j,N-1)
    backwave(i,j-1,N-1)
    backwave(i,j+1,N-1)
end

backwave(endi-1,endj,endwave)
backwave(endi+1,endj,endwave)
backwave(endi,endj-1,endwave)
backwave(endi,endj+1,endwave)

for i = 1, #maze, 1 do 
    for j = 1,#maze[i],1 do
        if(maze[i][j]~='0' and maze[i][j]~='*' and maze[i][j]~='I' and maze[i][j]~='E') then
            maze[i][j]=' '
        end 
    end
end

local filein = io.open("maze-out.txt", "a")

for i = 1, #maze, 1 do 
    for j = 1,#maze[i],1 do
        filein:write(maze[i][j])
    end
filein:write("\n")
end

filein:close()

