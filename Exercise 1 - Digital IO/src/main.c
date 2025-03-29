/**
 ******************************************************************************
 * @ File           : main.c
 * @ Author         : Dylan George
 * @ Brief          : Main program body
 ******************************************************************************
 * @ Description
 * This file is to the main executable for Exercise 1. It is currently in progress
 *
 ******************************************************************************
 */

#include "io_module.h"

void toggle_led() {
    uint8_t current = io_get_led();
    io_set_led(!current);
}

int main(void) {
    io_init(toggle_led);

    while (1) {
        // main loop can do other stuff
    }
}


