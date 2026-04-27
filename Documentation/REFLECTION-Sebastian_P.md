### Changes:
- Did everything required in the lab.

- Separated "creature.h" into header and implementation files.

- Privatized all "Creature" class data fields, and added getters and setters for said data fields.

- added static "creatureCount" data field to keep track of the number of creature instances globally.

- changed default destructor to decrement "creatureCount" when a creature instance is deleted.

- Changed implementation of "battle" in arena.cpp to reflect changes in Creature class data field access.

- Added docstring definitions for both header declarations and implementations in creature.h/.cpp.

- Added constant ints, "MIN_DAMAGE" and "MAX_DAMAGE" to stay consistent with other validation methods.

- Commented out iostream include in "sumo_sally.cpp" which was only needed for testing.

- Added a static member "creatureCount" that tracks how many Creature objects currently exist globaly.

- I added a type system which allows for possible implimentation for damage bonuses and advantages to make battles more strategic and interesting.
### Reasoning:
- Wanted implementation of the Creature class to be abstracted from user.

- Docstring definitions help the user to understand how to use the methods in the header, but not necessarily how they work.

- Docstring definitions in the implementation help explain specific details that are more in depth and aren't relevant to the user.

- Did not impliment a setter method for creature "name", wanted to avoid discrepancies with implemented stats and intended behavior conflicting with an unintended change in the creatures name. keeps people from changing the opponents name to their own, thus causing the opponent to be "their" creature.

- I used const on functions like attack(), isAlive(), and getters because they don’t modify the object, which prevents accidental changes.