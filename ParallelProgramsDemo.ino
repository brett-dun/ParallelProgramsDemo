
#include "ArduinoAssembly/opcodes.h"

#define TEMP 1
#define A 2
#define B 3
#define C 4

int acc;

int memory[64];

int assembly[11][3] = {
  {TEMP,DC,0},
  {A,DC,8},
  {B,DC,-2},
  {C,DC,3},
  {0,LOAD,B},
  {0,MULT,C},
  {0,ADD,A},
  {0,DIV,B},
  {0,SUB,A},
  {0,STORE,TEMP},
  {0,PRINT,TEMP},
};

void setup() {

  Serial.begin(9600);

  const byte PRGM_LEN = sizeof(assembly)/sizeof(assembly[0]);
  
  //loop through the assembly code for the entire length of the code or until "END" is reached
  for (int i = 0; i < PRGM_LEN && assembly[i][1] != END; i++) {
    //Serial.print("i:");
    //Serial.println(i);
    switch (assembly[i][1]) {

      case LOAD:
        acc = memory[assembly[i][2]];
        break;

      case STORE:
        memory[assembly[i][2]] = acc;
        break;
      
      case ADD:
        acc += memory[assembly[i][2]];
        break;

      case SUB:
        acc -= memory[assembly[i][2]];
        break;

      case MULT:
        acc *= memory[assembly[i][2]];
        break;
        
      case DIV:
        acc /= memory[assembly[i][2]];
        break;

      case BE:
        if (acc == 0) {
          for (int j = 0; j < PRGM_LEN; j++) {
            if (assembly[j][0] == assembly[i][2]) {
              i = j;
              break;
            }
          }
        }
        break;

      case BG:
        if (acc > 0) {
          for (int j = 0; j < PRGM_LEN; j++) {
            if (assembly[j][0] == assembly[i][2]) {
              i = j;
              break;
            }
          }
        }
        break;

      case BL:
        if (acc < 0) {
          for (int j = 0; j < PRGM_LEN; j++) {
            if (assembly[j][0] == assembly[i][2]) {
              i = j;
              break;
            }
          }
        }
        break;

      case BU:
        for (int j = 0; j < PRGM_LEN; j++) {
          if (assembly[j][0] == assembly[i][2]) {
            i = j;
            break;
          }
        }
        break;

      case READ:
        acc = Serial.read();
        break;

      case PRINT:
        Serial.println(memory[assembly[i][2]]);
        break;

      case DC:
        memory[assembly[i][0]] = assembly[i][2];
        break;

      case NOT:
        acc = ~acc;
        break;

      case AND:
        acc &= memory[assembly[i][2]];
        break;

      case OR:
        acc |= memory[assembly[i][2]];
        break;

      case XOR:
        acc ^= memory[assembly[i][2]];
        break;

      case NAND:
        acc = ~(acc & memory[assembly[i][2]]);
        break;

      case NOR:
        acc = ~(acc | memory[assembly[i][2]]);
        break;

      case XNOR:
        acc = ~(acc ^ memory[assembly[i][2]]);
        break;

      case LSHIFT:
        acc = acc << memory[assembly[i][2]];
        break;

      case RSHIFT:
        acc = acc >> memory[assembly[i][2]];
        break;

      case ABS:
        acc = acc >= 0 ? acc : -acc;
        break;

      case MOD:
        acc %= memory[assembly[i][2]];
        break;

      case SQRT:
        acc = sqrt(acc);
        break;

      case POW:
        acc = pow(acc, memory[assembly[i][2]]);
        break;

      case LN:
        acc = log(acc);
        break;

      case LOG:
        acc = log(memory[assembly[i][2]])/log(acc);
        break;

      case MODE:
        pinMode(memory[assembly[i][2]], acc ? OUTPUT : INPUT);
        break;

      case DWRITE:
        digitalWrite(memory[assembly[i][2]], acc ? 1 : 0);
        break;

      case AWRITE:
        analogWrite(memory[assembly[i][2]], acc);
        break;

      case MILLIS:
        acc = millis();
        break;

      case CLEAR:
        acc = 0;
        break;
      
    }
     
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
