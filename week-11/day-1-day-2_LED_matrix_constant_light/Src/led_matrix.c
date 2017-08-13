/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"

#include "stm32f7xx_hal_gpio.h"
#include "stm32f7xx_hal_rcc_ex.h"



/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];

// Mutex definition
osMutexDef(LED_MATRIX_MUTEX_DEF);

// Mutex global variable
osMutexId led_matrix_mutex_id;

/* Private function prototypes -----------------------------------------------*/
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);
/* Private functions ---------------------------------------------------------*/

// TODO:
// Write this function!
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state) {
	// TODO:
	// Wait for the mutex

	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!

	// TODO:
	// Release the mutex
}

// TODO:
// Write this function!

void led_matrix_update_thread(void const *argument)
{
	// TODO:

	//Define led matrix 2D arrays
// used pins: GPIOB, C, G, I, H
/*
	row rows[LED_MATRIX_ROWS][2] = {
			{GPIOC, GPIO_PIN_6},	//row 1: PC6
			{GPIOG, GPIO_PIN_6},	//row 2: PG6
			{GPIOB, GPIO_PIN_4},	//row 3: PB4
			{GPIOG, GPIO_PIN_7},	//row 4: PG7
			{GPIOI, GPIO_PIN_0},	//row 5: PI0
			{GPIOH, GPIO_PIN_6},	//row 6: PH6
			{GPIOI, GPIO_PIN_3},	//row 7: PI3
	};

	col coloumns[LED_MATRIX_COLS][2] = {
			{GPIOB, GPIO_PIN_15},	//coloumn 1: PB15
			{GPIOB, GPIO_PIN_14},	//coloumn 2: PB14
			{GPIOI, GPIO_PIN_1},	//coloumn 3: PI1
			{GPIOB, GPIO_PIN_9},	//coloumn 4: PB9
			{GPIOB, GPIO_PIN_8},	//coloumn 5: PB8
	};
*/

	//Initialize struct
	GPIO_InitTypeDef GPIO_InitDef;

	// Enable clock on used pins	// clock, azaz hogy a processzor meghajtsa a portot
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();

	// add in one definiton all used pins! 0, 1, 3, 4, 6, 7, 8, 9, 14, 15
	GPIO_InitDef.Pin = GPIO_PIN_15 | GPIO_PIN_14 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_4 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_1 | GPIO_PIN_0 | GPIO_PIN_3;
	//Mode output
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP; 	// Output Push Pull Mode
	//Output type
	GPIO_InitDef.Pull = GPIO_NOPULL;			// set nopull
	//Speed
	GPIO_InitDef.Speed = GPIO_SPEED_FREQ_HIGH;	// speed is not relevant, High is ok

	//Initialize pins on GPIOx ports
	HAL_GPIO_Init(GPIOB, &GPIO_InitDef);	// GPIOB
	HAL_GPIO_Init(GPIOC, &GPIO_InitDef);	// GPIOC
	HAL_GPIO_Init(GPIOG, &GPIO_InitDef);	// GPIOG
	HAL_GPIO_Init(GPIOI, &GPIO_InitDef);	// GPIOI
	HAL_GPIO_Init(GPIOH, &GPIO_InitDef);	// GPIOH */

/* Turn on every LED!
	// Switch on coloumn's - every port
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET); 	// col 1 power supply from PB15, col 1
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); 	// col 2 power supply from PB14, col 2
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET); 	// col 3 power supply from PI1, col 3
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET); 	// col 4 power supply from PB9, col 4
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET); 	// col 5 power supply from PB8, col 5

	// set to 0 the rows - switch on every rows
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);	// row 1 PC6
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);	// row 2 PG6
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);	// row 3 PB4
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);	// row 4 PG7
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);	// row 5 PI0
	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);	// row 6 PH6
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_RESET);	// row 7 PI3
*/

/* Light on only the 3rd coloumn!
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET); 	// col 3 power supply from PI1, col 3
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);	// row 2 PG6
*/

/* Light up everything excluded the 4th row!
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET); 	// col 1 power supply from PB15, col 1
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); 	// col 2 power supply from PB14, col 2
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET); 	// col 3 power supply from PI1, col 3
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET); 	// col 4 power supply from PB9, col 4
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET); 	// col 5 power supply from PB8, col 5

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);	// row 1 PC6
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);	// row 2 PG6
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);	// row 3 PB4
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);	// row 4 PG7
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);	// row 5 PI0
	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);	// row 6 PH6
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_RESET);	// row 7 PI3
*/

/*	// Light up only the 4th row!
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET); 	// col 1 power supply from PB15, col 1
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); 	// col 2 power supply from PB14, col 2
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET); 	// col 3 power supply from PI1, col 3
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET); 	// col 4 power supply from PB9, col 4
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET); 	// col 5 power supply from PB8, col 5

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);	// row 1 PC6
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);	// row 2 PG6
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);	// row 3 PB4
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);	// row 4 PG7
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);	// row 5 PI0
	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);	// row 6 PH6
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);	// row 7 PI3
*/

/*	// Light up only LED 3;5 !
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET); 	// col 1 power supply from PB15, col 1
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); 	// col 2 power supply from PB14, col 2
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET); 	// col 3 power supply from PI1, col 3
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET); 	// col 4 power supply from PB9, col 4
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET); 	// col 5 power supply from PB8, col 5

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);	// row 1 PC6
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);	// row 2 PG6
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);	// row 3 PB4
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);	// row 4 PG7
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);	// row 5 PI0
	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);	// row 6 PH6
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);	// row 7 PI3
*/

	// Light up only LED 4,2 and 4,4 !
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET); 	// col 1 power supply from PB15, col 1
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); 	// col 2 power supply from PB14, col 2
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET); 	// col 3 power supply from PI1, col 3
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET); 	// col 4 power supply from PB9, col 4
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET); 	// col 5 power supply from PB8, col 5

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);	// row 1 PC6
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);	// row 2 PG6
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);	// row 3 PB4
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);	// row 4 PG7
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);	// row 5 PI0
	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);	// row 6 PH6
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);	// row 7 PI3


