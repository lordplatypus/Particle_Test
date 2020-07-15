#include "LP.h"
using namespace std;
using namespace sf;

int LP::key = -1; //creates keys to use in the below maps
queue<int> LP::thingsToDraw; //list of ints (keys) used to know what to draw
map<int, RectangleShape> LP::rectangleMap; //map of rectangles
map<int, CircleShape> LP::circleMap; //map of circles
map<int, Texture> LP::textureMap;
map<int, Sprite> LP::spriteMap;
Font LP::font;
map<int, Text> LP::textMap;

LP::LP(){}

LP::~LP(){}


//Drawing Circles
int LP::SetCircle(int x, int y, int radius, sf::Color color)
{//create a new circle and add it to the circle map, return the key
    key++; //generate new key
    CircleShape temp; //create circle that will be added to the map
    temp.setRadius(radius); //set radius
    temp.setPosition(x, y); //set position
    temp.setFillColor(color); //set color
    circleMap[key] = temp; //add circle to the map
    return key; //return the key to the newly created circle
}

void LP::DrawCircle(int key)
{//adds circle to the list of objects to draw, no changes to the circle need to be made
    thingsToDraw.push(key);
}

void LP::DrawCircle(int x, int y, int radius, sf::Color color, int key)
{//adds circle to the list of objects to draw, changes are made to the circle before it is added to the list
    circleMap[key].setPosition(x, y); //change position
    circleMap[key].setRadius(radius); //change radius
    circleMap[key].setFillColor(color); //change color
    thingsToDraw.push(key);
}


//Drawing Rectangles
int LP::SetRectangle(int x, int y, int width, int height, sf::Color color)
{
    key++;
    RectangleShape temp;
    temp.setSize(Vector2<float>(width, height));
    temp.setPosition(x, y);
    temp.setFillColor(color);
    rectangleMap[key] = temp;
    return key;
}

void LP::DrawRectangle(int key)
{
    thingsToDraw.push(key);
}

void LP::DrawRectangle(int x, int y, int key)
{
    rectangleMap[key].setPosition(x, y);
    thingsToDraw.push(key);
}

void LP::DrawRectangle(float x, float y, int key)
{
    rectangleMap[key].setPosition(x, y);
    thingsToDraw.push(key);
}

void LP::DrawRectangle(int x, int y, int width, int height, sf::Color color, int key)
{
    rectangleMap[key].setPosition(x, y);
    rectangleMap[key].setSize(Vector2f(width, height));
    rectangleMap[key].setFillColor(color);
    thingsToDraw.push(key);
}

void LP::DrawRectangle(float x, float y, int width, int height, sf::Color color, int key)
{
    rectangleMap[key].setPosition(x, y);
    rectangleMap[key].setSize(Vector2<float>(width, height));
    rectangleMap[key].setFillColor(color);
    thingsToDraw.push(key);
}


//Drawing Sprites
int LP::SetTexture(string filePath, int width, int height)
{
    key++;
    Texture temp;
    temp.loadFromFile(filePath, IntRect(0, 0, width, height));
    textureMap[key] = temp;
    return key;
}

void LP::SetTexture(const int key, const std::string& filePath, int width, int height)
{
    textureMap[key].loadFromFile(filePath, IntRect(0, 0, width, height));
}

int LP::SetSprite(int x, int y, int textureKey)
{
    key++;
    Sprite temp;
    temp.setTexture(textureMap[textureKey]);
    temp.setPosition(x, y);
    spriteMap[key] = temp;
    return key;
}

int LP::SetSprite(int x, int y, int cellWidth, int cellHeight, int cellNum, int textureKey)
{
    key++;
    Sprite temp;
    temp.setTexture(textureMap[textureKey]);
    Vector2u textureSize = textureMap[textureKey].getSize();
    temp.setTextureRect(IntRect(cellNum % (textureSize.x / cellWidth) * cellWidth, cellNum / (textureSize.x / cellWidth) * cellWidth, cellWidth, cellHeight));
    temp.setPosition(x, y);
    spriteMap[key] = temp;
    return key;
}

vector<int> LP::SetSprite(int cellWidth, int cellHeight, int numOfColumns, int numOfRows, int textureKey)
{
    vector<int> spriteArray;
    for (int i = 0; i < numOfRows; i++)
    {
        for (int j = 0; j < numOfColumns; j++)
        {
            key++;
            Sprite temp;
            temp.setTexture(textureMap[textureKey]);
            temp.setTextureRect(IntRect(cellWidth * j, cellHeight * i, cellWidth, cellHeight));
            spriteMap[key] = temp;
            spriteArray.push_back(key);
        }
    }
    return spriteArray;
}

