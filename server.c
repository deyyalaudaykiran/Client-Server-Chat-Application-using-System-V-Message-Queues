#include"header.h"

int main()
{
    key_t key;
    int msgid;

    struct msgbuf v;

    key = ftok("server",65);

    msgid = msgget(key,0666 | IPC_CREAT);

    if(msgid < 0)
    {
        perror("msgget");
        return 0;
    }

    printf("Server Started...\n");

    while(1)
    {
        msgrcv(msgid,
               &v,
               sizeof(v)-sizeof(long),
               SERVER_TYPE,
               0);

        if(strcmp(v.msg,"exit")==0)
        {
            printf("Client %d exited\n",v.sender_id);
            continue;
        }

        printf("Message from Client %d to Client %d : %s\n",
                v.sender_id,
                v.receiver_id,
                v.msg);

        v.mtype = v.receiver_id;

        msgsnd(msgid,
               &v,
               sizeof(v)-sizeof(long),
               0);
    }
}
