# MTRX2700-Assignment-2 🤖

## Group X - NAME **

### **Authors ✍️:**  
- **NAME**: SID  
- **Dylan George**: 530839244  
- **NAME**: SID 
- **NAME**: SID 

## Roles and Responsibilities 👷‍♂️

| Name            | Role                  | Responsibilities                      |  
|----------------|----------------------|--------------------------------------|  
| Inez  | Serial, GPIO, Integration     | Task 2, 3, 5 |  
| Dylan      | Admin, GPIO, Serial, Integration   | Task 2, 3, 5, Minutes |  
| Sam   | Memory, Hardware Delays, Integration    | Task 1, 4, 5|  
| Tony     |  Memory, GPIO, Serial   | Task 1, 2, & 3 | 

## Project Overview 📜
This repository was made to meet requirements for the ASM Lab (Assignment 1) as part of coursework in MTRX2700 (Mechatronics 2) at the **University of Sydney**. The code is all in **ARM Assembly** language and was written for, and tested on, **STM32F3 Discovery** micro-controllers.  

The code is broken into separate modules, with sub-tasks for each module, each entailing their own respective files. Descriptions of each task, and how to run the code are explained in the drop-downs in the **Module Overview** section.  

It is recommended to create a new project in **STM32CubeIDE** using the downloaded Git repository (see details below). You can then run each sub-project by navigating into its respective directory or by manually copying individual files into a new project.

### How to Download the Repo ⬇️
Clone the repository in your terminal using:
   ```bash
   git clone https://github.com/dylangeorg3/MTRX2700-Assignment-1.git
   ```
Note that the repository is not publically available, for reasons pertaining to academic integrity.
## Module Overview 📂

