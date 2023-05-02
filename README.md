# mrmonkey420.github.io

## [Github](https://github.com/MrMonkey420/mrmonkey420.github.io)

### Sprite Sorting and Camera Culling

Hi, my name is Marc Escandell and this is an introduction to Sprite Sorting and Camera Culling methods

### Introduction

2D video games employ a rendering technique based on sprites, which involves creating small two-dimensional images that are layered on the screen to form the complete game image. As more objects and characters are added to the game, the number of sprites increases, which can slow down game performance and affect the user experience.

To address this issue, optimization methods such as Sprite Sorting and Camera Culling have been developed to allow game developers to improve performance and enhance the user experience.

### A bit of context to both methods

The use of Sprite Sorting and Camera Culling methods in 2D games dates back to the early days of video games, when technology wasn't so powerfull and game developers had to invent some tricks like these in order to the game to work properly. Game developers have employed these techniques for decades to improve game performance and ensure a smooth gaming experience.

As technology has advanced, so have these methods. Game developers have created more sophisticated algorithms to determine which objects and characters should be rendered at any given time. Additionally, optimization techniques have also been applied to 3D games to enhance performance on complex screens.

In summary, Sprite Sorting and Camera Culling are essential techniques that have been utilized in 2D games for decades. As technology has progressed, these methods have evolved, enabling game developers to create more sophisticated and seamless gaming experiences.

### ¿What does these methods do?

**Sprite Sorting:**

Sprite Sorting is a technique used to simulate 3D environments in a 2D world. It can also be used to reduce the number of sprites that need to be drawn on the screen at any given time, decreasing the number of rendered sprites and improving game performance.

In simple terms, Sprite Sorting arranges the sprites based on their position on the screen. Sprites that are closer to the camera are drawn first, while sprites that are farther away are drawn last. This way, sprites that are hidden behind other objects are not rendered, reducing the load on the GPU and increasing rendering speed.

Sprite Sorting is commonly used in games with many on-screen sprites, such as platformers and fighting games, where there are numerous constantly moving characters and objects. By applying Sprite Sorting, developers can enhance game performance and ensure players enjoy a smooth and uninterrupted gaming experience.

![image](https://user-images.githubusercontent.com/99950510/235758795-b440661b-5778-4560-aeac-48f0aea627c7.png)

**Camera Culling:**

Camera Culling is another optimization technique used in 2D games to improve game performance. In a 2D game, the camera acts as the player's viewpoint and determines which objects and characters are displayed on the screen.

Camera Culling reduces the number of objects and characters that need to be drawn on the screen. The technique divides the screen into sections and calculates which objects and characters are within the current camera section. Only the objects and characters within the current section are drawn, reducing the GPU load and increasing rendering speed.

Camera Culling is typically used in games where the camera is constantly moving, such as adventure games and platformers. By implementing Camera Culling, developers can ensure that the game's performance is not affected by the number of objects and characters displayed on the screen.

![image](https://user-images.githubusercontent.com/99950510/235759293-e6274fff-7ff1-4970-bcfa-39caa40761b2.png)


### Examples of games that use Sprite Sorting and Camera Culling

**Super Mario Bros**

Super Mario Bros. is an iconic platforming game that employs both methods to improve game performance. Sprite Sorting is used to determine which objects and characters are drawn in the foreground and which are drawn in the background. Additionally, Camera Culling is utilized to reduce the number of objects and characters displayed on the screen at any given time.

**The Binding of Isaac**

The Binding of Isaac is a rogue-like game that in some situations has plenty of enemies and bullets moving arround at the same time in the same space. It is a more recent game, but that doesn't mean it uses some of this methods, specially sprite sorting. 

**Donkey Kong Country**

Donkey Kong Country is another classic platforming game that utilizes both methods to improve game performance. 

## How to implement both methods

### Sprite Sorting

First, we need to know that if we draw an entity before another, the second one will always pass behind the first.

In order, these are the steps we must follow: 

1. Create a data structure for each sprite that includes its position (x, y) and its depth (z). This depth will determine the order in which the sprites are drawn on      the screen.

2. Store all sprites in a list or vector.

3. Sort the list of sprites based on their depth, so that sprites with a greater depth are drawn after sprites with a lesser depth.

4. Draw the sprites in the order they appear in the list. This ensures that the deepest sprites are drawn behind the sprites closest to the player.

**Pivot point:** 

There are other ways to sort sprites, and depending on the situation one would be better than others. 

If one entity wants to move around of a column, for example, their Z-order is in constant change and our code should solve it. Here is one more way to do it:

We can use what its called a pivot point: a point situated in the spot where the entity is supposed to touch the ground (at the same height than their feet) that we can use to compare better dynamic entities. We will compare their Y-axis because, in general in 2D games, the more upwards an entity is situated, further away from the player in Z-axis it is.

I made some code that could help you understand it more [here](https://github.com/MrMonkey420/mrmonkey420.github.io)

### Camera Culling

In essence, what we are gona do is set the camera bounds and detect if any entity is inside of it. If an entity that exists in the virtual world is not situated in the camera bounds, also called “frustum”, it wont render and will free some memory to better optimization.

1. Determine the camera's view frustum: In a 2D game, the camera's view frustum is essentially a rectangle that represents the portion of the game world that's visible    on the screen. You can calculate the view frustum by using the camera's position and size, as well as the screen size.

2. Cull objects outside the frustum: Once you have the view frustum, you can test each object in the scene to see if it's within the frustum. You can do this by          testing the object's bounding box or bounding circle against the frustum. If the object is outside the frustum, you don't need to render it.

3. Render visible objects: Once you've culled objects outside the view frustum, you can then render the visible objects.

There are more ways to implement this idea, like fractionary culling, but we are gonna focus in the standard one.

To see some code about Camera Culling visit [this page](https://github.com/MrMonkey420/mrmonkey420.github.io)


### Bibliography

If you want, check these websites and videos that helped me understand better these methods:

**Sprite Sorting:**

- [Advanced Sprite Sorting tutorial - Scott Steffes (YouTube)](https://www.youtube.com/watch?v=yRZlVrinw9I)
- [A discourse made by the libsd community about sprite arrays](https://discourse.libsdl.org/t/z-order/16357/11)
- [A github website made by ShaunLebron explaining how does Sprite Sorting work on isometric environments](https://shaunlebron.github.io/IsometricBlocks/)

**Camera Culling:**

- [Advanced C++/Graphics Tutorial 31: Camera Culling 2D! - MakingGamesWithBen (YouTube)](https://www.youtube.com/watch?v=zCaurIC49I4)
