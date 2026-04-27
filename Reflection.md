# Reflection

1. **What changes did you make?**
   - Made the creature's stats (`name`, `health`, `damage`) private so nothing outside the class can mess with them directly.
   - Added getter methods (`getName()`, `getHealth()`, etc.) to let others read the stats safely.
   - Used an initializer list in the constructor to set up stats more efficiently.
   - Added a `takeDamage()` method to handle damage consistently.
   - Made `isAlive()` const so it doesn't change anything.
   - Added `creatureCount` to count how many creatures are made.
   - Added a `type` field (like "Humanoid" or "Beast") to categorize creatures.
   - Updated the battle code to use the getter methods instead of accessing stats directly.

2. **How did you improve encapsulation?**
   - Stats are now locked away as private data. External code can't accidentally change them. Instead, it has to use the getter methods, which keeps the data safe and prevents mistakes.

3. **Where did you use const and why?**
   - Getter methods are const because they only read data, they don't change anything.
   - `isAlive()` is const for the same reason.
   - Validation methods take const references to make sure they don't accidentally modify creatures during checking.

4. **What does your static member track?**
   - `creatureCount` keeps a running total of how many creatures have been created. Every time you make a new creature, it goes up by one.

5. **What enhancement did you add and why?**
   - Added a `type` field so creatures can be labeled as different kinds (e.g., "Humanoid", "Beast"). This lets us organize creatures better and makes it easy to add special rules for different types later.