# Brainfuck Interpreter
Written in C++

## Brainfuck syntax
```brainfuck
> 	Increment the pointer.
< 	Decrement the pointer.
+ 	Increment the byte at the pointer.
- 	Decrement the byte at the pointer.
. 	Output the byte at the pointer.
, 	Input a byte and store it in the byte at the pointer.
[ 	Jump forward past the matching ] if the byte at the pointer is zero.
] 	Jump backward to the matching [ unless the byte at the pointer is zero.
```

### How to execute
```bash
git clone https://github.com/mvujas/brainfuck_interpreter
cd brainfuck_interpreter
make
```

