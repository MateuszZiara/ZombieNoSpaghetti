#include <valarray>
#include "../Header/Collision.h"
#include <SFML/Graphics.hpp>
sf::FloatRect getGlobalBounds(const std::vector<sf::Vector2f>& points) {
    sf::ConvexShape tempField;
    tempField.setPointCount(points.size());

    for (std::size_t i = 0; i < points.size(); ++i) {
        tempField.setPoint(i, points[i]);
    }

    return tempField.getGlobalBounds();
}
sf::ConvexShape getField(const std::vector<sf::Vector2f>& points, sf::RenderWindow& window, const sf::Color& fillColor)
{
    // Create a convex shape to represent the field
    sf::ConvexShape field;
    field.setPointCount(points.size());

    // Set the points of the convex shape
    for (std::size_t i = 0; i < points.size(); ++i) {
        field.setPoint(i, points[i]);

        sf::Vertex line[] = {
                sf::Vertex(points[i]),
                sf::Vertex(points[(i + 1) % points.size()])
        };

        window.draw(line, 2, sf::Lines);
    }
    // Set the fill color of the field
    field.setFillColor(fillColor);

    // Draw the filled field
    window.draw(field);
    return field;
}
void drawRectangleBounds(const sf::RectangleShape& rect, sf::RenderWindow& window, const sf::Color& boundsColor)
{
    // Create a rectangle shape representing the global bounds
    sf::RectangleShape boundsRect(rect.getGlobalBounds().getSize());
    boundsRect.setPosition(rect.getGlobalBounds().left, rect.getGlobalBounds().top);
    boundsRect.setFillColor(sf::Color::Transparent);
    boundsRect.setOutlineColor(boundsColor);
    boundsRect.setOutlineThickness(2.0f);

    // Draw the outlined rectangle
    window.draw(boundsRect);
}

bool isPointInsidePolygon(const sf::Vector2f& point, const std::vector<sf::Vector2f>& polygon)
{
    bool inside = false;
    for (std::size_t i = 0, j = polygon.size() - 1; i < polygon.size(); j = i++) {
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}
#include <algorithm> // for std::sort

bool isRectangleTouchingField(const sf::RectangleShape& rect, std::vector<sf::Vector2f> points, sf::RenderWindow& window)
{
    // Sort the points in counterclockwise order
    std::sort(points.begin(), points.end(), [&points](const sf::Vector2f& a, const sf::Vector2f& b) {
        return std::atan2(a.y - points[0].y, a.x - points[0].x) < std::atan2(b.y - points[0].y, b.x - points[0].x);
    });

    // Draw the filled field with red color
    sf::ConvexShape field = getField(points, window, sf::Color::Red);

    // Draw the rectangle bounds with yellow color
    drawRectangleBounds(rect, window, sf::Color::Yellow);

    // Iterate over the points of the rectangle
    for (const sf::Vector2f& rectPoint : {
            rect.getPosition(),
            {rect.getPosition().x + rect.getSize().x, rect.getPosition().y},
            {rect.getPosition().x, rect.getPosition().y + rect.getSize().y},
            {rect.getPosition().x + rect.getSize().x, rect.getPosition().y + rect.getSize().y}
    }) {
        // Check if the point is inside the convex shape
        if (isPointInsidePolygon(rectPoint, points)) {
            return true;
        }
    }

    // If none of the rectangle's points are inside the convex shape, return false
    return false;
}


