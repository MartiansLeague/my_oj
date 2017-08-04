
local error = error
local http = require( "socket.http" )
local ltn12 = require( "ltn12" )
local string = string
local table = table

facepunch={}
facepunch.http={}

function facepunch.http.get( URL, session )
	local t = {}
	local cookie = nil
	if ( session and session.cookie ) then
		cookie = session.cookie
	end
	local headers = {}
	headers[ "Cookie" ] = cookie
	local r, c, h = http.request({
		url = URL,
		sink = ltn12.sink.table( t ),
		headers = headers
	})
	r = table.concat( t, "" )
	if ( h ) then
		t = {}
		for k, v in pairs( h ) do
			if ( k == "set-cookie" ) then
				-- We remove expiration data here since it has commas in the given
				-- timestamps, so it doesn't break us separating individual cookies
				-- below
				v = string.gsub( v, "(expires=.-; )", "" )
				-- Grab set-cookie and append an additional separator for gmatch
				-- convenience
				v = v .. ", "
				for cookie in string.gmatch( v, "(.-), " ) do
					cookie = string.match( cookie, "(.-);" )
					table.insert( t, cookie )
				end
			end
		end
		cookie = table.concat( t, ";" )
	else
		cookie = nil
	end
	-- r is retcontent,c is retcode,cookie just cookie
	return r, c, cookie
end
for i=1000,9999 do
	infile=io.open("uoj"..i..".html","w")
r,c,cookie=facepunch.http.get( "http://acm.scau.edu.cn:8000/uoj/common_problem_view_PUBLIC.html?identity=55fb83200b34946da0c72b7a9f791950&problemId="..i,
 {cookie="JSESSIONID=F30EDD7CCB82FEA5714AC1034BA2742C; cotree=1.2; cstree=64;"} )
infile:write(r)
print(i)
infile:close()
print(c)
os.execute("ping 127.0.0.1 -n 3 -w 1000 > nul")
end

