#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>






void app(){
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	char userName [10] ="tbenson";
	char passwd[11] ="cs1380";
	if(login(userName,passwd)){
		getInspirationalMsg(userName);
	}
	gettimeofday(&stop, NULL);
	printf("Runtime %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); 

}


int main (){
	app();
}
