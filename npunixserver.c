#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <stdio.h>
int main()
{
//variable declaration
int sockfd, clientsockfd,n,addrlen;
struct sockaddr_un servaddr, clientaddr;
char buffer[256];
addrlen = sizeof(clientaddr);
// Create socket

sockfd = socket(AF_UNIX, SOCK_STREAM, 0); 
// Delete if the file name already exists
unlink("/home/hit/NP/mysock");
//fill zeros in the structure
bzero(&servaddr, sizeof(servaddr));
// Fill the structure with necessary information
servaddr.sun_family = AF_UNIX;
strcpy(servaddr.sun_path, "/home/hit/NP/mysock");
// Binding socket
bind (sockfd, &servaddr, sizeof(servaddr));
// Listen on the socket
listen(sockfd, 5);
//accept a new connection
clientsockfd = accept(sockfd, &clientaddr, &addrlen);
//receiving what the client has sent us
read(clientsockfd, &buffer, sizeof(buffer));
printf("\n Client sent us : %s \n", buffer);
// send some reply to the client
printf("Please enter some message to client: ");
bzero(buffer,256);
fgets(buffer,255,stdin);
write(clientsockfd,&buffer, sizeof(buffer));
close(clientsockfd);
close(sockfd);
return 0;
}
