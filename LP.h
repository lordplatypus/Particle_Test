#ifndef LP_H_
#define LP_H_
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <queue>

class LP
{
public:
    LP();
    ~LP();
    //Drawing Circles(丸を描く)
    //Create new circle with a specified position and radius(前の設定した位置と半径を使って、新しい丸を作る)
    static int SetCircle(const sf::Vector2f position, const float radius);
    //Add the specified circle to the queue of things to draw
    static void DrawCircle(const int key);
    //Add the specified circle to the queue of things to draw and update its position
    static void DrawCircle(const int key, const sf::Vector2f position);
    //Change the circles color/alpha
    static void SetCircleColor(const int key, const int red, const int green, const int blue, const int alpha);
    //change the circles radius
    static void SetCircleRadius(const int key, const float radius);

    //Drawing Rectangles
    //Create a new Rectangle with a specified position, width, and height(前の設定した位置と長さと高さを使って、新しい四角形を作る)
    static int SetRectangle(const sf::Vector2f position, const float width, const float height);
    //Add the specified rectangle to the queue of things to draw
    static void DrawRectangle(const int key);
    //Add the specified rectangle to the queue of things to draw and update its position
    static void DrawRectangle(const int key, const sf::Vector2f position);
    //Change the rectangles color/alpha
    static void SetRectangleColor(const int key, const int red, const int green, const int blue, const int alpha);
    //change the rectangles width and height
    static void SetRectangleSize(const int key, const float width, const float height);

    //Drawing Sprites
    //Load in a texture and return a key (int)(テクスチャをロードする、intを返す)
    static int SetTexture(const std::string& filePath, int width, int height);
    //Load in a texture using a predetermined key (int)(前の設定したIDを使って、テクスチャをロードする)
    static void SetTexture(const int key, const std::string& filePath, int width, int height);
    //Create a new sprite using a specified texture(前の設定したテクスチャを使って、新しいスプライトを作る)
    static int SetSprite(const int textureKey);
    //Create a new sprite using a specified texture and position(前の設定したテクスチャと位置を使って、新しいスプライトを作る)
    static int SetSprite(const int textureKey, const sf::Vector2f position);
    //Create a new sprite using part of a specified texture and position
    static int SetSprite(const int textureKey, const sf::Vector2f position, const int cellWidth, const int cellHeight, const int cellID);
    //Create multiple sprites from one texture and return them as a vector
    static std::vector<int> SetSprite(const int textureKey, const int cellWidth, const int cellHeight, const int numOfColumns, const int numOfRows);
    //Add the specified sprite to the queue of things to draw
    static void DrawSprite(const int key);
    //Add the specified sprite to the queue of things to draw and update its position
    static void DrawSprite(const int key, sf::Vector2f position);
    //change the sprites color/alpha
    static void SetSpriteColor(const int key, const int red, const int green, const int blue, const int alpha);
    //Change the sprites angle
    static void SetSpriteRotation(const int key, const float angle);
    //Change the sprites origin
    static void SetSpriteOrigin(const int key, const sf::Vector2f newOrigin);
    //Center the sprites origin
    static void SetSpriteOriginCenter(const int key);
    //Change the sprites scale
    static void SetSpriteScale(const int key, const float scaleX, const float scaleY);
    //Mirror the sprite or not
    static void SetSpriteHorizontalFlip(const int key, const bool flip);

    //Drawing Text
    //Load in a text font(フォントをロードする)
    static void SetFont(const std::string& filePath);
    //Create new text with a specified position and text size(前の設定した位置とテキストサイズを使って、新しいスプライトを作る)
    static int SetText(const std::string& text, const sf::Vector2f position, int textSize);
    //Change the text color using predetermined colors(テキストの色を設定する)
    static void SetTextColor(const int key, const sf::Color color);
    //Change the text color/alpha(テキストの色とアルファを設定する)
    static void SetTextColor(const int key, const int red, const int green, const int blue, const int alpha);
    //Change the text origin(テキストの元を設定する)
    static void SetTextOrigin(const int key, const sf::Vector2f newOrigin);
    //Change the text origin to the center of the text(テキストの元をまなかに設定する)
    static void SetTextOriginCenter(const int key);
    //Change the text position
    static void SetTextPosition(const int key, const sf::Vector2f newPosition);
    //Change the text scale
    static void SetTextScale(const int key, const float scaleX, const float scaleY);
    //Add the specified text to the queue of thing to draw
    static void DrawText(const int key);
    //Add the specified text to the queue of thing to draw and update the text
    static void DrawText(const int key, const std::string& text);

    //Draw
    //Draw whatever is in the queue in the window
    static void Draw(sf::RenderWindow *window);

    //Delete
    //Delete a specific circle
    static void DeleteCircle(int key);
    //Delete a specific rectangle
    static void DeleteRectangle(int key);
    //Delete a specific texture
    static void DeleteTexture(int key);
    //Delete a specific sprite
    static void DeleteSprite(int key);
    //Delete specific text
    static void DeleteText(int key);
    //Delete everything (circle, rectangle, texture, sprite, and text)
    static void DeleteAll();

private:
    //Key used to look up objects within their maps
    static int key;
    //Queue of things to draw every frame
    static std::queue<int> thingsToDraw;

    static std::unordered_map<int, sf::CircleShape> circleMap;
    static std::unordered_map<int, sf::RectangleShape> rectangleMap;
    static std::unordered_map<int, sf::Texture> textureMap;
    static std::unordered_map<int, sf::Sprite> spriteMap;
    static sf::Font font;
    static std::unordered_map<int, sf::Text> textMap;
};

#endif