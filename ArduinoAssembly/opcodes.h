
//Opcodes
//Usage: [label] OPCODE LOC [comments]

//Opcode 0 does nothing (this is so that we can have fixed array sizes)

//Opcodes 1 through 14 follow ACSL rules (http://www.apcomputerscience.com/cst/topic_descriptions/assembly.pdf)

//Contents of LOC are placed in the ACC. LOC is unchanged.
#define LOAD 1
//Contents of ACC are placed into the LOC. ACC is unchanged.
#define STORE 2
//Contents of LOC are added to the contents of the ACC. The sum is stored in the ACC. LOC is unchanged.
#define ADD 3
//Contents of LOC are subtracted from the contents of the ACC. The difference is stored in the ACC. LOC is unchanged.
#define SUB 4
//The contents of LOC are multiplied by the contents of the ACC. The product is stored in the ACC. LOC is unchanged.
#define MULT 5
//Contents of LOC are divided into the contents of the ACC.  The quotient is stored into the ACC. LOC is unchanged.
#define DIV 6
//Branch to instruction labeled with LOC if ACC = 0.
#define BE 7
//Branch to instruction labeled with LOC if ACC > 0.
#define BG 8
//Branch to instruction labeled with LOC if ACC < 0.
#define BL 9
//Branch unconditionally to instruction with LOC.
#define BU 10
//Program terminates. LOC field is ignored.
#define END 11
//Read data [implementation TBD]
#define READ 12
//Print the contents of LOC [implementation dependent: default implementation uses serial output.]
#define PRINT 13
//The value of the memory word defined by the LABEL feild is defined to contain the specified constant. The LABEL field is mandatory for this opcode. The ACC is not modified.
#define DC 14


//Opcodes 15-23 are binary operations

//Bitwise NOT on ACC. Result is stored into ACC. LOC is ignored.
#define NOT 15
//Bitwise AND on ACC and LOC. Result is stored into ACC. LOC is unchanged.
#define AND 16
//Bitwise OR on ACC and LOC. Result is stored into ACC. LOC is unchanged.
#define OR 17
//Bitwise exclusive OR on ACC and LOC. Result is stored into ACC. LOC is unchanged.
#define XOR 18
//Bitwise NOT AND on ACC and LOC. Result is stored into ACC. LOC is unchanged.
#define NAND 19
//Bitwise NOT OR on ACC and LOC. Result is stored into ACC. LOC is unchanged.
#define NOR 20
//Bitwise exclusive NOT OR on ACC and LOC. Result is stored into ACC. LOC is unchanged.
#define XNOR 21
//ACC is bit shifted to the left by the number of bits given in LOC. Result is stored in ACC. LOC is unchanged.
#define LSHIFT 22
//ACC is bit shifted to the right by the number of bits given in LOC. Result is stored in ACC. LOC is unchanged.
#define RSHIFT 23


//Opcodes 24-29 are math operations

//Absolute value of the ACC. Result is stored to ACC. LOC is ignored.
#define ABS 24
//The contents of ACC is modulated by LOC. Result is stored in ACC. LOC remains unchanged.
#define MOD 25
//Square root of the ACC is stored back into ACC. LOC is ignored.
#define SQRT 26
//Contents of LOC are used as the exponent that the base, ACC, is raised to. The result is stored to ACC. LOC is unchanged.
#define POW 27
//
#define LN 28
//Contents of LOC are used in a logarithmic operation where ACC is used as the base. The result is stored into ACC. LOC is unchanged.
#define LOG 29


//Opcodes 30-35 are arduino operations

//The pin LOC is set to read if the value of ACC is 0, set to write otherwise. LOC is unchanged.
#define MODE 30
//
#define DWRITE 31
//
#define AWRITE 32
//
#define DREAD 33
//
#define AREAD 34
//store the current time in milliseconds into ACC. LOC is ignored.
#define MILLIS 35


//Other opcodes

//Sets ACC to 0. LOC is ignored.
#define CLEAR 36
