# ARM7-LPC2138-LPC2148-UART-Universal-Asynchronous-Receiver-Transmitter

Overview

UART is used for serial communication between microcontrollers, PCs, or other peripherals.

LPC2148 has UART0 and UART1, both supporting:

5–8 data bits

1–2 stop bits

Parity (even, odd, none)

Common signals:

TXD → Transmit data

RXD → Receive data

Pins for LPC2148:

UART	TXD	RXD
UART0	P0.0	P0.1
UART1	P0.8	P0.9
2. UART Registers
Register	Purpose
U0LCR / U1LCR	Line control: word length, stop bits, parity
U0DLL / U0DLM	Divisor Latch for baud rate
U0FCR / U1FCR	FIFO Control Register
U0LSR / U1LSR	Line Status Register (data ready, THR empty)
U0RBR / U0THR	Receiver buffer / Transmit holding register
U0IER / U1IER	Interrupt enable register
