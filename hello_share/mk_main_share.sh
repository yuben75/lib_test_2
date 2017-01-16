
# 方法１
#gcc main.c libmylib.so -o hello_share	

# -L 參數用來指定要搜尋程式庫的目錄，`.’ 表示搜尋現在所在的目錄	
# 通常預設會搜/usr/lib 或/lib 等目錄。	
# 參數用來指定要連結的程式庫，’mylib’ 表示要與mylib進行連結
# 他會搜尋library名稱前加`lib’後接`.a’的檔案來連結。
gcc main.c -L. -lmylib -o hello_share


#linker會搜尋libmylib.so 來進行連結。
#如果目錄下同時有static與shared library的話，會以shared為主。
#使用-static 參數可以避免使用shared連結。
#$ gcc main.c -static -L. -lmylib
#此時可以用ldd 看編譯出的執行檔與shared程式庫的相依性
#$ldd a.out
#linux-gate.so.1 => (0xffffe000)
#[1;33mlibmylib.so.1 => not found[m
#libc.so.6 => /lib/libc.so.6 (0xb7dd6000)
#/lib/ld-linux.so.2 (0xb7f07000)
#輸出結果顯示出該執行檔需要libmylib.so.1 這個shared library。
#會顯示not found 因為沒指定該library所在的目錄，所找不到該library。
#因為編譯時有指定-soname參數為libmylib.so.1 的關係，所以該執行檔會
#載入libmylib.so.1。否則以libmylib.so連結，執行檔則會變成要求載入
#libmylib.so
#$ ./a.out
#./a.out: error while loading shared libraries: [1;33mlibmylib.so.1[m:
#cannot open shared object file: No such file or directory
#因為找不到libmylib.so.1 所以無法執行程式。
#
#有幾個方式可以處理。
#a. 把libmylib.so.1 安裝到系統的library目錄，如/usr/lib下
#b. 設定/etc/ld.so.conf ，加入一個新的library搜尋目錄，並執行ldconfig
#更新快取
#c. 設定LD_LIBRARY_PATH 環境變數來搜尋library
#這個例子是加入目前的目錄來搜尋要載作的library
#
#$ LD_LIBRARY_PATH=. ./a.out

#Hello world.







