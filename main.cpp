#include "Interpreter.h"
#include "path.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

void startup_notification() {
    printf("Brainfuck interpreter 'brainfi'\nVersion: %s (updated on %s)\n", BFI_VERSION, LAST_UPDATE);
}

void command_line_interface() {
    startup_notification();
    Interpreter brainfi;
    std::string input;
    while(true) {
        printf("brainfi> ");
        std::cin >> input;
        if(input == ".exit" || input == "exit")
            break;
        brainfi.execute(input);
    }
}

void process_file(std::string executable, std::string file) {
    path PATH(executable);
    PATH.add(file);
    std::ifstream input_file(PATH.pth);
    if(input_file.is_open())
    {
        std::string line, source = "";
        while(getline(input_file,line))
            source += line;
        input_file.close();
        Interpreter brainfi;
        brainfi.execute(source);
        printf("\n");
    }
    else
        printf("File '%s' does not exist.\n", PATH.pth.c_str());
}

int main(int argc, char *argv[])
{
    if(argc > 1) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        if(cwd == NULL) {
            printf("Program is terminated due to getcwd error.\n");
            return 0;
        }
        std::string input_file = "";
        for(int i = 1; i < argc; ++i) {
            if(i != 1)
                input_file += " ";
            input_file += argv[i];
        }
        process_file(cwd, input_file);
    }
    else
        command_line_interface();
    return 0;
}
