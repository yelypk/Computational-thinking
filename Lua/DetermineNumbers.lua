function Determine(ft, km)
    ft =  math.floor(ft*0.305)
    km = math.floor(km*1000)

    if ft <= km then
        print('ft')
    end
    if km <= ft then
        print('km')
    end
end
