#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include<stdio.h>
int main()
{
//declare variables here
int sockfd,n;
struct sockaddr_un servaddr;
char buffer[256];
// Creating socket
sockfd = socket(AF_UNIX, SOCK_STREAM, 0); 
//fill the structure with zeros
bzero(&servaddr, sizeof(servaddr));

// Fill the structure with necessary information for later computation
servaddr.sun_family = AF_UNIX;
strcpy(servaddr.sun_path, "/home/hit/NP/mysock");
// Connect to the server which is listening to the clients
connect(sockfd, &servaddr, sizeof(servaddr));
printf("Please enter your message: ");
bzero(buffer,256);
fgets(buffer,255,stdin);
// write some message to the server
write(sockfd, buffer,sizeof(buffer)); 
// get what the server says
read(sockfd, &buffer, sizeof(buffer));
printf("\n Server says : %s \n", buffer);
close(sockfd);
return 0;
}
