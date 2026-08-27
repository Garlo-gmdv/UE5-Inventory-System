\# Data access

* The inventory data is obtained via a cast inside the function "GetOwningPlayerPawn", this works because in this instance of the project the "BP\_ThirdPersonCharacter" is the only object using the inventory system. For more complex behaviours a cast to a base class (if possible) or an interface would be better to use because it offers more flexibility.

