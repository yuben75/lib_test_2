#include <stdio.h>

#include <stdlib.h>
#include <dlfcn.h>

int main() 
{
	void *handle;
	void (*f)();
	char *error;



	/* 開啟之前所撰寫的libmylib.so 程式庫*/

	handle = dlopen("./libmylib.so", RTLD_LAZY);
	if( !handle ) {
		fputs( dlerror(), stderr);
		exit(1);
	}
	
	
	/* 取得hello function 的address */
	f = dlsym(handle, "hello");
	if(( error=dlerror())!=NULL) {
		fputs(error, stderr);
		exit(1);
	}
	/* 呼叫該function */
	f();

	/* 取得world function 的address */
	f = dlsym(handle, "world");
	if(( error=dlerror())!=NULL) {
		fputs(error, stderr);
		exit(1);
	}
	/* 呼叫該function */
	f();

	dlclose(handle);

}
