#ifndef	__App_main_H__
#define	__App_main_H__


/*******************************************************************************
* Includes
*******************************************************************************/
/* general */
#include "product.h"
#include "R_driver_typedef.h"
#include "R_driver_general.h"
#include "config.h"
#include "R_COM.h"

/* product-specified */
#include "R_driver_port.h"
#include "R_driver_clock.h"
#include "R_driver_reset.h"
#include "R_driver_standby.h"
#include "R_driver_INTC.h"

/* target module */
#include "App_ETNF_cfg.h"
#include "R_driver_ETNF.h"
#include "App_interrupt.h"

/*******************************************************************************
* Definition
*******************************************************************************/

#define	R_PORT_GetPortInput(n, m)   	((rPPRn(n).UINT16 & (1 << m)) >> m)

/*******************************************************************************
* Global variables
*******************************************************************************/

	

/*******************************************************************************
* Prototype declarations of functions
* functional definition
*******************************************************************************/
void App_main( void );


#endif /* __App_main_H__ */


