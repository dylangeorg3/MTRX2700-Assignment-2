#ifndef IO_MODULE.H
#define IO_MODULE.H

// Include standard STM32 libraries
#include <stdint.h>
#endif

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
