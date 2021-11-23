#include <array>
#include <random>
#include <future>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <csignal>
#include <unistd.h>
#include <iostream>    // for cout
#include <fstream>
#include <queue>       // for queue
#include <vector>      // for vector
//control de señales
void signal_handler( int signal_num ) {	
    switch (signal_num){
    case  SIGINT: //ctrl c
        std::cout << "Detención no permitida" << std::endl;
        break;
    case SIGTSTP://ctrl z
        std::cout << "Detención no permitida" << std::endl;
        break;
    case SIGQUIT://ctrl "\"
        std::cout << "Detención no permitida" << std::endl;
        break;
    case SIGUSR1://kill 
        exit(EXIT_SUCCESS);
        break;
    case SIGUSR2://kill
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
} 
int main(){
    long int a = 0, b = 1, c = 0;//variables fib
    int impar = 1;//variable series impares
    int hijo = fork();
    //señales
    std::signal(SIGUSR1, signal_handler);
    std::signal(SIGUSR2, signal_handler);
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTSTP, signal_handler);
    std::signal(SIGQUIT, signal_handler);
    for(int i = 0; i < 50; i++) {
        if (hijo == 0){ //impar
            if(impar % 2 != 0){
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Valor Impar: " << impar << " - PID = " << getpid() << "\n";
            }
         } 
        else{//fib
            c = a + b;
            a = b;
            b = c;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Valor Fibonacci: " << c  << " - PPIDE = " << getpid() << std::endl;
        }
        impar=impar+2;
    }
    exit(EXIT_SUCCESS);
}
