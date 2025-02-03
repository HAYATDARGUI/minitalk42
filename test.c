
// #include <signal.h>
// #include <stdio.h>
// #include <sys/signal.h>
// #include <unistd.h>

// void handler(int n)
// {
//     printf("heeho %d",n);
// }

// int main()
// {
//     struct sigaction x;

//     x.sa_handler=handler;
//     sigemptyset(&x.sa_mask);
//     x.sa_flags =0;
//     if(sigaction(SIGEV_SIGNAL, &x, NULL)== -1)
//     {
//         printf("error sigation");
//         return 1;
//     }
//     pause();
//     return 0;
// }
// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>

// void handler(int signum) {
//     printf("Signal %d reçu! Mais je ne vais pas terminer.\n", signum);
// }

// int main() {
//     signal(SIGINT, handler); // Attraper Ctrl + C
//     while (1) {
//         printf("En attente de signal... (Ctrl + C pour tester)\n");
//         sleep(2);
//     }
//     return 0;
// }

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void send_message(pid_t server_pid, const char *message) {
    int i = 0;
    while (message[i] != '\0') {
        unsigned char encrypted_char = message[i];
        int j = 7;
        while (j >= 0) {
            if (encrypted_char & (1 << j)) {
                kill(server_pid, SIGUSR1);
            } else {
                kill(server_pid, SIGUSR2);
            }
            usleep(100); // Shorter delay
            j--;
        }
        i++;
    }
    kill(server_pid, SIGUSR2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    const char *message = argv[2];

    send_message(server_pid, message);

    printf("Message sent to server with PID %d\n", server_pid);
    return 0;
}
