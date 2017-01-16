# 編譯時要加上-fPIC 用來產生position-independent code。也可以用-fpic
#參數。(不太清楚差異，只知道-fPIC 較通用於不同平台，但產生的code較大
#而且編譯速度較慢)。
gcc -c -fPIC crc32.c

#-shared 表示要編譯成shared library
#-Wl 用於參遞參數給linker，因此-soname與libmylib.so.1會被傳給linker處理。
#-soname用來指名soname 為limylib.so.1
#library會被輸出成libmylib.so.1.0.0 (也就是real name)
#若不指定soname 的話，在編譯結連後的執行檔會以連時的library檔名為
#soname，並載入他。否則是載入soname指定的library檔案。

gcc -shared -Wl,-soname,libcrc32.so.1 -o libcrc32.so.1.0.0 crc32.o

#可以利用objdump 來看library 的soname。
#$ objdump -p libmylib.so | grep SONAME
#SONAME libmylib.so.1
#若不指名-soname參數的話，則library不會有這個欄位資料。
#在編譯後再用ln 來建立soname 與linker name 兩個檔案。


ln -s libcrc32.so.1.0.0 libcrc32.so
ln -s libcrc32.so.1.0.0 libcrc32.so.1
