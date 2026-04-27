###1.### What changes did you make?:
Refactored the code for data encapsulation and implementing other items as instructed(accessor methods, const member functions, constructor initializer lists, static members) with a change of my own being a simple inclusion of defense. Adjusted code to be compatible with changes to methods.
---
###2.### How did you improve encapsulation?:
The main way way I improved encapsulation is by privating items such name, health, attack, and defense and making them only accesible through getter methods in the public. Then recoding the subsequent code strucutres to prevent them from trying to access the private functions.
---
###3.### Where did you use const and why?:
I used the const in the getters so when a creature passes its traits to the constructor it won't leave behind its data behind when passed through the neccessary variables.
---
###4.### What does your static member track?:
I used static on creature count due to the nature it would a poor idea to immediatly throw it out or force the the system to keep counting how many creatures are in play.
---
###5.### What enhancement did you add and why?:
I added the enhancement of defense stat that subtracts from attack. If decided to be implemented I'd reccomend a cap of 5 due to how low the damage of the creatures are.
---