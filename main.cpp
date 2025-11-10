#include "graphics.h"

using namespace std;
using namespace mssm;
class Button {
public:
    Vec2d pos;
    // bool checked;
    Color color;
    int width;
    int height;
    string label;

    void draw(Graphics& g);
    //void update(Graphics& g);

    bool isMouseOver(Graphics& g); // return true if mouse is currently over the button
    bool isClicked(Graphics& g); // return true if mouse is clicked
};
void Button::draw(Graphics& g)
{
    if (isMouseOver(g)){
        g.rect(pos,width,height,BLUE,BLUE);
    }
    else {
         g.rect(pos,width,height,color,color);
    }
    g.text(pos, 40, format("Press Button"), WHITE);
}

bool Button::isMouseOver(Graphics &g)
{
    Vec2d mp = g.mousePos();
    if (mp.x >=200 && mp.x <= 500 && mp.y >=150 && mp.y <= 350)
    {
       return true;
    }
    return false;
}

bool Button::isClicked(Graphics &g)
{
    if (isMouseOver(g) && g.onMousePress(MouseButton::Left))
    {
        g.text({20,40}, 20, format("HELLO!"), GREEN);
        Sound Laser(g,"sounds/ShortLaser.wav");
        g.play(Laser,0.8);
    }
    return false;
}
int main()
{
    Graphics g("Hello Graphics!", 1024, 768);

    int x = 0;
    Button b {{200,150}, PURPLE, 300, 200, "press button"};
    //Button c {{400,150}, BLUE, 100, 200, "press button"};
    while (g.draw()) {
        if (!g.isDrawable()) {
            continue;
        }
        b.draw(g);
        //c.draw(g);
        // g.line({100,200}, {300,400}, GREEN);

        // g.ellipse({500,500}, 20, 30, YELLOW, PURPLE);

        // g.text({20,40}, 20, format("HELLO!!! {}", x), GREEN);

        // g.rect({600,600}, 150, 50, RED, YELLOW);

        if (g.onKeyPress(Key::Space)) {
            g.printError("Space!!!");
            x++;
        }
    }

    return 0;
}


