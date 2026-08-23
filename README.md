# Simple Motor Control Software

## 1. pins.h (The Settings File)

This file is only used to save the pin numbers. Instead of searching through hundreds of lines of code to change a pin number, you only open this file. If you decide to use a different board in the future, you just change the numbers here, and the rest of the code will work perfectly.

## 2. MD.h (The Header File)

Think of this file like a restaurant menu. It shows you what the code can do, but it does not show you how it is made. It tells the program that we have three classes: `L298N`, `CytronMD`, and `BTS7960`. Inside each class, it lists the available functions that you can use, like `begin()`, `drive(speed)`, and `stop()`.

## 3. task.cpp (The Logic File)

If the header file is the menu, this file is the kitchen. This is where the real work happens. It contains the actual C++ instructions. When you ask a motor to move forward, this file is the one that decides which pin goes HIGH, which pin goes LOW, and how to send the PWM speed signal. It also contains safety rules, like making sure the speed number never goes higher than 255 or lower than -255.

## 4. task.ino (The Main Program)

This is the main file that runs everything. It connects all the files together. In this file, we create our motor objects, and inside the `loop()` function, we give them direct commands (like move forward, wait for 1 second, then stop). Because we hid all the complex code in the other files, this main file looks very clean and simple.
