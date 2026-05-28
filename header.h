#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h> 
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf{
    long mtype;
    int sender_id;
    int receiver_id;
    char msg[100];

};
#define SERVER_TYPE 100
