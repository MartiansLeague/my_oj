PREFLE =  tui.c linklist.c goods.c serialize.c 
CC= gcc -Wall -DLOCAL -O3 -ansi
#默认
all:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	$(CC) $(PREFLE) main.c -o erp4c.exe
	erp4c.exe
#发布版本
release:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	gcc -Wall  -O3 -ansi $(PREFLE) main.c -o erp4c.exe
	erp4c.exe
#不清空编译输出，用以查找warring
dontclear:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	$(CC) -DDONTCLEARSCREEN -Wno-incompatible-pointer-types  $(PREFLE) main.c -o erp4c.exe
	erp4c.exe

#输出最小化，不开启-Wall,只显示主要的警告
min:
	gcc -DLOCAL -DDONTCLEARSCREEN  -O0 -ansi $(PREFLE) main.c -o erp4c.exe
	erp4c.exe
#测试商品模块
goods:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	$(CC) $(PREFLE) testgoods.c -o testgoods.exe
	testgoods.exe
#测试链表模块
linklist:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	$(CC) $(PREFLE)  testlinklist.c -o testlinklist.exe
	testlinklist.exe
#测试序列化模块
serialize:
	-lua addbuildnum.lua
	-git add .
	-git commit -m "build erp4c" 
	$(CC) $(PREFLE)  testserialize.c -o testserialize.exe
	testserialize.exe