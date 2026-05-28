#include"header.h"

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./client client_id\n");
        return 0;
    }

    int myid = atoi(argv[1]);

    key_t key;
    int msgid;

    struct msgbuf v;

    key = ftok("server",65);

    msgid = msgget(key,0666);

    if(msgid < 0)
    {
        perror("msgget");
        return 0;
    }

    if(fork()==0)
    {
        while(1)
        {
            msgrcv(msgid,
                   &v,
                   sizeof(v)-sizeof(long),
                   myid,
                   0);

            printf("\nMessage from Client %d : %s\n",
                    v.sender_id,
                    v.msg);
        }
    }

    while(1)
    {
        printf("Enter Receiver ID : ");
        scanf("%d",&v.receiver_id);

        printf("Enter Message : ");
        scanf(" %[^\n]",v.msg);

        v.sender_id = myid;

        v.mtype = SERVER_TYPE;

        msgsnd(msgid,
               &v,
               sizeof(v)-sizeof(long),
               0);

        if(strcmp(v.msg,"exit")==0)
        {
            printf("Client Exiting...\n");
            break;
        }
    }
}
