
# 方法１
#gcc main.c libmylib.a -o hello_static	

# -L 參數用來指定要搜尋程式庫的目錄，`.’ 表示搜尋現在所在的目錄	
# 通常預設會搜/usr/lib 或/lib 等目錄。	
# 參數用來指定要連結的程式庫，’mylib’ 表示要與mylib進行連結
# 他會搜尋library名稱前加`lib’後接`.a’的檔案來連結。
gcc main.c -L. -lmylib -o hello_static
