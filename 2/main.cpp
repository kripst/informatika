#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graph Zones");
    
    float pointX = -1000, pointY = -1000;
    int zone = 0;
    float graphX = 0, graphY = 0;
    float mashtab = 40.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    pointX = static_cast<float>(event.mouseButton.x);
                    pointY = static_cast<float>(event.mouseButton.y);

                    graphX = (pointX - 400.0f) / mashtab;
                    graphY = (300.0f - pointY) / mashtab;

                    float y_red = graphX + 3.0f;
                    float y_blue = -5.0f;

                    if (graphY < y_red && graphY < y_blue) {
                        zone = 1;
                    }
                    else if (graphY > y_blue && graphY < y_red) {
                        zone = 2;
                    }
                    else if (graphY > y_red && graphY > y_blue) {
                        zone = 3;
                    }
                    else if (graphY < y_blue && graphY > y_red) {
                        zone = 4;
                    }
                    else {
                        zone = 0;
                    }
                }
            }
        }

        window.clear(sf::Color::Black);

        sf::VertexArray axes(sf::Lines, 4);
        axes[0] = sf::Vertex(sf::Vector2f(0.0f, 300.0f), sf::Color::White);
        axes[1] = sf::Vertex(sf::Vector2f(800.0f, 300.0f), sf::Color::White);
        axes[2] = sf::Vertex(sf::Vector2f(400.0f, 0.0f), sf::Color::White);
        axes[3] = sf::Vertex(sf::Vector2f(400.0f, 600.0f), sf::Color::White);
        window.draw(axes);

        sf::VertexArray line1(sf::LineStrip, 400);
        for (int i = 0; i < 400; i++) {
            float x = (static_cast<float>(i * 2) - 400.0f) / mashtab;
            float y = x + 3.0f;
            float screenX = static_cast<float>(i * 2);
            float screenY = 300.0f - y * mashtab;
            line1[i] = sf::Vertex(sf::Vector2f(screenX, screenY), sf::Color::Red);
        }
        window.draw(line1);

        sf::VertexArray line2(sf::Lines, 2);
        float y2_screen = 300.0f - (-5.0f) * mashtab;
        line2[0] = sf::Vertex(sf::Vector2f(0.0f, y2_screen), sf::Color::Blue);
        line2[1] = sf::Vertex(sf::Vector2f(800.0f, y2_screen), sf::Color::Blue);
        window.draw(line2);

        if (pointX > 0 && pointY > 0) {
            sf::CircleShape point(8.0f);
            point.setPosition(pointX - 8.0f, pointY - 8.0f);

            switch (zone) {
            case 1: point.setFillColor(sf::Color::Green); break;
            case 2: point.setFillColor(sf::Color::Yellow); break;
            case 3: point.setFillColor(sf::Color::Cyan); break;
            case 4: point.setFillColor(sf::Color::Magenta); break;
            default: point.setFillColor(sf::Color::White); break;
            }
            window.draw(point);

            sf::RectangleShape zoneIndicator(sf::Vector2f(30.0f, 30.0f));
            zoneIndicator.setPosition(20.0f, 20.0f);
            switch (zone) {
            case 1: zoneIndicator.setFillColor(sf::Color::Green); break;
            case 2: zoneIndicator.setFillColor(sf::Color::Yellow); break;
            case 3: zoneIndicator.setFillColor(sf::Color::Cyan); break;
            case 4: zoneIndicator.setFillColor(sf::Color::Magenta); break;
            default: zoneIndicator.setFillColor(sf::Color::White); break;
            }
            window.draw(zoneIndicator);
        }

        sf::RectangleShape z1(sf::Vector2f(20.0f, 20.0f));
        z1.setPosition(20.0f, 450.0f);
        z1.setFillColor(sf::Color::Green);
        window.draw(z1);

        sf::RectangleShape z2(sf::Vector2f(20.0f, 20.0f));
        z2.setPosition(20.0f, 480.0f);
        z2.setFillColor(sf::Color::Yellow);
        window.draw(z2);

        sf::RectangleShape z3(sf::Vector2f(20.0f, 20.0f));
        z3.setPosition(20.0f, 510.0f);
        z3.setFillColor(sf::Color::Cyan);
        window.draw(z3);

        sf::RectangleShape z4(sf::Vector2f(20.0f, 20.0f));
        z4.setPosition(20.0f, 540.0f);
        z4.setFillColor(sf::Color::Magenta);
        window.draw(z4);

        window.display();
    }

    return 0;
}