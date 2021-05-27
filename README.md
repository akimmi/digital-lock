# digital-lock
Youtube link:
https://youtu.be/dIIMmNJnILM 

Behavior Description:
This device is a digital lock that consists of an LCD, MSP432 and a keypad. The digital lock will power into a lock state then the LCD displays “LOCKED” and “ENTER KEY:” to prompt the user to input a password. This device waits for a user to input 4 characters on the attached keypad, and then checks that input against a predetermined key. If the user’s input is correct, the LCD displays the word “Unlocked” for 2 seconds and then resets the device, as if it had just been booted up for the first time. If the user’s input does not match the stored key then the device will delete the user’s input and reset. The user’s input is displayed on the LCD after the phrase “Locked Enter Key” as they press each button. The star button on the keypad will automatically reset the device no matter where the user is in their input.

