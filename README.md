- [Projects](#projects)
  - [Program 1: Bouncing Shapes](#program-1-bouncing-shapes)

## Projects

### Program 1: Bouncing Shapes

A C++/SFML program which reads the description of a shape from a configuaration filem and them draws those shapes to the screen. 

The shapes also bounce off the side of the window that contains them. This means that if the shapes left side hits the left side of the window the X speed is reverced. 

Because SFML does not have a speed property for the shapes, I had to create a class that contains the shape and the speed of the shape. Example of the class is below.

```
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

```
I then created a vector of the class and added the shapes to the vector.
```
std::vector<myRectangleShape> RectangleShapeList;
sf::RectangleShape aShape(sf::Vector2f(shapeWidth, shapeHeight));
myRectangleShape anShape(xVelocity,yVelocity,aShape);       
RectangleShapeList.push_back(anShape);
```

Demo

![Alt Text](path/to/your/gif.gif)
