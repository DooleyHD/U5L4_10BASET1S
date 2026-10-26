/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef FSP_COMMON_API_H
#define FSP_COMMON_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <assert.h>
#include <stdint.h>

/* Includes FSP version macros. */
#include "fsp_version.h"

/*******************************************************************************************************************//**
 * @ingroup RENESAS_COMMON
 * @defgroup RENESAS_ERROR_CODES Common Error Codes
 * @brief All FSP modules share these common error codes.
 *
 * @{
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** This macro is used to suppress compiler messages about a parameter not being used in a function. The nice thing
 * about using this implementation is that it does not take any extra RAM or ROM. */

#define FSP_PARAMETER_NOT_USED(p)    (void) ((p))

/** Determine if a C++ compiler is being used.
 * If so, ensure that standard C is used to process the API information.  */
#if defined(__cplusplus)
 #define FSP_CPP_HEADER    extern "C" {
 #define FSP_CPP_FOOTER    }
#else
 #define FSP_CPP_HEADER
 #define FSP_CPP_FOOTER
#endif

/** FSP Header and Footer definitions */
#define FSP_HEADER    FSP_CPP_HEADER
#define FSP_FOOTER    FSP_CPP_FOOTER

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/** Macro to be used when argument to function is ignored since function call is NSC and the parameter is statically
 *  defined on the Secure side. */
