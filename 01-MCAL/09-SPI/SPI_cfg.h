

#ifndef SPI_CFG_H_
#define SPI_CFG_H_

/*****************************************/
/*if the SPI Master Select Clock polarity*/
/*****************************************/

#define LEAD_RIS_TRE_FALL		0
#define LEAD_FALL_TRE_RIS		1

#define CLK_POLARITY_MODE  LEAD_RIS_TRE_FALL

/*****************************************/
/*if the SPI Master Select Clock Phase   */
/*****************************************/
#define LEAD_SAMPL_TRE_SETUP	0
#define LEAD_SETUP_TRE_SAMPL	1

#define CLK_PHASE_MODE  LEAD_SAMPL_TRE_SETUP

/*****************************************/
/*if the SPI Master Select Clock Rate    */
/*****************************************/


#define FCPU_DIV2				0
#define FCPU_DIV4				1
#define FCPU_DIV8				2
#define FCPU_DIV16				3
#define FCPU_DIV23				4
#define FCPU_DIV64				5
#define FCPU_DIV128				6

#define  SPI_CLK_RATE  FCPU_DIV8


/*****************************************/
/*if the SPI Master Select Data Order    */
/*****************************************/

#define FIRST_MS				0
#define FIRST_LS				1

#define DATA_ORDER  FIRST_MS

#endif
