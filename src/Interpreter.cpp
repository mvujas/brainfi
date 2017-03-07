#include "Interpreter.h"

inline lld max(lld a, lld b) {
    return (a > b) ? a : b;
}

Interpreter::Interpreter(std::string in) {
    preProcess(in);
    if(!error.empty())
        printf("%s\n", error.c_str());
    else
        mainloop();
}

Interpreter::~Interpreter() { }

void Interpreter::preProcess(std::string in) {
    std::string out = "";
    lld length = in.length();
    std::string err = "";
    lld reg = 0, loop = 0, maxreg = 0;
    for(lld i = 0; i <= length - 1; ++i) {
        switch(in[i]) {
            case '>': {
                out += in[i];
                ++reg;
            }
            break;
            case '<': {
                out += in[i];
                --reg;
            }
            break;
            case '+':
            case '-':
            case '.':
            case ',':
                out += in[i];
            break;
            case '[': {
                out += in[i];
                ++loop;
            }
            break;
            case ']': {
                out += in[i];
                --loop;
            }
            break;
        }
        maxreg = max(reg, maxreg);
        if(reg < 0) {
            err = "Memory error: -1";
            break;
        }
        if(loop < 0) {
            err = "Mismatched parentheses.";
            break;
        }
    }
    if(loop)
        err = "Mismatched parentheses.";
    code_length = out.length();
    error = err;
    for(lld i = maxreg + 1; i--;)
        registers.push_back(0);
    max_registers = maxreg + 1;
    code_length = out.length();
    current_register = 0;
    current_line = 0;
    code = out;
}

void Interpreter::command(char cmd) {
    switch(cmd) {
        case '>':
            ++current_register;
            break;
        case '<':
            --current_register;
            break;
        case '+':
            ++registers[current_register];
            break;
        case '-':
            --registers[current_register];
            break;
        case '.':
            printf("%c", registers[current_register]);
            break;
        case ',':
            scanf("%c", &registers[current_register]);
            break;
        case '[':
            loops.push(current_line);
            break;
        case ']':
            if(registers[current_register] > 0) {
               current_line = loops.top();
               loops.pop();
               --current_line;
            }
            break;
    }
    ++current_line;
}

void Interpreter::mainloop() {
    while(code_length - current_line)
        command(code[current_line]);
}
