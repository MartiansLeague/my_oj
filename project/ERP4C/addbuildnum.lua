str=io.open("BUILDNUM","r"):read("*a")
print(str)
num=tonumber(str)
io.open("BUILDNUM","w"):write(num+1)