## Requirements
### Software Requirements
- **STM32CubeIDE** (Required for building, debugging, and uploading code to the STM32F3Discovery board).
- **Serial Monitor Tool**
  - **Windows:** [PuTTY](https://www.putty.org/)
  - **MacOS:** [CuteCom](https://cutecom.sourceforge.io/)

### Hardware Requirements
- **One or Two STM32F3 Discovery Boards**
  - Two boards are required for **Exercise 3E** and **Integration**, connected via serial communication.
- **3 x 30AWG female to female jumper cables**
  - Required to connect the two boards in the aforementioned tasks
  - They are relatively cheap, and available at [Core Electronics](https://core-electronics.com.au/female-to-female-dupont-line-40-pin-10cm-24awg.html?gad_source=1&gclid=Cj0KCQjw4v6-BhDuARIsALprm32sz4oCAe0GOuz8QdB3mVvDaUouCLKruWdyOYjAz_SCJl4C5ngxbRAaAuPGEALw_wcB)


## Installation & Setup
### STM32CubeIDE Installation
1. Download STM32CubeIDE from [ST’s official website](https://www.st.com/en/development-tools/stm32cubeide.html).
2. Follow the installation instructions provided on the website for your operating system.

### Serial Monitor Installation
- **Windows (PuTTY):**
  1. Download from [PuTTY’s official website](https://www.putty.org/).
  2. Install using the provided installer.
- **MacOS (CuteCom):**
  1. Install via Homebrew (Recommended):
     ```bash
     brew install cutecom
     ```
  2. Or download from the [CuteCom website](https://cutecom.sourceforge.io/).


<details>
<summary><strong>Exercise 1 - Memory & Pointers 🧠</strong></summary>

<details>
<summary><strong>Task 1A</strong></summary>

#### **Usage**
The user can specify the string in the .data section:
```assembly
ascii_string: .asciz "y y"  @ Ascii string to convert
```

#### **Description**
An `ascii_string` and `ascii_buffer` are initialized to store a string we want to convert and its conversion.  
Based on a value in R2, the `ascii_string` gets converted from uppercase to lowercase, or vice versa.  
After choosing which conversion to make, we enter a loop that iterates over the string and stores each  
character with an offset of either `+0x20` or `-0x20` in the `ascii_buffer`. This will convert the character to  
either uppercase or lowercase. Non-letter characters remain unmodified.

</details>

<details>
<summary><strong>Task 1B</strong></summary>

#### **Usage**
In the data section, the user can specify the input string for detection:
```assembly
palindrome_string: .asciz "rar" @ Set palindrome (each character occupies a byte of memory)
```

#### **Description**
The main idea of this code is to iterate over the `palindrome_string` from the last character  
to the beginning and store it backward into the `palindrome_buffer`. With a reversed copy of  
the original string, we can directly compare the two to determine if a string is a palindrome.

</details>

<details>
<summary><strong>Task 1C</strong></summary>

#### **Usage**
In the first three lines, the user can modify the input string and shift register:
```assembly
string:       .asciz "Hey"  @ input string
shift_value:  .word 3       @ shift index
```

#### **Description**
This module implements a Caesar cipher in ARM Assembly. The program loads an input string  
and a shift value, then iterates through each character, applying a shift while maintaining  
case sensitivity. It checks for uppercase (`'A'–'Z'`) and lowercase (`'a'–'z'`) ranges, wrapping  
around when necessary.  

</details>

</details>

---

<details>
<summary><strong>Exercise 2 - Digital I/O 💡</strong></summary>

<details>
<summary><strong>Task 2A</strong></summary>

#### **Usage**
In the main function, the user can modify the bitmask to change the LED pattern:
```assembly
LDR R4, =0b10000100 @ Bit mask
```
#### **Description**
The program first enables the peripheral clocks by enabling GPIOA, GPIOC, and GPIOE by setting the corresponding bits in the AHBENR. Then, it configures GPIOE pins PE8-PE15 as outputs by writing 0x5555 to the upper half of the MODER. A bit mask is then loaded continuously to GPIOE ODR (bits 8-15) to control output states.
</details>

<details>
<summary><strong>Task 2B</strong></summary>

#### **Usage**
The user can press the USER button on the microcontroller to increment the LED's on the output.

#### **Description**
The program enables peripheral clocks and initializes GPIOE for LED control, the same as in task 2A. It continuously checks the button state and waits for a press. When pressed, it waits until the button is released before updating the LEDs. If all LEDs are ON, the bitmask resets to 0. Otherwise, the LED pattern is left-shifted and incremented, turning on one more LED at each press.

</details>

<details>
<summary><strong>Task 2C</strong></summary>

#### **Usage**
The user can press the USER button on the microcontroller to increment/decrement the LED's on the output.

#### **Description**
The program enables peripheral clocks and initializes GPIOE for LED control. It continuously checks the button state and waits for a press. When pressed, it waits until the button is released before updating the LEDs. If all LEDs are ON, the mode switches to count-down, and LEDs start turning off one by one each time the button is pressed. If all LEDs are OFF, the mode switches to count-up, turning LEDs on one by one each time the button is pressed. The bitmask is updated using left or right shifts, depending on the current mode.

</details>

<details>
<summary><strong>Task 2D</strong></summary>

#### **Usage**
The user can provide an input string. The program will count and display the number of vowels in binary on the LED's, if the button is pressed it will display the number of consonants (also in binary)

#### **Description**
The program enables peripheral clocks and initializes GPIOE for LED control. It then iterates through the [NEED TO FINISH DEPENDING ON WHICH CODE WE USE]

</details>

</details>

---

<details>
<summary><strong>Exercise 3 - Serial Communication 🔌</strong></summary>

<details>
<summary><strong>Task 3A</strong></summary>

#### **Usage**
The user can change the string to be transmitted, and its length, in lines 20-21:
```assembly
tx_string: .asciz "Bane\r\n\0" @ Define a string
tx_length: .byte 7 @ Define string length
```
The user should then open CuteCom (Mac) or PuTTY (Windows) and connect to the USB port you have connected to the microcontroller, as well as choosing the appropriate baud rate (115200 in this case). Then, debug `assembly.s` in the STM32CubeIDE and press play, or run the code. The string will then be printed onto the CuteCom/PuTTY terminal when the user button on the microcontroller is pressed.

#### **Description**
This ARM assembly program waits for a button press, then transmits a predefined string over UART. It initializes hardware, continuously checks the button state, and debounces input before sending data. The program loops back to wait for another button press after transmission.

</details>

<details>
<summary><strong>Task 3B</strong></summary>

#### **Description**
This task recieves an input string of characters from the PC serial communication terminal, which it will read character by character before storing it in memory on the microcontroller.

#### **Usage**
First open CuteCom (Mac) or PuTTY (Windows) and connect to the USB port you have connected to the microcontroller, as well as choosing the appropriate baud rate (115200 in this case). Then, debug `assembly.s` in the STM32CubeIDE and manually step through the code until line 39 is reached:
```assembly
	loop_forever:
    	LDR R0, =USART1            @ Load base address of UART
```
You will then resume the code by pressing F8, and send the given string using the CuteCom serial communication terminal. Suspend the code. To check that the message has been recieved, enable Memory Browser, and paste in the address that is currently stored in `R6`. The resulting hex values stored at this address will be displayed, as well as the ASCII representation on the far right where your string should now be stored.
The program has allocated for 62 bytes (or 62 ASCII characters) to be transmitted as seen in lines 13-17 of `assembly.s`. 
```assembly
	@ Allocate space for the incoming buffer
	incoming_buffer: .byte 62
	
	@ Store the size of the buffer
	incoming_counter: .byte 62
```
If you wish to transmit a longer message, you will need to increase the buffer and counter sizes accordingly.
</details>

<details>
<summary><strong>Task 3C</strong></summary>
  
#### **Description**
This program is the same as Task 3B, but now it explicitly highlights how to adjust the baud rate to ensure two microcontrollers communicate correctly over UART at the same baud rate, even when the clock speed changes.
  
#### **Usage**
To change the baud rate of USART1, access the `initialise.s` file. On lines 55-57, we have the following code:
```assembly
	MOV R1, #0x46               @ BRR value (see table in README.md for explanation)
	LDR R0, =USART1             @ Base address for the UART register to turn clocks on/off
	STRH R1, [R0, #USART_BRR]   @ Store BRR value directly in the first half word (16 bits) of baud rate register
```
Here, `#USART_BRR` is the **address offset** in the UART register where the baud rate value is stored, as defined in definitions.s:
```assembly
	.equ USART_BRR, 0x0C
```
The baud rate register (BRR) value is calculated using the formula:  
$$BRR = \frac{Clock Frequency}{Baud Rate}$$.

The exact baud rate value needed depends on the clock frequency, which can either be 8 MHz (when using an external clock) or 24 MHz (when using the phase-locked loop, PLL).
For convenience, here are precomputed values:
| Clock Frequency | Baud Rate | BRR Value (Decimal) | BRR (Hex) |
|----------------|----------|----------------------|-----------|
| 8 MHz         | 9600     | 833                  | 0x341     |
| 8 MHz         | 115200   | 69                   | 0x45      |
| 24 MHz        | 9600     | 2500                 | 0x9C4     |
| 24 MHz        | 115200   | 208                  | 0xD0      |

For programs moving forward, including integration, we will be using a baud rate of 115200, with 8MHz clocks. Hence our BRR value will be `0x45`.


</details>


<details>
<summary><strong>Task 3D</strong></summary>

#### **Usage**
First open CuteCom (Mac) or PuTTY (Windows) and connect to the USB port you have connected to the microcontroller, as well as choosing the appropriate baud rate (115200 in this case). Then, debug `assembly.s` in the STM32CubeIDE and press play, or run the code. Input a string into the terminal and press enter. The string will then be printed onto the CuteCom/PuTTY terminal.
#### **Description**
This ARM assembly program handles UART communication by receiving data, storing it in a buffer, and transmitting it back. It initializes hardware, checks for errors, and processes incoming bytes until the buffer is full or a newline is received. The stored data is then transmitted character by character, followed by a buffer reset. A delay function using Timer 2 ensures proper timing.

</details>

<details>
<summary><strong>Task 3E</strong></summary>

#### **Usage**
You must first connect the two microcontrollers using 3 female to female jumper cables. One cable must connect the grounds (GND) between both boards, one must connect PA2 on the first board to PA3 on the second, with the final cable connecting PA3 on the first board, to PA2 on the second. The pin-out diagram for the STM32F3 Discovery Board can be seen below

  <img src="images/stm32f3-discovery-pinout.png" alt="STM32F4 Discovery Pinout" width="600"/>

  The task contains two seperate folders, TX, for recieving a string from the serial input, and transmitting to the second microcontroller, and RX, for recieving the string from the first microcontroller. You will need two microcontrollers, with one running the RX code and one running TX code. Please see the respective usage details for both below

Next, open CuteCom (Mac) or PuTTY (Windows) and connect to the USB port you have connected to the microcontroller, as well as choosing the appropriate baud rate (115200 in this case). Then, debug `assembly_tx.s` and run the code by pressing resume. Ensure the RX code is also running on the other microcontroller/ computer and is ready to receive. A string can then be sent into Cutecom/PuTTy using the computer running `assembly_tx.s`.

#### **Description**

  <details>
    <summary><strong>Receive 📥</strong></summary>

First we initialise all required hardware components. The code initialises USART2 to recieve, looping in loop_forever until there is a byte to recieve. Once all bytes have been received and stored into the buffer space, checking for newline characters, the transmittion functions are called. Over USART1, tx_uart continuously loads all received bytes into the transmission buffer until the length of string received is equal to the length of string transmitted. This will display the received string onto Cutecom/PuTTy. Once all bytes are transmitted, the buffer space to store the received string is cleared, and returns to continuously check for incoming bytes.

A delay is implemented to ensure smooth transmittion over USART1.

  </details>

  <details>
    <summary><strong>Transmit 📤</strong></summary>

First we initialise all required hardware components. The code initialises USART1 to recieve, looping in loop_forever until there is a byte to recieve. Once all bytes have been received and stored into the buffer space, checking for newline characters, the transmittion functions are called. Over USART2, tx_uart continuously loads all received bytes into the transmission buffer until the length of string received is equal to the length of string transmitted. This will send the message to the second microcontoller to receive. Once all bytes are transmitted, the buffer space to store the received string is cleared, and returns to continuously check for incoming bytes.

A delay is implemented to ensure smooth transmittion over USART2.

  </details>

</details>



</details>

---

<details>
<summary><strong>Exercise 4 - Hardware Timers ⏳</strong></summary>

<details>
<summary><strong>Task 4A</strong></summary>

#### **Usage**
Line 39 loads the appropriate delay time into the program in microseconds:
```assembly
LDR R1, =1000000             @ load 1s in
```

#### **Description**
The program's function is to count a delay on timer 2, oscillating an LED as a visual indicator of a delay. To implement this, the timer was initialised and enabled, as was the discovery board to begin the LED in the HIGH state. Given the clock is 8Mhz, setting the prescaler to 7 will divide the tick rate by 8 (7+1), effectively creating a 1Mhz delay. In the delay_wait function, the timer counter is compared to the selected load time. If the counter has exceeded the time period, its branched back to the blink loop, swapping the LED state. If not, then the delay loop is repeated. This carries on indefinitely.

</details>

<details>
<summary><strong>Task 4B</strong></summary>

#### **Usage**
The program parameters can be changed by altering two number, the number of cycle counts, and the duration of a cycle.
```assembly
CMP R6, #100 				 @ check if 1s passed

LDR R1, =10000             @ load 1s in
```

#### **Description**
The program's purpose is to create a pseudo 1s timer by counting 10,000 iterations of a 0.1ms timer. The LED starts in the HIGH state and toggles approximately every 10 ms. The prescaler is set to 7, dividing the 8 MHz clock by 8 (7 + 1), resulting in a 1 MHz timer tick rate. The delay_wait function repeatedly checks the counter until it reaches 10000, corresponding to 10 ms.

Each time the delay finishes, the LED is toggled using an XOR (EOR), flipping it between ON and OFF. The counter tracks how many times the delay function has completed. After 100 ticks (about 1 second), the LED is turned off permanently.
For the STM32F3Discovery board with an 8MHz timer, we select appropriate prescaler values for different delay periods:
For a 1 microsecond delay, we use a prescaler of 7 (divide by 8), resulting in a 1 MHz timer tick rate where each tick equals 1 microsecond. This fits within the 16-bit prescaler register.

For a 1 second delay, we use a prescaler of 7999 (divide by 8000), giving a 1 kHz timer tick rate. Setting the counter to 1000 provides a 1-second delay, with both prescaler and counter values fitting within 16-bit registers.

For a 1 hour delay, we implement a multi-stage approach (avoiding register limitations): using a prescaler of 7999 for a 1 kHz tick rate, a counter to count to 60000 ticks (60 seconds), with an additional software counter for 60 iterations (totalling 60 minutes).

To demonstrate a delay period of 0.1 ms, we use a prescaler of 7 (creating a 1 MHz timer frequency) and a counter value of 100. Verify this by counting 10,000 iterations of this 0.1 ms delay, which approximates 1 second total. The LED state toggles every 100 delays (10 ms) using a bit-wise XOR operation, efficiently implemented on the ARM Cortex-M4 processor. All counter values fit within their respective registers, ensuring proper operation on the STM32F3 hardware.
</details>

<details>
<summary><strong>Task 4C</strong></summary>

#### **Usage**
Line 33 sets the timer’s Auto-Reload Register to define a 1-second delay:
```assembly
LDR R1, =999999              @ set ARR for 1s delay
```

#### **Description**
This program toggles an LED connected to GPIOE using Timer 2 for precise 1-second intervals. The 8 MHz system clock is divided by (7 + 1) via the prescaler, producing a 1 MHz timer clock. Setting the ARR to 999999 makes the timer count up to this value, generating a 1-second delay.

The delay_wait function checks the update flag in TIM_SR. Once set, it clears the flag and returns to continue the LED toggling. The use of auto-reload ensures consistent timing without manually resetting the counter each cycle.

</details>

</details>

---

<details>
  <summary><strong>Exercise 5 - Integration 🔄</strong></summary>

  #### **Description**
  This final exercise combines aspects of each of the previous sections into a final integration exercise between two separate microcontrollers. 
  
TX:
When run, the code will take in a message from a serial input on the first microcontroller over USART 1. It then checks if the code is a palindrome. If it is a palindrome, it will turn on the green LED's, encode the message as a caesar cipher, and then transmit the encoded message to the second board via USART 2. If the string is not a palindrome, it will turn on the red LED's and transmit the string without encoding it.

RX:
The second microcontroller will then receive the string, also over USART 2, before checking it is a palindrome, since a palindrome encoded with a caesar cipher, is still a palindrome. If it is a palindrome, the code will begin to decode the message. If it is not a palindrome, the message will not be decoded. Both of these branches will then count the number of vowels and consonants in the string, before transmitting the message over USART1 onto the Cutecom/PuTTY display. Then displaying this number in binary on the LED's, with the NW LED representing the least significant bit, and increasing anti clockwise from there. It was oscillate every 500ms between showing the number of vowels and the number of consonants. After repeating this five times the microcontroller will loop back to prepare to receive another string.

For detailed explanations of how each of these steps work, please see previous task descriptions, or the usage drop downs below for TX and RX respectively.

  #### **Usage**
You must first connect the two microcontrollers using 3 female to female jumper cables. One cable must connect the grounds (GND) between both boards, one must connect PA2 on the first board to PA3 on the second, with the final cable connecting PA3 on the first board, to PA2 on the second. The pin-out diagram for the STM32F3 Discovery Board can be seen below

  <img src="images/stm32f3-discovery-pinout.png" alt="STM32F4 Discovery Pinout" width="600"/>

  The task contains two seperate folders, TX, for recieving a string from the serial input, and transmitting to the second microcontroller, and RX, for recieving the string from the first microcontroller. You will need two microcontrollers, with one running the RX code and one running TX code. Please see the respective usage details for both below:

  

  <details>
    <summary><strong>Transmit 📤</strong></summary>

#### **Usage**
1. To run the transmit code ensure you have completed the steps from above.

2. Next, open CuteCom (Mac) or PuTTY (Windows) and connect to the USB port you have connected to the microcontroller, as well as choosing the appropriate baud rate (115200 in this case). Then, debug `assembly_tx.s` and run the code by pressing resume. Ensure the RX code is also running on the other microcontroller/ computer and is ready to receive.


You can change Caesar cipher offset by altering the code on line 9 in ```assembly_tx.s``` to any number. Note that if the shift value is set to zero, the Caesar cipher will have no affect on the characters.  
```assembly
shift_value:  .word 10       @ Shift index to encode Caesar cipher
```

  </details>

  
  <details>
    <summary><strong>Receive 📥</strong></summary>
	  
#### **Usage**
1. To run the receive code ensure you have completed the steps from above.

2. Ensure the TX code is also running on the other microcontroller/ computer and is ready to send. Then, debug `assembly_rx.s` and run the code by pressing resume. It is now ready to receive. Once a message has been sent from the first board you will see the relevant LED's turn on, and the transmitted string at the address stored in register R6.

  </details>



</details>

---


## Testing and Troubleshooting 🧪
### Project Setup ⚙️
1. Move all files from each folder in this project into your STM32CubeIDE workspace.
2. Open STM32CubeIDE and import the project files as necessary.
3. Build the project and ensure there are no errors.

### Special Requirements for Exercise 3E and Integration 📃
- To complete **Exercise 3E** and the **Integration task**, you must have **two STM32F3Discovery boards** connected via serial communication.
- Ensure proper connections are made between the boards, and the correct serial ports are selected in your serial monitor tool.
### Debugging 🐞
- To debug your program in STM32CubeIDE:
  1. Click on **Debug** to start the debugging process.
  2. Once debugging starts, click **Resume** to run the program.
  3. Transmit your data via serial communication using your chosen serial monitor tool.
  4. Click **Pause** in STM32CubeIDE to inspect what was received.


- Make sure all dependencies are installed and properly configured.
- If the IDE does not detect the STM32F3Discovery board, try restarting your IDE or reconnecting the board.
- If using a MAC, the dongle connectors can be temperamental. Try unplugging and retrying
- Ensure serial connections are properly established between the boards if working on Exercise 3E and Integration.

