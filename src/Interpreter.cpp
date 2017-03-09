#include "Interpreter.h"

inline lld max(lld a, lld b) {
    return (a > b) ? a : b;
}

Interpreter::Interpreter() :
    max_registers(1),
    registers(std::vector<int>(1, 0)),
    current_register(0) { }

Interpreter::~Interpreter() { }

void Interpreter::preProcess(std::string in) {
    std::string out = "";
    lld length = in.length();
    lld loop = 0;
    for(lld i = 0; i <= length - 1; ++i) {
        switch(in[i]) {
            case '>':
            case '<':
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
        if(loop < 0) {
            error = "Mismatched parentheses.";
            break;
        }
    }
    if(loop)
        error = "Mismatched parentheses.";
    code_length = out.length();
    if(!error.empty())
        printf("%s\n", error.c_str());
    code_length = out.length();
    current_line = 0;
    code = out;
}

void Interpreter::command(char cmd) {
    switch(cmd) {
        case '>':
            ++current_register;
            if(current_register == max_registers) {
                ++max_registers;
                registers.push_back(0);
            }
            break;
        case '<':
            --current_register;
            if(current_register < 0) {
                error = "Memory error: -1";
                printf("%s\n", error.c_str());
                current_register = 0;
            }
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

void Interpreter::execute(std::string source) {
    preProcess(source);
    while((code_length - current_line) && error.empty())
        command(code[current_line]);
}
