# ⚠️ Capacitor Game Crisis - Arduino Defuse Challenge (Simulation Only)

> **🚨 WARNING: FOR EDUCATIONAL SIMULATION PURPOSES ONLY**  
> Do **NOT** build or power this circuit in real life.  
> Misuse can result in **component damage**, **fire**, or **personal injury**.  
> This project is designed for use **only in simulation environments** (e.g., Tinkercad, Proteus).  
> You assume all responsibility if you ignore this warning.

---
# Capacitor Game Crisis - Arduino Defuse Challenge

This project is a simple time-based reaction game built using an Arduino UNO. Press one button to start a 30-second countdown "crisis". You must press the second button within the time limit to "defuse" the situation. Failure results in a simulated "explosion" triggered via a relay.

## Gameplay

1.  **Power On:** Apply power to the circuit. The **Green LED** should light up, indicating the system is stable.
2.  **Start Crisis:** Press the **Start Button** (connected to pin D9).
    *   The **Red LED** will turn ON.
    *   The **Green LED** will turn OFF.
    *   The **Buzzer** will start making noise.
    *   A 30-second countdown begins. You can monitor the remaining time via the Arduino Serial Monitor (set baud rate to 115200).
3.  **Defuse:** Press the **Defuse Button** (connected to pin D8) *before* the 30-second countdown finishes.
    *   If successful: The **Green LED** turns ON, the **Red LED** turns OFF, and the **Buzzer** stops. The game resets to the stable state. Congrats!
4.  **Failure (Boom!):** If you do *not* press the Defuse Button within 30 seconds:
    *   The countdown reaches zero.
    *   The message "Boooooooooom" is printed to the Serial Monitor.
    *   The **Relay** (connected to pin D10) is activated for 3 seconds, simulating the "explosion". (Connect your desired "explosion" effect - like a bigger light, motor, etc. - to the relay contacts).
    *   The buzzer stops after the 3-second delay. The Red LED remains ON until the system is potentially reset.

## Hardware Requirements

*   Arduino UNO (or compatible board)
*   Push Button x 2
*   Red LED x 1
*   Green LED x 1
*   Piezo Buzzer x 1
*   5V Relay Module x 1
*   1k Ohm Resistor x 2 (for LEDs)
*   10k Ohm Resistor x 2 (Optional - for button pull-ups if not using `INPUT_PULLUP`, though the code uses internal pull-ups)
*   1uF Capacitor x 1 (For power smoothing as shown in schematic)
*   Power Source (e.g., 5V supply for Arduino, or separate battery pack `P1+/-` as per schematic if using external power regulation)
*   Jumper Wires
*   Breadboard (optional, for prototyping)

## Wiring / Connections

**Note:** The provided schematic diagram shows connections to Arduino pins A1-A5. However, the provided code uses digital pins D5-D10. **Follow the pin connections defined in the code (listed below) for the game to function correctly.**

*   **Start Button:**
    *   One leg to Arduino **Pin D9**
    *   Other leg to **GND**
*   **Defuse Button:**
    *   One leg to Arduino **Pin D8**
    *   Other leg to **GND**
*   **Red LED:**
    *   Anode (+) to 1k Resistor -> Arduino **Pin D7**
    *   Cathode (-) to **GND**
*   **Green LED:**
    *   Anode (+) to 1k Resistor -> Arduino **Pin D6**
    *   Cathode (-) to **GND**
*   **Buzzer:**
    *   Positive (+) leg to Arduino **Pin D5**
    *   Negative (-) leg to **GND**
*   **Relay Module:**
    *   `IN` (Signal) pin to Arduino **Pin D10**
    *   `VCC` pin to Arduino **5V**
    *   `GND` pin to Arduino **GND**
*   **Arduino Power:**
    *   Connect via USB or use the `VIN` / `5V` and `GND` pins according to your power source.



## Software Setup

1.  Install the [Arduino IDE](https://www.arduino.cc/en/software).
2.  Connect your Arduino UNO to your computer via USB.
3.  Open the Arduino IDE.
4.  Select the correct Board (Arduino UNO) and Port from the `Tools` menu.
5.  Copy the provided `.ino` sketch code into the IDE.
6.  Click the "Upload" button.
7.  (Optional) Open the Serial Monitor (`Tools -> Serial Monitor`) and set the baud rate to `115200` to see game messages and the countdown.

## Schematic Diagram
![Screenshot 2025-03-30 020053](https://github.com/user-attachments/assets/cf606908-afec-4064-82f8-e4bbba590074)
![image](https://github.com/user-attachments/assets/2468038d-50da-4505-a468-b7919da7c39a)


## Customization

*   **Countdown Time:** Change the value of the `countDown` constant in the code (line 7) to make the game easier or harder.
*   **Sounds/Feedback:** Modify the `tone()` frequency or add different patterns. Change LED behavior.
*   **Relay Action:** Connect different devices to the relay's output contacts (COM, NO/NC) to create various "explosion" effects (ensure the relay can handle the load).


