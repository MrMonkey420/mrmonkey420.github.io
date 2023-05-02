# mrmonkey420.github.io

## [Github](https://github.com/MrMonkey420/mrmonkey420.github.io)

### Sprite Sorting and Camera Culling

Hi, my name is Marc Escandell and this is an introduction to Sprite Sorting and Camera Culling methods

### Introduction

2D video games employ a rendering technique based on sprites, which involves creating small two-dimensional images that are layered on the screen to form the complete game image. As more objects and characters are added to the game, the number of sprites increases, which can slow down game performance and affect the user experience.

To address this issue, optimization methods such as Sprite Sorting and Camera Culling have been developed to allow game developers to improve performance and enhance the user experience.

### ¿What does these methods do?

**Sprite Sorting:**

Sprite Sorting is a technique used to simulate 3D environments in a 2D world. It can also be used to reduce the number of sprites that need to be drawn on the screen at any given time, decreasing the number of rendered sprites and improving game performance.

In simple terms, Sprite Sorting arranges the sprites based on their position on the screen. Sprites that are closer to the camera are drawn first, while sprites that are farther away are drawn last. This way, sprites that are hidden behind other objects are not rendered, reducing the load on the GPU and increasing rendering speed.

Sprite Sorting is commonly used in games with many on-screen sprites, such as platformers and fighting games, where there are numerous constantly moving characters and objects. By applying Sprite Sorting, developers can enhance game performance and ensure players enjoy a smooth and uninterrupted gaming experience.

**Camera Culling**

Camera Culling is another optimization technique used in 2D games to improve game performance. In a 2D game, the camera acts as the player's viewpoint and determines which objects and characters are displayed on the screen.

Camera Culling reduces the number of objects and characters that need to be drawn on the screen. The technique divides the screen into sections and calculates which objects and characters are within the current camera section. Only the objects and characters within the current section are drawn, reducing the GPU load and increasing rendering speed.

Camera Culling is typically used in games where the camera is constantly moving, such as adventure games and platformers. By implementing Camera Culling, developers can ensure that the game's performance is not affected by the number of objects and characters displayed on the screen.

### A bit of context to both methods

The use of Sprite Sorting and Camera Culling methods in 2D games dates back to the early days of video games, when technology wasn't so powerfull and game developers had to invent some tricks like these in order to the game to work properly. Game developers have employed these techniques for decades to improve game performance and ensure a smooth gaming experience.

As technology has advanced, so have these methods. Game developers have created more sophisticated algorithms to determine which objects and characters should be rendered at any given time. Additionally, optimization techniques have also been applied to 3D games to enhance performance on complex screens.

In summary, Sprite Sorting and Camera Culling are essential techniques that have been utilized in 2D games for decades. As technology has progressed, these methods have evolved, enabling game developers to create more sophisticated and seamless gaming experiences.

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
