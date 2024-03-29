#ifndef _LoadRegister
#define _LoadRegister

#include "Operation.cpp"
#include "MemoryUnit.cpp"
class LoadRegister: public Operator
{
  public:
  LoadRegister(MemortUnit* Current_ram,MemortUnit* Current_register, MemortUnit* controller): Operator(Current_ram,Current_register,controller) {};

  void apply()
  {
    unsigned short instruct= controller->readInstruction(1);
    unsigned char reg= (instruct & 0x0f00)>>8;
    unsigned char address=(instruct & 0x00ff);
    unsigned char BitPattern=ram->get((unsigned char)address);
    registors->set((unsigned char)reg,BitPattern);
  }
}
;
#endif
