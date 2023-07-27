/*****************************************/
/* Description : configur file for timer1*/
/* Author      : mustafa ali             */
/* Date        : sep 2022                */
/* Version     : 0.1V                    */ 
/*****************************************/

#ifndef TIM1_CFG_H
#define TIM1_CFG_H





/***************************************************/
#define TIM1_MODE            NORMAL_MODE

#define  NORMAL_MODE                               0
#define  PWM_PHASE_CORRECT_8BIT_MODE               1
#define  PWM_PHASE_CORRECT_9BIT_MODE               2
#define  PWM_PHASE_CORRECT_10BIT_MODE              3
#define  CTC_TOP_OCRA1_MODE                        4
#define  FAST_PWM_8BIT_MODE                        5
#define  FAST_PWM_9BIT_MODE                        6
#define  FAST_PWM_10BIT_MODE                       7
#define  PWM_PHASE_AND_FREQ_CORREC_TOP_ICR1_MODE   8
#define  PWM_PHASE_AND_FREQ_CORREC_TOP_OCRA1_MODE  9
#define  PWM_PHASE_CORRECT_TOP_ICR1_MODE           10
#define  PWM_PHASE_CORRECT_TOP_OCRA1_MODE          11
#define  CTC_TOP_ICR1_MODE                         12
#define  FAST_PWM_TOP_OCRA1_MODE                   13
#define  FAST_PWM_TOP_ICR1_MODE                    14
/*****************************************************/
/*****************************************************/
#define TIM1_MODE_CHANNEL1A    MODE_CHANNEL_A_NORMAL

#define MODE_CHANNEL_A_NORMAL                       0
#define MODE_CHANNEL_A_TOGGLE                       1
#define MODE_CHANNEL_A_CLEAR_OC1A                   2
#define MODE_CHANNEL_A_SET_OC1A                     3

/******************************************************/
/******************************************************/
#define TIM1_MODE_CHANNEL1B    MODE_CHANNEL_B_NORMAL

#define MODE_CHANNEL_B_NORMAL                       0
#define MODE_CHANNEL_B_TOGGLE                       1
#define MODE_CHANNEL_B_CLEAR_OC1B                   2
#define MODE_CHANNEL_B_SET_OC1B                     3

/******************************************************/
/******************************************************/
#define TIM1_PRESCALLER      CLK_DIV_BY8


#define NO_CLK             0
#define CLK_DIV_BY1        1
#define CLK_DIV_BY8        2
#define CLK_DIV_BY64       3
#define CLK_DIV_BY256      4
#define CLK_DIV_BY1024     5
#define CLK_EXT_FALLING    6
#define CLK_EXT_RISING     7
/******************************************************/
/******************************************************/
#define TIMER1_ICU_RISING_EDGE  0
#define TIMER1_ICU_FALLING_EDGE 1
/*****************************************************/
#endif
