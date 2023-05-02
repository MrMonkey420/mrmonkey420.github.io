#include <SDL2/SDL.h>
#include <vector>
#include "Textures.h"
#include "Render.h"

//Data struct to represent every sprite
struct Sprite
{
    SDL_Texture* texture;
    SDL_Rect rect;
    int depth;
    iPoint pivot;
};

// Comparison function based on sprite depth
bool SpriteDepthComparator(Sprite a, Sprite b)
{
    return a.depth < b.depth;
}

// Comparison function based on pivot position in Y-axis
bool SpriteDepthComparatorByPivot(Sprite a, Sprite b)
{
    return a.pivot.y > b.pivot.y;
}


int main()
{
    // Load sprite texture
    const char* spriteTexPath = parameters.attribute(“texturepath”).as_string();
    SDL_Texture* spriteTexture = app->tex->Load(spriteTexPath);

    // Create an array of sprites 
    std::vector<Sprite> sprites;
    Sprite sprite1 = { spriteTexture, { 100, 100, 32, 32 }, 1, { entity.pos.x - 5, entity.pos.y - 10 } };
    Sprite sprite2 = { spriteTexture, { 200, 200, 32, 32 }, 2, { entity.pos.x - 5, entity.pos.y - 10 } };
    Sprite sprite3 = { spriteTexture, { 300, 300, 32, 32 }, 3, { entity.pos.x - 5, entity.pos.y - 10 } };
    sprites.push_back(sprite1);
    sprites.push_back(sprite2);
    sprites.push_back(sprite3);

    // Sort sprites by depth
    std::sort(sprites.begin(), sprites.end(), SpriteDepthComparator);

    // Sort sprites by pivot
    std::sort(sprites.begin(), sprites.end(), SpriteDepthComparatorByPivot);

    // Blit sprites in order
    for (int i = 0; i != 3; i++)
    {
        app->render->DrawTexture(sprites[i].texture);
    }

    return 0;
}
