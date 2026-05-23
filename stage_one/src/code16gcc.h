/*
  Hey GCC please stop changing my code behind my back :)

  This doesn't work...

  GCC still likes to use 32 bit registers which when I've explictely written 16 bit regs

  Edit: it's just standard bullshittery that makes it so that GCC uses 32 bit registers. Ie, good luck writing code for anything older then the 80386
 */

.code16gcc
.code16