void LP::DrawSprite(int x, int y, bool flip, int key)
{
    spriteMap[key].setPosition(x, y);
    if (flip) spriteMap[key].setScale(-1, 1);
    else spriteMap[key].setScale(1, 1);
    thingsToDraw.push(key);
}

void LP::DrawSprite(float x, float y, bool flip, int key)
{
    spriteMap[key].setPosition(x, y);
    if (flip) 
    {
        spriteMap[key].setScale(-1, 1);
        spriteMap[key].setOrigin(spriteMap[key].getLocalBounds().width, 0);
    }
    else 
    {
        spriteMap[key].setScale(1, 1);
        spriteMap[key].setOrigin(0, 0);
    }
    thingsToDraw.push(key);
}

void LP::DrawSprite(float x, float y, bool flip, float scaleX, float scaleY, int key)
{
    spriteMap[key].setPosition(x, y);
    if (flip) 
    {
        spriteMap[key].setScale(-scaleX, scaleY);
        spriteMap[key].setOrigin(spriteMap[key].getLocalBounds().width, 0);
    }
    else 
    {
        spriteMap[key].setScale(scaleX, scaleY);
        spriteMap[key].setOrigin(0, 0);
    }
    thingsToDraw.push(key);
}

void LP::DrawSprite(int key)
{
    thingsToDraw.push(key);
}

void LP::SetSpriteColor(int key, int red, int green, int blue, int alpha)
{
    spriteMap[key].setColor(Color(red, green, blue, alpha));
}

void LP::SetSpriteRotation(int key, float angle)
{
    //spriteMap[key].setOrigin(spriteMap[key].getLocalBounds().width / 2, spriteMap[key].getLocalBounds().height / 2);
    spriteMap[key].setRotation(angle);
    //spriteMap[key].setOrigin(0, 0);
}


//Drawing Text
void LP::SetFont(string filePath)
{
    font.loadFromFile(filePath);
}

int LP::SetText(string text, int x, int y, int textSize, sf::Color color)
{
    key++;
    Text temp;
    temp.setFont(font);
    temp.setCharacterSize(textSize);
    temp.setPosition(x, y);
    temp.setFillColor(color);
    temp.setString(text);
    textMap[key] = temp;
    return key;
}

void LP::SetTextColor(sf::Color color, int key)
{
    textMap[key].setFillColor(color);
}

void LP::DrawText(int key)
{
    thingsToDraw.push(key);
}

void LP::DrawText(string text, int key)
{
    textMap[key].setString(text);
    thingsToDraw.push(key);
}

void LP::DrawText(float scaleX, float scaleY, int key)
{
    textMap[key].setScale(scaleX, scaleY);
    thingsToDraw.push(key);
}


//Draw
void LP::Draw(RenderWindow *window)
{
    if(thingsToDraw.size() > 0)
    {//as long as there are things to draw, run the below code
        int numOfThingsToDraw = thingsToDraw.size(); //save the num of things to draw
        for (int i = 0; i < numOfThingsToDraw; i++)
        {
            if (circleMap.find(thingsToDraw.front()) != circleMap.end())
            {//if the circleMap contains the key draw the circle
                window->draw(circleMap[thingsToDraw.front()]);
            }
            else if (rectangleMap.find(thingsToDraw.front()) != rectangleMap.end())
            {//if the rectangleMap contains the key, draw the rectangle
                window->draw(rectangleMap[thingsToDraw.front()]);
            }
            else if (spriteMap.find(thingsToDraw.front()) != spriteMap.end())
            {
                window->draw(spriteMap[thingsToDraw.front()]);
            }
            else if (textMap.find(thingsToDraw.front()) != textMap.end())
            {
                window->draw(textMap[thingsToDraw.front()]);
            }
            thingsToDraw.pop(); //remove the key from the list
        }
    }
}


//Delete
void LP::DeleteCircle(int key)
{
    circleMap.erase(key);
}

void LP::DeleteRectangle(int key)
{
    rectangleMap.erase(key);
}

void LP::DeleteTexture(int key)
{
    textureMap.erase(key);
}

void LP::DeleteSprite(int key)
{
    spriteMap.erase(key);
}

void LP::DeleteText(int key)
{
    textMap.erase(key);
}

void LP::DeleteAll()
{
    circleMap.clear();
    rectangleMap.clear();
}