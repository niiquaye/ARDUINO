A circuit designed to dim an LED with two buttons. 

Button_One augments the brightness of the LED via pulse width modulation. 
Each time Button_One is pressed the there is an analogWrite by increments of 10
until the number 1023 is reached. 

Button Two decreases the brightness of the LED via pulse width modulation. 
Each time Button_Two is pressed there is an analogWrite written to the already lit LED.
Button_Two reduces the current pulse width then writes to the LED the reduced pulse width.

