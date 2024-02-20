#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

class myRectangleShape {
    sf::RectangleShape m_shape;
    float m_xvel;
    float m_yvel;
public:

    myRectangleShape(float vel,float yvel, sf::RectangleShape shape) :m_xvel(vel),m_yvel(yvel), m_shape(shape){

    }

    float getxVel() {
        return m_xvel;
    }

    float getyVel() {
        return m_yvel;
    }

    sf::RectangleShape getShape() {
        return m_shape;
    }

    void setPos(float x, float y) {
        m_shape.setPosition(x, y);
    }

    void setyVel(float yvel) {
        m_yvel = yvel;
    }

    void setxVel(float xvel) {
        m_xvel = xvel;
    }

};

class myCircleShape {
    sf::CircleShape m_shape;
    float m_xvel;
    float m_yvel;
public:

    myCircleShape(float vel, float yvel, sf::CircleShape shape) :m_xvel(vel), m_yvel(yvel), m_shape(shape) {

    }

    float getxVel() {
        return m_xvel;
    }

    float getyVel() {
        return m_yvel;
    }

    void setyVel(float yvel) {
        m_yvel = yvel;
    }

    sf::CircleShape getShape() {
        return m_shape;
    }

    void setPos(float x, float y) {
        m_shape.setPosition(x, y);
    }

    void setxVel(float xvel) {
        m_xvel = xvel;
    }


};

int main()
{

    std::ifstream fin("config.txt");

    int windowW;     
    int windowH;
    fin >> windowW;
    fin >> windowH;
    sf::RenderWindow window(sf::VideoMode(windowW, windowH), "My Window");

    std::vector<myRectangleShape> RectangleShapeList;
    std::vector<myCircleShape> CircleShapeList;

    std::string type;
    float shapeXPos;   
    float shapeYPos;
    int shapeRVal;   
    int shapeGVal; 
    int shapeBVal;  
    float shapeWidth;
    float shapeHeight;
    float radius;
    float xVelocity;
    float yVelocity;

    
    while (fin >> type) {
        if (type == "Rectangle") {
            fin >> shapeXPos;
            fin >> shapeYPos;
            fin >> shapeRVal;
            fin >> shapeGVal;
            fin >> shapeBVal;
            fin >> shapeWidth;
            fin >> shapeHeight;
            fin >> xVelocity;
            fin >> yVelocity;
            sf::Color shapeColor(shapeRVal, shapeGVal, shapeBVal);
            sf::RectangleShape aShape(sf::Vector2f(shapeWidth, shapeHeight));
            aShape.setPosition(shapeXPos, shapeYPos);
            aShape.setFillColor(shapeColor);

            myRectangleShape anShape(xVelocity,yVelocity,aShape);

          
       

            RectangleShapeList.push_back(anShape);
        }
        else if (type == "Circle") {
            fin >> shapeXPos;
            fin >> shapeYPos;
            fin >> shapeRVal;
            fin >> shapeGVal;
            fin >> shapeBVal;
            fin >> radius;
            fin >> xVelocity;
            fin >> yVelocity;

            sf::CircleShape aShape(radius);
            sf::Color shapeColor(shapeRVal, shapeGVal, shapeBVal);
            aShape.setPosition(shapeXPos, shapeYPos);
            aShape.setFillColor(shapeColor);

            myCircleShape anShape(xVelocity, yVelocity, aShape);

            CircleShapeList.push_back(anShape);
        }
        
  
        
    }


    while (window.isOpen()) {

        for (auto& r : RectangleShapeList) {
            r.setPos(r.getShape().getPosition().x, r.getShape().getPosition().y - r.getyVel());
            r.setPos(r.getShape().getPosition().x - r.getxVel(), r.getShape().getPosition().y);

            if (r.getShape().getPosition().y + r.getShape().getSize().y >= window.getSize().y) {
                r.setyVel(r.getyVel() * -1);
            }

            if (r.getShape().getPosition().y <= 0) {
                r.setyVel(r.getyVel() * -1);
            }

            if (r.getShape().getPosition().x + r.getShape().getSize().x >= window.getSize().x) {
                r.setxVel(r.getxVel() * -1);
            }

            if (r.getShape().getPosition().x <= 0) {
                r.setxVel(r.getxVel() * -1);
            }
        }

        for (auto& c : CircleShapeList) {
                c.setPos(c.getShape().getPosition().x, c.getShape().getPosition().y - c.getyVel());
                c.setPos(c.getShape().getPosition().x - c.getxVel(), c.getShape().getPosition().y);

                if (c.getShape().getPosition().y + c.getShape().getLocalBounds().height >= window.getSize().y) {
                    c.setyVel(c.getyVel() * -1);
                }

                if (c.getShape().getPosition().y <= 0) {
                    c.setyVel(c.getyVel() * -1);
                }

                if (c.getShape().getPosition().x + c.getShape().getLocalBounds().width >= window.getSize().x) {
                    c.setxVel(c.getxVel() * -1);
                }

                if (c.getShape().getPosition().x <= 0) {
                    c.setxVel(c.getxVel() * -1);
                }          
        }
      
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }     
        }   
        window.clear();
        for (myRectangleShape r : RectangleShapeList) {
            window.draw(r.getShape());
        }

        for (myCircleShape c: CircleShapeList) {
            window.draw(c.getShape());
        }
        window.display();
    }
   



    return 0;
}
