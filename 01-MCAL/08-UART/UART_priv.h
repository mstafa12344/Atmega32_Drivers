#ifndef UART_PRIV_H
#define UART_PRIV_H



#define UCSRA *((volatile uint8 * ) 0x2B )
#define UCSRB *((volatile uint8 * ) 0x2A )
#define UCSRC *((volatile uint8 * ) 0x40 )
#define UBBRL *((volatile uint8 * ) 0x29 )
#define UBBRH *((volatile uint8 * ) 0x40 )
#define UDR   *((volatile uint8 * ) 0x2C )

#define NORMAL_SPEED  0
#define DOUBLE_SPEED  1

#define DATA_5BIT          0
#define DATA_6BIT          1
#define DATA_7BIT          2
#define DATA_8BIT          3
#define DATA_9BIT          10

#define SYNC_MODE      0
#define ASYNC_MODE     1

#define PARITY_DISABLE 0
#define PARITY_ENABLE  1
#define PARITY_EVEN    2
#define PARITY_ODD     3

#define STOP_1BIT      0
#define STOP_2BIT      1

#define FALLING_TX_RISING_RX  0
#define FALLING_RX_RISING_TX  0
#endif
