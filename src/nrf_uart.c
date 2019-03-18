
#include "nrf_delay.h"
#include "nrf_uart.h"
#include "nrf_uarte.h"
#include "app_uart.h"

#define UART_HWFC APP_UART_FLOW_CONTROL_DISABLED

#define MAX_TEST_DATA_BYTES     (15U)                /**< max number of test bytes to be used for tx and rx. */
#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 256                         /**< UART RX buffer size. */

app_uart_comm_params_t comm_params =
{
    RX_PIN_NUMBER,
    TX_PIN_NUMBER,
    RTS_PIN_NUMBER,
    CTS_PIN_NUMBER,
    UART_HWFC,
    false,
    NRF_UART_BAUDRATE_115200
};


void uart_error_handle(app_uart_evt_t * p_event)
{
    if (p_event->evt_type == APP_UART_COMMUNICATION_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_communication);
    }
    else if (p_event->evt_type == APP_UART_FIFO_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_code);
    }
}
void printd(char *str)
{
    int i = 0;

    while(str[i] != '&')
    {
	while( app_uart_put(str[i]) != NRF_SUCCESS);
	i = i + 1;
    }
}
void uart_init(void)
{
   uint32_t err_code;

   APP_UART_FIFO_INIT(&comm_params,
                       UART_RX_BUF_SIZE,
                       UART_TX_BUF_SIZE,
                       uart_error_handle,
                       APP_IRQ_PRIORITY_LOWEST,
                       err_code);

    APP_ERROR_CHECK(err_code);

//    printd("dongpangfudontesT&");
}

