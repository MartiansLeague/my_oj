os.execute("git status")

f =io.read()
if (f=="q" or f == "") then 
    print("exit")
else
    os.execute("git add .")
    os.execute("git commit -m \""..f.."\"")
    os.execute("start git push")
end