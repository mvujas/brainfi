# brainfi
Brainfuck interpreter written in C++

### Brainfuck syntax
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

### How to compile
```bash
git clone https://github.com/mvujas/brainfuck_interpreter
cd brainfuck_interpreter
make
# If you want to be able to use brainfi anywhere on your system uncomment following command. Don't do it if you don't understand what it does
#sudo cp bin/Debug/brainfuckInterpreter /usr/bin/brainfi
```

