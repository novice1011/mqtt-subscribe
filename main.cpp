#include <stdlib.h>
#include <stdio.h>
#include <mosquitto.h>
#include <pthread.h>

void *checking_subs(void *arg){
    struct mosquitto_message *msg;
    struct mosquitto *mosq = mosquitto_new("laptop-ubuntu", 1, NULL);
    while (1) {
        int rc = mosquitto_subscribe_simple(
                &msg, 1, true,
                "#", 0,
                "localhost", 1883,
                NULL, 60, true,
                NULL, NULL,
                NULL, NULL);//im trying to understand
        if(rc){
            printf("Error: %s\n", mosquitto_strerror(rc));
            mosquitto_lib_cleanup();
        }
        printf("%s %s\n", msg->topic, (char *)msg->payload);

        mosquitto_message_free(&msg);
    }

}

int main(int argc, char *argv[])
{

    mosquitto_lib_init();

    pthread_t thread_checking_subs;
    int err =pthread_create(&thread_checking_subs,NULL,checking_subs,NULL);

    printf("press any key to stop\n");
    getchar();

    mosquitto_lib_cleanup();
    return 0;
}
