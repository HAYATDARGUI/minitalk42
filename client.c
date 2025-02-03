
// #include <signal.h>
// typedef void (*my_signal_handler)(int);
// #include <unistd.h>
// void	print_bit(unsigned char octet)
// {
//     int i=8;
//     int bit;
//     while (i--)
//     {
//         bit=(octet >>i &1)+'0';
//         write(1, &bit, 1);
//     }
// }
// void handler(int i)
// {
//     my_signal_handler x;
// }
// int main()
// {
//     struct sigaction x;

//     x.sa_handler=handler;
// }
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

unsigned char received_char = 0;
int bit_count = 0;

void handle_sigusr1(int sig) {
    (void)sig;
    received_char = (received_char << 1) | 1; 
    bit_count++;

    if (bit_count == 8)
    { 
        write(1, &received_char, 1);
        received_char = 0;
        bit_count = 0;
    }
}

void handle_sigusr2(int sig) {
    (void)sig;
    received_char = (received_char << 1);
    bit_count++;

    if (bit_count == 8)
    {  
        write(1, &received_char, 1);
        received_char = 0;
        bit_count = 0;
    }
}

int main() {
    printf("Server running with PID: %d\n", getpid());

    struct sigaction sa1, sa2;
    sa1.sa_handler = handle_sigusr1;
    sa2.sa_handler = handle_sigusr2;
    sigemptyset(&sa1.sa_mask);
    sigemptyset(&sa2.sa_mask);
    sa1.sa_flags = 0;
    sa2.sa_flags = 0;
    sigaction(SIGUSR1, &sa1, NULL);
    sigaction(SIGUSR2, &sa2, NULL);

    while (1) {
    
         pause();
    }
    
    return 0;
}