#define FSP_SECURE_ARGUMENT    (NULL)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Common error codes */
typedef enum e_fsp_err
{
    FSP_SUCCESS = 0,

    FSP_ERR_ASSERTION             = 1,                 ///< A critical assertion has failed
    FSP_ERR_INVALID_POINTER       = 2,                 ///< Pointer points to invalid memory location
    FSP_ERR_INVALID_ARGUMENT      = 3,                 ///< Invalid input parameter
    FSP_ERR_INVALID_CHANNEL       = 4,                 ///< Selected channel does not exist
    FSP_ERR_INVALID_MODE          = 5,                 ///< Unsupported or incorrect mode
    FSP_ERR_UNSUPPORTED           = 6,                 ///< Selected mode not supported by this API
    FSP_ERR_NOT_OPEN              = 7,                 ///< Requested channel is not configured or API not open
    FSP_ERR_IN_USE                = 8,                 ///< Channel/peripheral is running/busy
    FSP_ERR_OUT_OF_MEMORY         = 9,                 ///< Allocate more memory in the driver's cfg.h
    FSP_ERR_HW_LOCKED             = 10,                ///< Hardware is locked
    FSP_ERR_IRQ_BSP_DISABLED      = 11,                ///< IRQ not enabled in BSP
    FSP_ERR_OVERFLOW              = 12,                ///< Hardware overflow
    FSP_ERR_UNDERFLOW             = 13,                ///< Hardware underflow
    FSP_ERR_ALREADY_OPEN          = 14,                ///< Requested channel is already open in a different configuration
    FSP_ERR_APPROXIMATION         = 15,                ///< Could not set value to exact result
    FSP_ERR_CLAMPED               = 16,                ///< Value had to be limited for some reason
    FSP_ERR_INVALID_RATE          = 17,                ///< Selected rate could not be met
    FSP_ERR_ABORTED               = 18,                ///< An operation was aborted
    FSP_ERR_NOT_ENABLED           = 19,                ///< Requested operation is not enabled
    FSP_ERR_TIMEOUT               = 20,                ///< Timeout error
    FSP_ERR_INVALID_BLOCKS        = 21,                ///< Invalid number of blocks supplied
    FSP_ERR_INVALID_ADDRESS       = 22,                ///< Invalid address supplied
    FSP_ERR_INVALID_SIZE          = 23,                ///< Invalid size/length supplied for operation
    FSP_ERR_WRITE_FAILED          = 24,                ///< Write operation failed
    FSP_ERR_ERASE_FAILED          = 25,                ///< Erase operation failed
    FSP_ERR_INVALID_CALL          = 26,                ///< Invalid function call is made
    FSP_ERR_INVALID_HW_CONDITION  = 27,                ///< Detected hardware is in invalid condition
    FSP_ERR_INVALID_FACTORY_FLASH = 28,                ///< Factory flash is not available on this MCU
    FSP_ERR_INVALID_STATE         = 30,                ///< API or command not valid in the current state
    FSP_ERR_NOT_ERASED            = 31,                ///< Erase verification failed
    FSP_ERR_SECTOR_RELEASE_FAILED = 32,                ///< Sector release failed
    FSP_ERR_NOT_INITIALIZED       = 33,                ///< Required initialization not complete
    FSP_ERR_NOT_FOUND             = 34,                ///< The requested item could not be found
    FSP_ERR_NO_CALLBACK_MEMORY    = 35,                ///< Non-secure callback memory not provided for non-secure callback
    FSP_ERR_BUFFER_EMPTY          = 36,                ///< No data available in buffer
    FSP_ERR_INVALID_DATA          = 37,                ///< Accuracy of data is not guaranteed

    /* Start of RTOS only error codes */
    FSP_ERR_INTERNAL     = 100,                        ///< Internal error
    FSP_ERR_WAIT_ABORTED = 101,                        ///< Wait aborted

    /* Start of UART specific */
    FSP_ERR_FRAMING            = 200,                  ///< Framing error occurs
    FSP_ERR_BREAK_DETECT       = 201,                  ///< Break signal detects
    FSP_ERR_PARITY             = 202,                  ///< Parity error occurs
    FSP_ERR_RXBUF_OVERFLOW     = 203,                  ///< Receive queue overflow
    FSP_ERR_QUEUE_UNAVAILABLE  = 204,                  ///< Can't open s/w queue
    FSP_ERR_INSUFFICIENT_SPACE = 205,                  ///< Not enough space in transmission circular buffer
    FSP_ERR_INSUFFICIENT_DATA  = 206,                  ///< Not enough data in receive circular buffer

    /* Start of SPI specific */
    FSP_ERR_TRANSFER_ABORTED = 300,                    ///< The data transfer was aborted.
    FSP_ERR_MODE_FAULT       = 301,                    ///< Mode fault error.
    FSP_ERR_READ_OVERFLOW    = 302,                    ///< Read overflow.
    FSP_ERR_SPI_PARITY       = 303,                    ///< Parity error.
    FSP_ERR_OVERRUN          = 304,                    ///< Overrun error.

    /* Start of FLASH Specific */
    FSP_ERR_FLASH_PE_FAILURE         = 500,            ///< Unable to enter Programming mode.
    FSP_ERR_FLASH_CMD_LOCKED         = 501,            ///< Peripheral in command locked state
    FSP_ERR_FCLK                     = 502,            ///< FCLK frequency is below the minimum supported value
    FSP_ERR_INVALID_LINKED_ADDRESS   = 503,            ///< Address is in the same bank as the code linked/executing from
    FSP_ERR_FLASH_BLANK_CHECK_FAILED = 504,            ///< Blank check operation failed

    /* Start of I3C Specific */
    FSP_ERR_INVALID_ALIGNMENT = 1003,                  ///< Invalid memory alignment found

    /* Start of touch panel framework specific */
    FSP_ERR_CALIBRATE_FAILED = 1200,                   ///< Calibration failed

    /* Start of IIRFA specific */
    FSP_ERR_IIRFA_ECC_1BIT = 1300,                     ///< 1-bit ECC error detected
    FSP_ERR_IIRFA_ECC_2BIT = 1301,                     ///< 2-bit ECC error detected

    /* Start of ECM Specific*/
    FSP_ERR_ECM_SELF_DIAG_FAIL     = 1350,             ///< One or more results didn't pass the ECM Self-Diagnosis Procedure.
    FSP_ERR_ECM_LOOPBACK_TEST_FAIL = 1351,             ///< ERROROUT is not match with error status

    /* Start of IP specific */
    FSP_ERR_IP_HARDWARE_NOT_PRESENT = 1400,            ///< Requested IP does not exist on this device
    FSP_ERR_IP_UNIT_NOT_PRESENT     = 1401,            ///< Requested unit does not exist on this device
    FSP_ERR_IP_CHANNEL_NOT_PRESENT  = 1402,            ///< Requested channel does not exist on this device

    /* Start of Message framework specific */
    FSP_ERR_NO_MORE_BUFFER           = 2000,           ///< No more buffer found in the memory block pool
    FSP_ERR_ILLEGAL_BUFFER_ADDRESS   = 2001,           ///< Buffer address is out of block memory pool
    FSP_ERR_INVALID_WORKBUFFER_SIZE  = 2002,           ///< Work buffer size is invalid
    FSP_ERR_INVALID_MSG_BUFFER_SIZE  = 2003,           ///< Message buffer size is invalid
    FSP_ERR_TOO_MANY_BUFFERS         = 2004,           ///< Number of buffer is too many
    FSP_ERR_NO_SUBSCRIBER_FOUND      = 2005,           ///< No message subscriber found
    FSP_ERR_MESSAGE_QUEUE_EMPTY      = 2006,           ///< No message found in the message queue
    FSP_ERR_MESSAGE_QUEUE_FULL       = 2007,           ///< No room for new message in the message queue
    FSP_ERR_ILLEGAL_SUBSCRIBER_LISTS = 2008,           ///< Message subscriber lists is illegal
    FSP_ERR_BUFFER_RELEASED          = 2009,           ///< Buffer has been released

    /* Start of ETHER Driver specific */
    FSP_ERR_ETHER_ERROR_NO_DATA              = 4000,   ///< No Data in Receive buffer.
    FSP_ERR_ETHER_ERROR_LINK                 = 4001,   ///< ETHERC/EDMAC has an error in the Auto-negotiation
    FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE    = 4002,   ///< As a Magic Packet is being detected, and transmission/reception is not enabled
    FSP_ERR_ETHER_ERROR_TRANSMIT_BUFFER_FULL = 4003,   ///< Transmit buffer is not empty
    FSP_ERR_ETHER_ERROR_FILTERING            = 4004,   ///< Detect multicast frame when multicast frame filtering enable
    FSP_ERR_ETHER_ERROR_PHY_COMMUNICATION    = 4005,   ///< ETHERC/EDMAC has an error in the phy communication
    FSP_ERR_ETHER_RECEIVE_BUFFER_ACTIVE      = 4006,   ///< Receive buffer is active.

    /* Start of ETHER_PHY Driver specific */
    FSP_ERR_ETHER_PHY_ERROR_LINK = 5000,               ///< PHY is not link up.
    FSP_ERR_ETHER_PHY_NOT_READY  = 5001,               ///< PHY has an error in the Auto-negotiation

    /* Start of BYTEQ library specific */
    FSP_ERR_QUEUE_FULL  = 10000,                       ///< Queue is full, cannot queue another data
    FSP_ERR_QUEUE_EMPTY = 10001,                       ///< Queue is empty, no data to dequeue

    /* Start of SENT specific */
    FSP_ERR_SENT_SPC_PULSE_LENGTH = 27000,             ///< SPC Pulse length is not in range between 1 and 128.
    FSP_ERR_SENT_ABORT_FAILED     = 27001,             ///< Fail to abort an communication.

    /* Start of SDMMC specific */
    FSP_ERR_CARD_INIT_FAILED     = 40000,              ///< SD card or eMMC device failed to initialize.
    FSP_ERR_CARD_NOT_INSERTED    = 40001,              ///< SD card not installed.
    FSP_ERR_DEVICE_BUSY          = 40002,              ///< Device is holding DAT0 low or another operation is ongoing.
    FSP_ERR_CARD_NOT_INITIALIZED = 40004,              ///< SD card was removed.
    FSP_ERR_CARD_WRITE_PROTECTED = 40005,              ///< Media is write protected.
    FSP_ERR_TRANSFER_BUSY        = 40006,              ///< Transfer in progress.
    FSP_ERR_RESPONSE             = 40007,              ///< Card did not respond or responded with an error.

    /* Start of FX_IO specific */
    FSP_ERR_MEDIA_FORMAT_FAILED = 50000,               ///< Media format failed.
    FSP_ERR_MEDIA_OPEN_FAILED   = 50001,               ///< Media open failed.

    /* Start of CAN specific */
    FSP_ERR_CAN_DATA_UNAVAILABLE   = 60000,            ///< No data available.
    FSP_ERR_CAN_MODE_SWITCH_FAILED = 60001,            ///< Switching operation modes failed.
    FSP_ERR_CAN_INIT_FAILED        = 60002,            ///< Hardware initialization failed.
    FSP_ERR_CAN_TRANSMIT_NOT_READY = 60003,            ///< Transmit in progress.
    FSP_ERR_CAN_RECEIVE_MAILBOX    = 60004,            ///< Mailbox is setup as a receive mailbox.
    FSP_ERR_CAN_TRANSMIT_MAILBOX   = 60005,            ///< Mailbox is setup as a transmit mailbox.
    FSP_ERR_CAN_MESSAGE_LOST       = 60006,            ///< Receive message has been overwritten or overrun.
    FSP_ERR_CAN_TRANSMIT_FIFO_FULL = 60007,            ///< Transmit FIFO is full.

    /* Start of CANXL Specific */
    FSP_ERR_CANXL_LRAM_INSUFFICIENT = 60100,           ///< Not enough Local RAM memory allocated

    /* Start of COMMS specific */
    FSP_ERR_COMMS_BUS_NOT_OPEN = 0x40000,              ///< Bus is not open.

    /* Start of ADCK specific */
    FSP_ERR_ADCK_GROUP_MASK_NOT_SUPPORT = 0x30000,     ///< ADCK group mask is not supported.
    FSP_ERR_ADCK_CHANNEL_NOT_SUPPORT    = 0x30001,     ///< ADCK channel is not supported.
    FSP_ERR_SGX_DISABLED                = 0x30002,     ///< Use ADCK scan group x when it is disabled.
    FSP_ERR_PWM_DIAG_DISABLED           = 0x30003,     ///< Use ADCK PWM-Diag when it is disabled.
    FSP_ERR_SG_DIAG_DISABLED            = 0x30004,     ///< Use ADCK scan group x when it is disabled.
    FSP_ERR_SG_AD_TIMER_ACTIVE          = 0x30005,     ///< Request to enable/disable T&H when any scan group or AD timer is active.
    FSP_ERR_TH_STOP = 0x30006,                         ///< Try to use T&H group A for T&H group B when it is stopped.

    /* Start of CGC specific */
    FSP_ERR_CLOCK_INACTIVE                = 70000,     ///< Inactive clock specified
    FSP_ERR_NOT_STABILIZED                = 70001,     ///< Clock has not stabilized
    FSP_ERR_GEAR_DOWN_PLL_DIVIDER_INVALID = 70003,     ///< Invalid PLL divider used for gear down operation
    FSP_ERR_INVALID_CLOCK_SOURCE          = 70004,     ///< Invalid clock source
    FSP_ERR_CLOCK_IN_USE = 70005,                      ///< Clock source has been start

    /* Start of VMON specific */
    FSP_ERR_VMON_DIAGNOSTIC_RESET_FAIL      = 0x30007, ///< VMON diagnostic reset behavior is incorrect.
    FSP_ERR_VMON_DIAGNOSTIC_VMONOUT_FAIL    = 0x30008, ///< VMON diagnostic vmonout behavior is incorrect.
    FSP_ERR_VMON_DIAGNOSTIC_FAIL            = 0x30009, ///< VMON diagnostic result does not match the expected value.
    FSP_ERR_VMON_DIAGNOSTIC_CLEAR_FLAG_FAIL = 0x30010, ///< Failed to clear VMONF and VMONOUTF flags during VMON diagnostic.

    /* Start of Clock monitor specific */
    FSP_ERR_CLOCK_MONITOR_SELFTEST_FAIL = 0x30011,     ///< CLMA selftest fail.

    /* Start of FLEXRAY specific */
    FSP_ERR_RECEIVE_MESSAGE_BUFFER      = 0x50001,     ///< FLEXRAY has error for receive message buffer.
    FSP_ERR_NOT_TRANSMITTED             = 0x50002,     ///< FLEXRAY has not been transmitted.
    FSP_ERR_TRANSMIT_VIOLATION_CHANNELS = 0x50003,     ///< FLEXRAY has error transmitted in channel A or/and Channel B.
    FSP_ERR_CMD_NOT_ACCEPTED            = 0x50004,     ///< FLEXRAY has error send cmd.
    FSP_ERR_RAM_OVERRUN                 = 0x50005,     ///< FLEXRAY has error configuration data section in RAM.
} fsp_err_t;

/** Common version structure */
typedef struct st_fsp_version
{
    uint8_t code_version_minor;        ///< Code minor version
    uint8_t code_version_major;        ///< Code major version
    uint8_t api_version_minor;         ///< API minor version
    uint8_t api_version_major;         ///< API major version
} fsp_version_t;

/** @} */

/***********************************************************************************************************************
 * Function prototypes
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
