#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <bits/stdc++.h>
typedef long long lld;

class Interpreter
{
    public:
        Interpreter(std::string in);
        virtual ~Interpreter();
        void command(char cmd);

    protected:
        lld current_register, max_registers, code_length, current_line;
        std::vector<int> registers;
        std::stack<lld> loops;
        std::string code, error;
        void preProcess(std::string in);
        void mainloop();

};

#endif // INTERPRETER_H
