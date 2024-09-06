/*
 * ESP.h
 *
 *  Created on: Jun 28, 2024
 *      Author: Joris Blankestijn
 */

#ifndef INC_ESP_H_
#define INC_ESP_H_

#include <stdbool.h>
#include <stdint.h>
#include "stm32l0xx_hal.h"
#include "utils.h"
#include "gpio.h"
#include "measurement.h"
#include "Battery_utils.h"

#define ESP_MAX_UART_RETRIES 2
#define ESP_MAX_BUFFER_SIZE 255
#define ESP_TX_BUFFER_SIZE 512
#define ESP_START_UP_TIME 700
#define ESP_RESPONSE_TIME 10
#define ESP_RESPONSE_LONG 50
#define ESP_WIFI_INIT_TIME 500
#define ESP_DMA_TIMEOUT 100
#define ESP_AT_COMMANDS_COUNT 4

#define AT_RESPONSE_OK "OK"
#define AT_RESPONSE_ERROR "ERROR"
#define AT_RESPONSE_READY "ready"
#define AT_RESPONSE_START ">"

#define AT_COMMANDS_SIZE 18

typedef enum {
  RECEIVE_STATUS_OK,
  RECEIVE_STATUS_ERROR,
  RECEIVE_STATUS_READY,
  RECEIVE_STATUS_INCOMPLETE,
  RECEIVE_STATUS_RETRY,
  RECEIVE_STATUS_START,
  RECEIVE_STATUS_TIMEOUT,
  RECEIVE_STATUS_UNPROGGED
}RECEIVE_STATUS;

typedef enum {
  RECEIVE_EXPECTATION_OK,
  RECEIVE_EXPECTATION_READY,
  RECEIVE_EXPECTATION_START,
  RECEIVE_EXPECTATION_WIFI
} AT_Expectation;

typedef enum {
  ESP_STATE_OFF,
  ESP_STATE_IDLE,
  ESP_STATE_INIT,
  ESP_STATE_WAIT_FOR_REPLY,
  ESP_STATE_SEND,
  ESP_STATE_NEXT_AT,
  ESP_STATE_PROCESS_AT,
  ESP_STATE_ERROR,
  ESP_STATE_WAIT_TO_SEND,
  ESP_STATE_RESET,
  ESP_STATE_BOOT,
  ESP_STATE_RECEIVE_DATA
} ESP_States;

typedef enum {
  AT_WAKEUP,
  AT_SET_RFPOWER,
  AT_CHECK_RFPOWER,
  AT_RESTORE,
  AT_CWINIT,
  AT_CWMODE1,
  AT_CWAUTOCONN,
  AT_CWJAP,
  AT_CWMODE3,
  AT_CWSAP,
  AT_CIPMUX,
  AT_WEBSERVER,
  AT_HTTPCPOST,
  AT_SENDDATA,
  AT_SLEEP
} AT_Commands;

void ESP_Init(UART_HandleTypeDef* espUart);
void ESP_Upkeep(void);
void ESP_Reset(void);
void ESP_Sleep(void);
void ESP_DeInit(void);

#endif /* INC_ESP_H_ */
void setMeasurement(float temp, float humid, uint16_t voc);
void setCharges(float charge, float solar);
