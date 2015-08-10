Ascii Roguelike - Toughguy Warehouse
========
UKY CS216 Programming Assignment
## To run:
1. Clone the repo. Because of lncurses dependency, must be run in linux environment
2. type 'make game' to make the exe, and './game' to run.
 
---
### How to Play:

**Movement**
'''
    [8]			    Up
[4]     [6]	       Left    Right
    [2]			   Down
'''
**Controls**
'''
[5] 		  Pick-up Items/Go up/down stairs(if unlocked)

Manage Inventory: [9] or [d] Cycles between		Weapons -> Armors -> Consumables
		  [7] or [a] Cycles between		Equipped Weapons/Armor and currently usable consumable,
							depending on which one you have selected using [9].
							The Weapon/Armor that is displaying is the one that is equipped.
	          [0] or [s] Use/Sell			Sells Weapon/Armor or Uses Item, depending on selection via [9] and 								[7]

Quit Game	  [q]
'''
**Item uses**
'''
	The Sauce	 -gives 15 * player level health
	Energy drink 	 -increase chain by 2 and resets number of turns before losing chain
	Stairwell Key	 -unlocks next floor
	Some Shells  	 -shoot shotty, after using you will be asked to pick a direction to shoot
'''
---
**Hints**
		*The last bad guy on each floor will drop a key[^]. You have to select that item in your inventory
		and then press [0] to use it while standing on the stairs up [>] tile.
		*You can build up a chain which increases damage dealt by killing bad guys in succession 
		within a set number of turns. You get more turns to build a chain as you gain levels.
		*The log displays the 4 most recent events with the newest on top. New events are denoted with "->"
		*You'll get the shotty on floor 4 after you kill all the thugs, a path will open up to the item,
		and the key to the exit is underneath the shotty.
		*You have to use the shotty to kill the boss on floor 8, after he dies, the path will open up to
		the exit/endgame.
		*!!! If you want to go straight to the boss enter GOTOBOSS when choosing your name. !!! 
		

