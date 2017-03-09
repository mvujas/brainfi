#ifndef INTERPRETER_H
#define INTERPRETER_H
#define BFI_VERSION "0.0.1"
#define LAST_UPDATE "2017-03-09"
#define AUTHOR "Milos Vujasinovic"
#include <bits/stdc++.h>
typedef long long lld;

class Interpreter
{
    public:
        Interpreter();
        virtual ~Interpreter();
        void execute(std::string source);

    protected:
        lld current_register, max_registers, code_length, current_line;
        std::vector<int> registers;
        std::stack<lld> loops;
        std::string code, error;
        void command(char cmd);
        void mainloop();
        void preProcess(std::string in);
};

#endif // INTERPRETER_H
