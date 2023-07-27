/******************************************************/
/********* Name     : Mustafa Ali *********************/
/********* comonent : TWI         *********************/
/********* Date     : 16/12/2022  *********************/
/******************************************************/

#ifndef I2C_PRIV_H
#define I2C_PRIV_H

typedef enum
{
	NOERROR,
	START_CONDITION_ERROR,
	REPEAT_START_CONDITION_ERROR,
	SEND_ADD_AND_Write_Error,
	SEND_ADD_AND_Read_Error,
	MASTER_WRITE_BYTE_ERROR,
	MASTER_READ_BYTE_ERROR,
}TWI_ERRStatus;
	
#define TWCR   *((volatile uint8*)0X56) /*control register*/

#define TWCR_TWINT   7                 /* INTERRUPT FLAG    */
#define TWCR_TWEA    6                 /*Enable acknowldge  */
#define TWCR_TWSTA   5                 /* start condition   */
#define TWCR_TWSTO   4                 /*stop condition     */
#define TWCR_TWWC    3                 /*write collision    */
#define TWCR_TWEN    2                 /*twi enable         */
#define TWCR_TWIE    0                 /*interrupt enable   */

#define TWDR  *((volatile uint8*)0X23) /*data register      */

#define TWAR *((volatile uint8*)0X22)  /*address register   */

#define TWAR_TWGCE  0                  /*General call Enable*/

#define TWSR  *((volatile uint8*)0X21) /* status register   */

#define TWSR_TWPS0  0                  /* pres bit0         */
#define TWSR_TWPS0  1                  /* pres bit1         */

#define TWBR *((volatile uint8*)0X20)  /* bit rate reg      */ 

/* stusts of operations*/

#define START_ACK                0X08  /*Start has been sent*/
#define REP_START_ACK            0X10  /*REPEATED START     */
#define SLAVE_ADD_AND_WR_ACK     0X18  /*Masrer transmit ,write req*/
#define SLAVE_ADD_AND_RD_ACK     0x40  /*Masrer transmit ,read req*/
#define MASTER_WR_BYTE_ACK       0X28  /*MASTER SEND DATA ACK     */
#define MASTER_RD_BYTE_WITH_ACK  0X50  /*MASTER RECIEVE DATA WITH ACK*/  
#define MASTER_RD_BYTE_WITH_NACK 0X58  /*MASTER RECIEVE DATA WITHOUT ACK*/
#define SLAVE_ADD_RECVD_RD_REQ   0XA8
#define SLAVE_ADD_RECVD_WR_REQ   0X60
#define SLAVE_DATA_RECEIVED      0X80
#define SLAVE_BYTE_TANSMITTED    0XB8
 
#endif