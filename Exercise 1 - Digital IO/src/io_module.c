// io_module.c

#include "io_module.h"
#include "stm32f303xc.h"

static void (*button_callback)(void) = 0;
static uint8_t led_state = 0;
static uint8_t led_update_allowed = 1;

void io_init(void (*callback)(void)) {
    button_callback = callback;

    // Enable GPIO clocks
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOEEN;

    // LED (PE8) as output
    GPIOE->MODER &= ~(0x3 << (2 * 8));
    GPIOE->MODER |=  (0x1 << (2 * 8));

    // Button (PA0): input mode by default

    // Enable SYSCFG
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // EXTI0 config
    SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0_Msk; // PA0
    EXTI->RTSR |= EXTI_RTSR_TR0;
    EXTI->IMR  |= EXTI_IMR_MR0;

    NVIC_SetPriority(EXTI0_IRQn, 1);
    NVIC_EnableIRQ(EXTI0_IRQn);

    // Enable timer (e.g., TIM2)
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    TIM2->PSC = 64000 - 1;   // Prescaler (assume 64 MHz / 64k = 1kHz)
    TIM2->ARR = 200;         // 200ms period
    TIM2->DIER |= TIM_DIER_UIE;
    TIM2->CR1 |= TIM_CR1_CEN;

    NVIC_EnableIRQ(TIM2_IRQn);
}

// LED access
void io_set_led(uint8_t state) {
    led_state = state;
}

uint8_t io_get_led(void) {
    return led_state;
}

// Timer interrupt for rate-limiting LED update
void TIM2_IRQHandler(void) {
    TIM2->SR &= ~TIM_SR_UIF; // Clear update flag

    if (led_update_allowed) {
        if (led_state)
            GPIOE->ODR |= (1 << 8);
        else
            GPIOE->ODR &= ~(1 << 8);

        led_update_allowed = 0;
    }

    led_update_allowed = 1;
}

// Button ISR
void EXTI0_IRQHandler(void) {
    if (button_callback != 0)
        button_callback();

    EXTI->PR |= EXTI_PR_PR0;
}
