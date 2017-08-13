/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h" //osMutexDef

#include "stm32f7xx_hal_gpio.h"
#include "stm32f7xx_hal_rcc_ex.h"


/* Private typedef -----------------------------------------------------------*/
typedef struct ledmatrix_gpio_pin{	// struktura tipusa: ledmatrix_gpio_pin
	GPIO_TypeDef 	GPIOx;			// GPIO pin of the row.
    uint16_t 		PIN;      		// pin of the row.
}ledmatrix_struct;					// ez a struktura ilyen változótípusú: ledmatrix_struct. változó értékadás majd alább!

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
// Create ledmatrix_struct typed variables with values: fill up with GPIOx and GPIO_PIN values for each rows
ledmatrix_struct ledmatrixrows[LED_MATRIX_ROWS] = { //put ledmatrix rows in a struct
		{GPIOC, GPIO_PIN_6},	//row 1: PC6	//
		{GPIOG, GPIO_PIN_6},	//row 2: PG6
		{GPIOB, GPIO_PIN_4},	//row 3: PB4
		{GPIOG, GPIO_PIN_7},	//row 4: PG7
		{GPIOI, GPIO_PIN_0},	//row 5: PI0
		{GPIOH, GPIO_PIN_6},	//row 6: PH6
		{GPIOI, GPIO_PIN_3},	//row 7: PI3
};

ledmatrix_struct ledmatrixcoloumns[LED_MATRIX_COLS] = {
		{GPIOB, GPIO_PIN_15},	//coloumn 1: PB15
		{GPIOB, GPIO_PIN_14},	//coloumn 2: PB14
		{GPIOI, GPIO_PIN_1},	//coloumn 3: PI1
		{GPIOB, GPIO_PIN_9},	//coloumn 4: PB9
		{GPIOB, GPIO_PIN_8},	//coloumn 5: PB8
};
		/* Notes - typdef struct
 * analógia: int a = 1;  // változótípus változónév = értékadás;
 * vált.típus változónév[elemszám] = {
		{strukttípuselsõelem értéke, struktípusmásodikelem értéke}; */

// create variable for General Purpose I/O pin initialization
GPIO_InitTypeDef GPIO_InitDef;
// Fill up the GPIO_InitDef variable for pin initialization
GPIO_InitDef.Pin = GPIO_PIN_15 | GPIO_PIN_14 | GPIO_PIN_9 | GPIO_PIN_8 |
		GPIO_PIN_4 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_1 | GPIO_PIN_0 |
		GPIO_PIN_3;							// add all used pins! 0, 1, 3, 4, 6, 7, 8, 9, 14, 15
GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP; 	// Output Push Pull Mode
GPIO_InitDef.Pull = GPIO_NOPULL;			// Output type: set nopull, since we will define it separately according to the animation
GPIO_InitDef.Speed = GPIO_SPEED_FREQ_HIGH;	// Speed: not relevant, High is ok

// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];

/* Mutex definition - Create and use Mutex: steps
	https://www.keil.com/pack/doc/cmsis/RTOS/html/group__CMSIS__RTOS__MutexMgmt.html
	1. Declare the mutex container and initialize the mutex:
		osMutexDef (uart_mutex);    // Declare mutex
		osMutexId  (uart_mutex_id); // Mutex ID
	2. Create the mutex in a thread:
		uart_mutex_id = osMutexCreate(osMutex(uart_mutex));
	3. Acquire the mutex when peripheral access is required:
		osMutexWait(uart_mutex_id, osWaitForever);
	4. When finished with the peripheral access, release the mutex:
		osMutexRelease(uart_mutex_id);
*/
osMutexDef(LED_MATRIX_MUTEX_DEF); 	//declare mutex
// Mutex global variable
osMutexId led_matrix_mutex_id; 		// mutex ID

/* Private function prototypes -----------------------------------------------*/
// led_matrix_set(row, col, state) @brief: set the state of the selected LED!
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);

/* Private functions ---------------------------------------------------------*/

// TODO:
// Write this function!
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state) {

	// TODO:
	// Wait for the mutex
	osMutexWait(led_matrix_mutex_id, osWaitForever);

	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!
	led_matrix_state[row][col] = state;

	// TODO:
	// Release the mutex
	osMutexRelease(led_matrix_mutex_id);
}

// TODO:
// Write this function!
void led_matrix_update_thread(void const *argument)
{
	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array
	// First, enable clock on used pins	// clock, azaz hogy a processzor meghajtsa a portot
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();

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
	/* Light up only LED 4,2 and 4,4 !
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
*/

	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEF
	led_matrix_mutex_id = osMutexCreate(osMutex(LED_MATRIX_MUTEX_DEF)); // Create the mutex in a thread:

	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality

		// Step 1:
		// Iterate through every column or row / COL!
		for (int i = 0; i < LED_MATRIX_COLS, i++) {
			// Step 2:
			// Wait for the mutex
			osMutexWait(led_matrix_mutex_id, osWaitForever);

			// Step 3:
			// Turn on the column or row / COL!
			HAL_GPIO_WritePin(ledmatrixcoloumns[i].GPIOx, ledmatrixrows[i].PIN, state);
			// Step 4:
			// Turn on the leds in that column or row / COL!


			// Step 5:
			// Release the mutex
			osMutexRelease(led_matrix_mutex_id);

			// Step 6:
			// Delay
			osDelay(250);

			// Step 7:
			// Turn off the column or row

		}
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
		for (uint8_t row = 0; row < LED_MATRIX_ROWS; row++) {
			for (uint8_t col = 0; col < LED_MATRIX_COLS; col++) {
				led_matrix_set(row, col, 1);
				osDelay(50);
				led_matrix_set(row, col, 0);
			}
		}
	}

	while (1) {
		LCD_ErrLog("led_matrix_waterfall - terminating...\n");
		osThreadTerminate(NULL);
	}

}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