/*	// Light up only LED 4,2 and 3,3 !
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET); 	// col 1 power supply from PB15, col 1
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); 	// col 2 power supply from PB14, col 2
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET); 	// col 3 power supply from PI1, col 3
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET); 	// col 4 power supply from PB9, col 4
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET); 	// col 5 power supply from PB8, col 5

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);	// row 1 PC6
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);	// row 2 PG6
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);	// row 3 PB4
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);	// row 4 PG7
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);	// row 5 PI0
	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);	// row 6 PH6
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);	// row 7 PI3
	// lights up: 3,2; 3,3, 4,2, 4,3. Without mutex and for loop this task cannot be done.
*/


/* 4. oszlopban csak 1 NEM világít
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET); // col 4 power supply from PB9, col 4
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);	// row 4 PG7
*/


	// elv: felhúzó ellenállásnál a pinstate legyen "1", de potenciálkülönbség kell,
	// azaz a kimenetet meg le kell húzni 0-ra.


// void HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)
// GPIOx: where x can be (A..K) to select the GPIO peripheral.
// user manual (UM1907) page 23 table 4 -> 1-es oszlopot a D11-be kötöttem be ->
// pin name: D11 => STM32 pin: PB15 -> GPIOx-nél X=B
// @param  GPIO_Init: pointer to a GPIO_InitTypeDef structure that contains
// the configuration information for the specified GPIO peripheral.


	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEF

	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality

		// Step 1:
		// Iterate through every column or row

			// Step 2:
			// Wait for the mutex


			// Step 3:
			// Turn on the column or row


			// Step 4:
			// Turn on the leds in that column or row


			// Step 5:
			// Release the mutex


			// Step 6:
			// Delay


			// Step 7:
			// Turn off the column or row
	}

	// Terminating thread
	while (1) {
		LCD_ErrLog("led_matrix - terminating...\n");
		osThreadTerminate(NULL);
	}

}


// This thread is a waterfall type animation
void led_matrix_waterfall_thread(void const *argument)
{
	while (1) {
		for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
			for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
				led_matrix_set(r, c, 1);
				osDelay(50);
				led_matrix_set(r, c, 0);
			}
		}
	}

	while (1) {
		LCD_ErrLog("led_matrix_waterfall - terminating...\n");
		osThreadTerminate(NULL);
	}

}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
