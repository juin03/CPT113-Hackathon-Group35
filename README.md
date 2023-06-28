# CPT113_Hackathon2_-Group35-
## "The Vanished Voyage"
## 1.0 Game Description
Unleash your courage in a thrilling race against time, as you delve into the enigmatic aftermath of an airplane crash. On a fateful Christmas eve, you were on your way home after a long year working abroad, eagerly anticipating the joyous reunion with your family. However, destiny had a different plan in store for you. Awaking amidst the forest with a throbbing pain in your head, the harsh reality sets in: your plane has crashed. Driven by an unwavering determination to reunite with your beloved family, you must navigate the treacherous terrain, face mysterious challenges, and discover the path to survival and escape.

![MAP](https://github.com/juin03/CPT113_Hackathon2_-Group35-/blob/6d8a58628042896d153173d8573e780590fc46be/Screenshot%201.png)

## 2.0 Game Feature
Gameplay Overview:
"The Vanished Voyage" is a game where players explore various areas, interact with events, and make choices to progress in the game. The game is played through a command-line interface, where players input commands to navigate, interact, and manage their character. The objective is to complete certain events and collect specific items to achieve the game's ultimate goal.

1. Immersive Descriptions and dynamic choices: Experience a richly described environment, events, and characters through vivid text descriptions, enhancing the immersion and sense of adventure. Player will face decision points throughout the game that have consequences, shaping the story and determining the character's fate.

2. Area Navigation:
The game world consists of different areas, each represented by a unique ID. Players start in the "EmptyGround" area and can choose their direction to move to neighboring areas. The available directions are North (N), South (S), East (E), and West (W). Players input the corresponding letter to select their desired direction. Invalid inputs are not accepted, and players are prompted to enter a valid direction.

3. Events:
Player can engage in interactive events and encounters as they explore the crash site, each with its own unique challenges, and outcomes. Each area has three events associated with it. Events are represented by objects of the `Event` structure and stored in the eventList. A random generator is used to randomly generate one of the three events that is already preset for that particular area. Each event may provide descriptions, hints, buffs, debuffs, or item rewards. Players can interact with the events and this will unlock hidden events and eventually affect the ending of the game.

4. Inventory:
Player has to collect and utilize various items and resources found throughout the game to overcome obstacles and unlock events.The game includes an inventory system to manage collected items. Items are represented by objects of the `Inventory` structure and stored in the inventoryList. The items are dropped when the player encounter certain events. Player need to utilise the item collected to unlock secret events. The storyline of the player is highly dependent on the items collected.

5. Health Management: Monitor your character's health (HP) throughout the game, making strategic decisions to avoid losing HP unnecessarily by strategically choosing the next direction of the journey.
   
6. Multiple Endings: The game offers multiple possible outcomes based on the choices made by the player, adding replay value and encouraging exploration.
   
7. Save and Load System: Enable players to save their progress at any point in the game and load it later, allowing for convenient gameplay sessions.


## 3.0 How to play the game.
1. Introduction:
   - Launch the game and start by selecting whether to start a new game or load a previous game process.

2. Character Creation:
   - Begin the game as your character awakens in the empty ground with 50 HP (health points).

3. Navigation:
   - You choose a direction to move from their current area to adjacent areas by typing the corresponding command, such as "North(n)", "South(s)", "East(e)",          and "West(w).
   - Each direction will lead you to different places within the crash site.

4. Exploration and Challenges:
   - As you move to different places, you will encounter mysterious events and challenges.
   - Read the descriptions carefully and make choices based on the available options.
   
5. Collecting Inventories:
   - Collect and add items to your inventory throughout the map.
   - Inventories may help you overcome obstacles or unlock new paths and events.

6. Health Management:
   - Pay attention to your HP as it indicates your character's health.
   - Make wise decisions to avoid losing HP unnecessarily, as it may impact your ability to survive and progress.

7. Escaping:
   - Your main objective is to find a way to escape from the forest.
   - Explore different places and unlock different ending based on the decision made throughout the journey.

8. Saving Progress:
   - Save your game progress after you quit to ensure you can resume from where you left off.

9. Game Over and Victory:
   - The game ends when you successfully escape from the forest or if your HP reaches zero, resulting in a game over.


## 4.0 How object-oriented concepts were used to develop the game.
The game was developed using object-oriented concepts to organize and structure the code effectively. The game utilizes various classes and structures to represent different entities and functionalities. 

1. Classes and Objects:
   - The code defines several classes such as `LinkedList`, `Player`, `Area`, `EmptyGround`, `PlaneWreck1`, `PlaneWreck2`, `River`, `Forest`, and `Village`.
   - Objects of these classes are created and utilized throughout the code, such as `eventList`, `inventoryList`, `ground`, `wreck1`, `wreck2`, `river`, `forest`, and `village`.

2. Encapsulation:
   - The code encapsulates related data and behavior within the classes. Access specifiers like `private` and `public` are used to control the accessibility of        class members.
   - For example, the `LinkedList` class encapsulates the linked list functionality.
   - Player class also shows encapsulation where mutator and accessor function are used to access the private members.

3. Inheritance:
   - The code demonstrates inheritance by defining derived classes that inherit from a base class.
   - Derived classes `EmptyGround`, `PlaneWreck1`, `PlaneWreck2`, `River`, `Forest`, and `Village` inherit from the base class `Area`.
   - For example, the area_ID is inherited and it acts as a checkpoint whenever player chooses to load the game.

4. Polymorphism:
   - The code exhibits polymorphism through function overriding.
   - Each derived class has a `choose()` function that overrides the base class's `choose()` function.  
   - The available direction that is not blocked in each area is different hence this overridden function provide different implementations based on the specific      behavior of each area.

5. Abstraction:
   - The code demonstrates abstraction by using classes to model real-world concepts and hiding the underlying implementation details.
   - Classes like `LinkedList`, `Player`, and `Area` provide abstractions for data structures, game entities, and game areas, respectively.

6. Templates:
   - The code utilizes templates to create a generic linked list data structure (`LinkedList`) that can work with different types of data (e.g., `Event` and         `Inventory`).
   - `Event` and `Inventory` are two separate structure that has their own variables.

Overall, the code effectively demonstrates the application of OOP concepts like classes, objects, encapsulation, inheritance, polymorphism, abstraction, templates, and object composition. These concepts promote modularity, reusability, and maintainability of the codebase, making it easier to understand and extend the functionality of the program.

## 5.0 How linked lists play a role in the game.
Linked list is used in the game. It plays a core role in the game which makes up the main structure of the game. It is essential to save and load the game progress as well.

A linked list template is created.
The LinkedList template class is designed to accommodate different data types and is instantiated for two specific types: Event and Inventory. The template class consists of a nested struct called ListNode, which represents each node in the linked list. Each node holds the data of the corresponding type and a pointer to the next node in the list.

The Event and Inventory structs define the structure of the data stored in the linked list nodes. Each area class (e.g., PlaneWreck1, River, etc.) contains a LinkedList<Event> and LinkedList<Inventory> to store the corresponding events and items for that area.

**Managing Events:**

The LinkedList<Event> specialization is used to manage events in the game. The appendNode() function allows the addition of new events to the linked list, and deleteEvent() enables the removal of events based on their event_ID. The outputEvent() function displays information about a specific event by matching its event_ID. Additionally, the eventExist() function checks if an event with a particular event_ID exists in the linked list.

**Managing Inventory:**

The LinkedList<Inventory> specialization is responsible for managing the player's inventory. The appendNode() function facilitates the addition of new items to the inventory, while deleteItem() allows the removal of items based on their item_ID. The outputItem() function displays the item_message of a specific item by matching its item_ID. Similarly, the itemExist() function checks if an item with a specific item_ID exists in the linked list.
The linked list implementation is provided through the LinkedList class template. It includes common operations such as appending nodes, deleting nodes based on event or item IDs, outputting specific nodes based on IDs, checking if certain events or items exist in the list, and traversing the inventory.

**Track, Save and Load Game Progress:**

LinkedList<Event> is created. In the game, the events for each area are pre-appended to the program before we start the game. For certain events that can only happen once, the event will be deleted after it happens by deleting the list node in the linkedlist. This will prevent the event from happening again while the program is still running. At the same time, the event_ID is written into a txt.file as well. When the program is terminated, restarted and player chooses to load previous game, the program will traverse and delete the list node for that particular event so that it wont happen again.

Similarly, LinkedList<Inventory> is created. When player obtain an item, the listnode for that particular item is appended into the linked list and will be shown when we traverse and print the inventory list. If the inventory already has the particular item, the event spawning this item will not happen again to avoid player from obtaining the same item repetitvely. For certain scenarios, the program will traverse the LinkedList<inventory> to check whether the player has the specific item to unlock hidden events. While the program is running, whenever the player obtain an item, the item_ID will be written into a txt file. When player load the game after the program is terminated, the inventory list will be traverse and the listnodes will be deleted based on the item_ID. The inventory of the player is updated to the state when the program is saved.

Below are the details explanation of how the linked list work in the game:
1. Dynamic Data Structure: In our game, the linked list data structure allows for dynamic addition and removal of events and inventory items. For example, when the player triggers a new event or acquires a new item, the corresponding nodes can be efficiently inserted into the linked list using the `appendItem` functions. Similarly, when events are resolved or items are discarded, the `deleteEvent` and `deleteItem` functions enable seamless removal from the linked list, dynamically adjusting the game state.

2. Sequential Access: The sequential access provided by linked lists ensures that events and inventory items are processed and displayed in the order they were added. For instance, when you traverse the inventory using the `traverseInventory` function, the linked list's sequential nature guarantees that items are iterated over in the order they were acquired, maintaining the inventory's chronological order. This allows for consistent and logical presentation of the player's progress.

3. Flexibility in Size: Linked lists offer flexibility in handling varying numbers of events and inventory items. Our game can dynamically accommodate different gameplay scenarios without the need for a fixed size. As the player progresses, events and inventory items can be added or removed from the linked list as required. This adaptability ensures that our game can handle a changing number of elements efficiently without constraints on predefined capacity.

4. Efficient Element Removal: The `deleteEvent` and `deleteItem` functions in our code demonstrate the efficient removal of specific events and inventory items based on their IDs. By traversing the linked list and manipulating pointers, these functions allow for swift removal of desired elements. This functionality is crucial for managing the player's progress and maintaining an up-to-date inventory, ensuring efficient memory utilization and streamlined gameplay.

5. Easy Traversal and Searching: The `traverseInventory`, `eventExist`, and `itemExist` functions exemplify the ease of traversing the linked list and searching for specific events or items. The `traverseInventory` function iterates over the linked list, enabling easy display of inventory items. Similarly, the `eventExist` and `itemExist` functions utilize linked list traversal to search for specific events or items based on their IDs, providing quick and efficient lookup capabilities for gameplay interactions.

6. Memory Efficiency: Linked lists utilize memory efficiently by dynamically allocating memory for each element as needed. In the game, this means that memory is optimally utilized, as nodes are allocated only when items are added to the linked list. This memory efficiency ensures that the game can handle large or small numbers of events and inventory items without unnecessary memory consumption, promoting a smooth and responsive gameplay experience.

## 6.0 Screenshots of the game.
1. When compiling the program, you will be presented with two choices: to either load your previous progress or start a new game. After making your selection, the program will display the game's map and provide you with the background story, as well as instruct you on what to do next.
![map](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/map.png)<br>

2. Throughout the game, there are **TWO BUFFS** that you may come across:<br>
a) Freshwater: This buff will increase your HP by 10 points. In this case, the original HP is 50.
![buff1-freshwater](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/water.png)<br>
b) Antibiotic: This buff will also increase your HP by 20 points. In this case, the original HP is 50.
![buff2-antibiotic](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/antibiotic.png)<br>

3. Throughout the game, there are **TWO DEBUFFS** that you may come across:<br>
a) Trap: This buff will decrease your HP by 10 points. In this case, the original HP is 50.
![debuff2-trap](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/trap.png)
b) Snake: This buff will decrease your HP by 20 points. In this case, the original HP is 70.
![debuff1-snake](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/snake.png)

4. In the game, there are **THREE ITEMS** that players can collect in their inventory:<br>
a) Axe
![axe](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/axe.png)<br>
b) Teddy
![teddy](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/teddy.png)<br>
c) Plank - ( requires the axe to obtain )
![plank](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/plank.png)<br>

5. **HINTS** can be obtained in the game to aid your progress.
![letter](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/letter.png)<br>

6. There are two **WINNING PATH** in the game<br>
a) Building a boat to escape via the river.
![win1-river](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/win-boat.png)<br>
b) Exchanging the teddy for a radio with the villager's children.
![win1-village](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/win-radio.png)

7. **GAME OVER** when HP reaches or falls below zero.
![gameOver](https://github.com/juin03/CPT113-Hackathon-Group35/blob/de2ef704b97d80be1c47b7807ec358d7e805610b/Screenshot/gameOver.png)

## 7.0 A link to the game demo video.
