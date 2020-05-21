# Bomberman
 Clone of bomberman game in unreal engine
 
 # Instructions
To get you into UE4 we would like you to make a small Bomberman clone. 

We'll do this as a 2 week project to start with.

We want you to base it off the classic Bomberman title, see the following:

https://www.youtube.com/watch?v=x8naOun2yXg (You don't have to watch the whole thing)

https://strategywiki.org/wiki/Bomberman/How_to_play

The exact enemies and powerups are not really that important,
you can take some artistic freedom with the choices here. Or make up your own if you want.

Programmer art is enough for this clone. It does not need to look pretty, and you don't need to support any sound or music.

You should use the newest version of UE4 available through the Epic Games Launcher. Which should be 4.24.

We do however have a few gameplay requirements that your clone should meet,
so that you dig into the various parts of UE4 we're certain you will have to deal with here.

For the record it is fine to experiment and prototype with Blueprints, but we're going to be discouraging overuse of Blueprints on new projects. This is for maintainability, performance and workflow (allowing two programmers to work on the same area of the code for example). So I would suggest implementing your character in C++ for example at the very least. (You can prototype it in Blueprints if you wish). (Edit: You should heavily prefer C++ over Blueprints. But as said, you can prototype a bit in Blueprints if you feel like it.)

The game should have:

Make the game in 3D. UE4 isn't great at 2D, and we're making 3D games anyway. So just make it in 3D, don't try looking for how to do 2D in UE4.

Bomberman map supporting multiple variations of the destructible walls layout. It's up to you if these should be a set of fixed walls variations or randomized.

Goal: Get an understanding of unreal maps or "Levels" as they are called.
Implementation tips: Controlling the map layout can be done through the Level Blueprint or through the GameMode class. 


Bomberman bomb, obviously!

Goal: Learning collision system. And to actually have some gameplay.


Have a set of powerups that alter the game, like classic bomberman.

Goal: Get familiar with Actors and collision system and collision events. I would also encourage getting familiar with UE4 Interfaces here.


Have some basic enemies.

Goal: Get familiar with AI system in UE4.


Support two-player online multiplayer, focusing on the "Dedicated Server" option. This can be coop or versus. If you also make it work with a "Listen Server" option, that is a nice bonus.

Goal: Get familiar with the UE4 networking system. Both Property Replication and RPCs(Remote Procedure Calls).


HUD/UI to show score/other game info.

Goal: Get a basic understanding of UI in UE4.


Feel free to experiment into any other aspect of UE4 you discover on the way, but make sure to cover these 7 requirements.
