#ifndef LP_H_
#define LP_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>

class LP
{
public:
    LP();
    ~LP();
    //Drawing Circles
    static int SetCircle(int x, int y, int radius, sf::Color color);
    static void DrawCircle(int key);
    static void DrawCircle(int x, int y, int radius, sf::Color color, int key);
    //Drawing Rectangles
    static int SetRectangle(int x, int y, int width, int height, sf::Color color);
    static void DrawRectangle(int key);
    static void DrawRectangle(int x, int y, int key);
    static void DrawRectangle(float x, float y, int key);
    static void DrawRectangle(int x, int y, int width, int height, sf::Color color, int key);
    static void DrawRectangle(float x, float y, int width, int height, sf::Color color, int key);
    //Drawing Sprites
    static int SetTexture(std::string filePath, int width, int height);
    static void SetTexture(const int key, const std::string& filePath, int width, int height);
    static int SetSprite(int textureKey);
    static int SetSprite(int x, int y, int textureKey);
    static int SetSprite(int x, int y, int cellWidth, int cellHeight, int cellNum, int textureKey);
    static std::vector<int> SetSprite(int cellWidth, int cellHeight, int numOfColumns, int numOfRows, int textureKey);
    static void DrawSprite(int x, int y, bool flip, int key);
    static void DrawSprite(float x, float y, bool flip, int key);
    static void DrawSprite(float x, float y, bool flip, float scaleX, float scaleY, int key);
    static void DrawSprite(int key);
    static void SetSpriteColor(int key, int red, int green, int blue, int alpha);
    static void SetSpriteRotation(int key, float angle);
    //Drawing Text
    static void SetFont(std::string filePath);
    static int SetText(std::string text, int x, int y, int textSize, sf::Color color);
    static void SetTextColor(sf::Color color, int key);
    static void DrawText(int key);
    static void DrawText(std::string text, int key);
    static void DrawText(float scaleX, float scaleY, int key);
    //Draw
    static void Draw(sf::RenderWindow *window);
    //Delete
    static void DeleteCircle(int key);
    static void DeleteRectangle(int key);
    static void DeleteTexture(int key);
    static void DeleteSprite(int key);
    static void DeleteText(int key);
    static void DeleteAll();

private:
    static int key;
    static std::queue<int> thingsToDraw;

    static std::map<int, sf::CircleShape> circleMap;
    static std::map<int, sf::RectangleShape> rectangleMap;
    static std::map<int, sf::Texture> textureMap;
    static std::map<int, sf::Sprite> spriteMap;
    static sf::Font font;
    static std::map<int, sf::Text> textMap;
};

#endif