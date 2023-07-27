#ifndef   TIM0_PRIV_H
#define   TIM0_PRIV_H

#define TIM0_PRESCALLER_OFF  0
#define TIM0_PRESCALLER_1    1
#define TIM0_PRESCALLER_8    2
#define TIM0_PRESCALLER_64   3
#define TIM0_PRESCALLER_256  4
#define TIM0_PRESCALLER_1024 5
#define TIM0_EXTCLK_FALLING  6
#define TIM0_EXTCLK_RISING   7


#define TCCR0 *((volatile uint8*)0x53)
#define TCNT0 *((volatile uint8*)0x52)
#define OCR0  *((volatile uint8*)0x5c)
#define TIMSK *((volatile uint8*)0x59)

#endif
