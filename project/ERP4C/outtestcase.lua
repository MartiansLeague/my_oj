outfile=io.open("testin1.txt","w")

outfile:write("1\n");

for i=1,100 do
	outfile:write(tostring(i).."\n");
	outfile:write("name"..tostring(i).."\n");
	outfile:write(tostring(i).."\n");
	outfile:write("\n");
end

outfile:write("0\n\n\n0\n\n");