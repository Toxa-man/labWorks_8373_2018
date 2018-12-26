#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include<ctime>
#include <fstream>

sf::Clock lock;
const int width = 10;
const int height = 20;
const float speed = 0.5;

std::ofstream file;

enum figure_type {line, square, l_chair, r_chair, l_gnome, r_gnome};
const figure_type arre[] = {line, square, l_chair, r_chair, l_gnome, r_gnome};

const int screen_x = 720;
const int screen_y = 720;
const int cube_size = screen_y / 22;

struct point{int x; int y;};

struct figure
{
    figure_type type;
    std::vector<point> body;
    int position;
};



void draw_figure(figure f, int* field)
{
    for (int i = 0; i < 4; i++)
    {
        *(field + width*f.body[i].y + f.body[i].x) = 1;
    }
}

void delete_figure(figure f, int* field)
{
    for (int i = 0; i < 4; i++)
    {
        *(field + width*f.body[i].y + f.body[i].x) = 0;
        field[width*f.body[i].y + f.body[i].x] = 0;
    }
}

void print(int* arr, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << *(arr + i*width + j);
        }
        std::cout << std::endl;
    }
}

void swap_arrays (int* arr1, int* arr2, int length)
{
    int temp[length] = {0};
    for (int i = 0; i < length; i++)
    {
        temp[i] = *(arr1 + i);
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp[i];
    }

}
void update_vector(std::vector<int> &vec, int a, int b, int c)
{
    vec.clear();
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
}

bool turn_possible(std::vector<int> points_x, std::vector<int> points_y , int* field)
{
    std::cout<< points_x.size();
    for(int i = 0; i < points_x.size(); i++)
    {
        if (*(field + width*points_y[i] + points_x[i]) != 0 || points_x[i] > width - 1 || points_x[i] < 0 || points_y[i] > height - 1)
        {
            return false;
        }
    }
    return true;
}
void clean_array(int* arr)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(arr + i*width + j) = 0;
        }
    }
}

void turn_figure(figure &f, int* field)
{
    delete_figure(f, (int*) field);
    std::vector<int> points_x = {};
    std::vector<int> points_y = {};
    switch (f.type)
    {
    case line:
        switch (f.position)
        {
        case 1:
            update_vector(points_x, f.body[1].x - 1, f.body[1].x + 1, f.body[1].x + 2);
            update_vector(points_y, f.body[1].y, f.body[1].y, f.body[1].y);
            if(turn_possible(points_x, points_y, (int*) field))
            {
                f.body[0].x = f.body[1].x - 1;
                f.body[0].y = f.body[1].y;
                f.body[2].x = f.body[1].x + 1;
                f.body[2].y = f.body[1].y;
                f.body[3].x = f.body[1].x + 2;
                f.body[3].y = f.body[1].y;
                f.position = 2;
            }
            break;
        case 2:
            update_vector(points_x, f.body[1].x, f.body[1].x, f.body[1].x);
            update_vector(points_y, f.body[1].y - 1, f.body[1].y + 1, f.body[1].y + 2);
            if(turn_possible(points_x, points_y, (int*) field))
            {
                f.body[0].x = f.body[1].x;
                f.body[0].y = f.body[1].y - 1;
                f.body[2].x = f.body[1].x;
                f.body[2].y = f.body[1].y + 1;
                f.body[3].x = f.body[1].x;
                f.body[3].y = f.body[1].y + 2;
                f.position = 1;
            }
            break;
        }
        break;
    case l_chair:
        switch (f.position)
        {
        case 1:
            update_vector(points_x, f.body[1].x - 1, f.body[1].x + 1, f.body[1].x + 1);
            update_vector(points_y, f.body[1].y, f.body[1].y, f.body[1].y - 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x - 1 ;
            f.body[0].y = f.body[1].y;
            f.body[2].x = f.body[1].x + 1;
            f.body[2].y = f.body[1].y;
            f.body[3].x = f.body[1].x + 1;
            f.body[3].y = f.body[1].y - 1;
            f.position = 2;
            }
            break;

        case 2:
            update_vector(points_x, f.body[1].x, f.body[1].x, f.body[1].x - 1);
            update_vector(points_y, f.body[1].y + 1, f.body[1].y - 1, f.body[1].y - 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x;
            f.body[0].y = f.body[1].y + 1;
            f.body[2].x = f.body[1].x;
            f.body[2].y = f.body[1].y - 1;
            f.body[3].x = f.body[1].x - 1;
            f.body[3].y = f.body[1].y - 1;
            f.position = 3;
            }
            break;
        case 3:
            update_vector(points_x, f.body[1].x + 1, f.body[1].x - 1, f.body[1].x - 1);
            update_vector(points_y, f.body[1].y, f.body[1].y, f.body[1].y + 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x + 1;
            f.body[0].y = f.body[1].y;
            f.body[2].x = f.body[1].x - 1;
            f.body[2].y = f.body[1].y;
            f.body[3].x = f.body[1].x - 1;
            f.body[3].y = f.body[1].y + 1;
            f.position = 4;
            }
            break;
        case 4:
            std::cout << 4;
            update_vector(points_x, f.body[1].x, f.body[1].x, f.body[1].x + 1);
            update_vector(points_y, f.body[1].y - 1, f.body[1].y + 1, f.body[1].y + 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x;
            f.body[0].y = f.body[1].y - 1;
            f.body[2].x = f.body[1].x;
            f.body[2].y = f.body[1].y + 1;
            f.body[3].x = f.body[1].x + 1;
            f.body[3].y = f.body[1].y + 1;
            f.position = 1;
            }
            break;
        }
        break;
    case l_gnome:
        switch (f.position)
        {
        case 1:
            update_vector(points_x, f.body[1].x, f.body[1].x + 1, f.body[1].x + 1);
            update_vector(points_y, f.body[1].y - 1, f.body[1].y, f.body[1].y + 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x;
            f.body[0].y = f.body[1].y - 1;
            f.body[2].x = f.body[1].x + 1;
            f.body[2].y = f.body[1].y;
            f.body[3].x = f.body[1].x + 1;
            f.body[3].y = f.body[1].y + 1;
            f.position = 2;
            }
            break;
        case 2:
            update_vector(points_x, f.body[1].x - 1, f.body[1].x, f.body[1].x + 1);
            update_vector(points_y, f.body[1].y, f.body[1].y - 1, f.body[1].y - 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x - 1;
            f.body[0].y = f.body[1].y;
            f.body[2].x = f.body[1].x;
            f.body[2].y = f.body[1].y - 1;
            f.body[3].x = f.body[1].x + 1;
            f.body[3].y = f.body[1].y - 1;
            f.position = 1;
            }
            break;
        }
        break;
    case r_gnome:
        switch (f.position)
        {
        case 1:
            update_vector(points_x, f.body[1].x, f.body[1].x - 1, f.body[1].x - 1);
            update_vector(points_y, f.body[1].y - 1, f.body[1].y, f.body[1].y + 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x;
            f.body[0].y = f.body[1].y - 1;
            f.body[2].x = f.body[1].x - 1;
            f.body[2].y = f.body[1].y;
            f.body[3].x = f.body[1].x - 1;
            f.body[3].y = f.body[1].y + 1;
            f.position = 2;
            }
            break;
        case 2:
            update_vector(points_x, f.body[1].x - 1, f.body[1].x, f.body[1].x + 1);
            update_vector(points_y, f.body[1].y, f.body[1].y + 1, f.body[1].y + 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x - 1;
            f.body[0].y = f.body[1].y;
            f.body[2].x = f.body[1].x;
            f.body[2].y = f.body[1].y + 1;
            f.body[3].x = f.body[1].x + 1;
            f.body[3].y = f.body[1].y + 1;
            f.position = 1;
            break;
            }
        }
        break;
    case r_chair:
        switch (f.position)
        {
        case 1:
            update_vector(points_x, f.body[1].x - 1, f.body[1].x + 1, f.body[1].x + 1);
            update_vector(points_y, f.body[1].y, f.body[1].y, f.body[1].y + 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x - 1;
            f.body[0].y = f.body[1].y;
            f.body[2].x = f.body[1].x + 1;
            f.body[2].y = f.body[1].y;
            f.body[3].x = f.body[1].x + 1;
            f.body[3].y = f.body[1].y + 1;
            f.position = 2;
            }
            break;
        case 2:
            update_vector(points_x, f.body[1].x, f.body[1].x, f.body[1].x + 1);
            update_vector(points_y, f.body[1].y + 1, f.body[1].y - 1, f.body[1].y - 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x;
            f.body[0].y = f.body[1].y + 1;
            f.body[2].x = f.body[1].x;
            f.body[2].y = f.body[1].y - 1;
            f.body[3].x = f.body[1].x + 1;
            f.body[3].y = f.body[1].y - 1;
            f.position = 3;
            }
            break;
        case 3:
            update_vector(points_x, f.body[1].x + 1, f.body[1].x - 1, f.body[1].x - 1);
            update_vector(points_y, f.body[1].y, f.body[1].y, f.body[1].y - 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x + 1;
            f.body[0].y = f.body[1].y;
            f.body[2].x = f.body[1].x - 1;
            f.body[2].y = f.body[1].y;
            f.body[3].x = f.body[1].x - 1;
            f.body[3].y = f.body[1].y - 1;
            f.position = 4;
            }
            break;
        case 4:
            update_vector(points_x, f.body[1].x, f.body[1].x, f.body[1].x - 1);
            update_vector(points_y, f.body[1].y - 1, f.body[1].y + 1, f.body[1].y + 1);
            if(turn_possible(points_x, points_y, (int*) field)){
            f.body[0].x = f.body[1].x;
            f.body[0].y = f.body[1].y - 1;
            f.body[2].x = f.body[1].x;
            f.body[2].y = f.body[1].y + 1;
            f.body[3].x = f.body[1].x - 1;
            f.body[3].y = f.body[1].y + 1;
            f.position = 1;
            }
            break;
        }
        break;
    case square:
        break;
    }
    draw_figure(f, (int*) field);
}


void move_down(figure &f, int* field)
{
    bool result = true;
    for (int i = 0; i < 4; i++)
    {
         if( *(field + width*(f.body[i].y + 1) + f.body[i].x) == 2 || f.body[i].y == (height - 1))
        {
            result = 0;
        }
    }
    if(result)
    {
        delete_figure(f, (int*) field);
        for(int i = 0; i < 4 ; i++)
        {
            f.body[i].y += 1;
        }
        draw_figure(f, (int*) field);
    }
}
void move_right(figure &f, int* field)
{
    bool flag = true;
    for(int i = 0; i < 4; i++)
    {
        if (f.body[i].x == (width - 1) || *(field+ f.body[i].y*width + f.body[i].x + 1) == 2)
        {
            flag = false;
            break;
        }
    }
    if(flag){
    delete_figure(f, (int*) field);
    for(int i = 0; i < 4 ; i++)
    {
        f.body[i].x += 1;
    }
    draw_figure(f, (int*) field);
    }
}
void move_left(figure &f, int* field)
{
    bool flag = true;
    for(int i = 0; i < 4; i++)
    {
        if (f.body[i].x == 0 || *(field+ f.body[i].y*width + f.body[i].x - 1) == 2)
        {
            flag = false;
            break;
        }
    }
    if(flag){
    delete_figure(f, (int*) field);
    for(int i = 0; i < 4 ; i++)
    {
        f.body[i].x -= 1;
    }
    draw_figure(f, (int*) field);
    }
}

void create_figure(figure &f)
{
    f.type = (arre[rand() % 6]);
    point a1, a2, a3, a4;
    if (f.type == line)
    {
        a1.x = 3;
        a1.y = 0;
        a2.x = 3;
        a2.y = 1;
        a3.x = 3;
        a3.y = 2;
        a4.x = 3;
        a4.y = 3;
    } else if(f.type == square){
        a1.x = 3;
        a1.y = 0;
        a2.x = 4;
        a2.y = 0;
        a3.x = 3;
        a3.y = 1;
        a4.x = 4;
        a4.y = 1;
    } else if(f.type == l_chair){
        a1.x = 3;
        a1.y = 0;
        a2.x = 3;
        a2.y = 1;
        a3.x = 3;
        a3.y = 2;
        a4.x = 4;
        a4.y = 2;
    } else if(f.type == r_chair){
        a1.x = 4;
        a1.y = 0;
        a2.x = 4;
        a2.y = 1;
        a3.x = 4;
        a3.y = 2;
        a4.x = 3;
        a4.y = 2;
    } else if(f.type == l_gnome){
        a1.x = 3;
        a1.y = 1;
        a2.x = 4;
        a2.y = 1;
        a3.x = 4;
        a3.y = 0;
        a4.x = 5;
        a4.y = 0;
    } else if(f.type == r_gnome){
        a1.x = 3;
        a1.y = 0;
        a2.x = 4;
        a2.y = 0;
        a3.x = 4;
        a3.y = 1;
        a4.x = 5;
        a4.y = 1;
    }
    f.body = {a1, a2, a3, a4};
    f.position = 1;

}



void delete_complete_lines(int* arr, int &score)
{
    for(int i = height - 1; i > 0; i--)
    {
        bool complete = true;
        for (int k = 0; k < width; k++)
        {
            if (*(arr + i*width + k) == 0)
            {
                complete = false;
                break;
            }
        }
        if(complete)
        {
            score++;
            for (int j = 0; j < width; j++) {*(arr + i*width + j) = 0;}
            for (int k = i; k > 0 ; k--)
            {
                swap_arrays((int*) arr + k*width, (int*) arr + (k-1)*width, width);
            }
            delete_complete_lines((int*) arr, score);
        }
    }
}
bool free_down(figure f, int* field)
{
    bool result = 1;
    for(int i = 0; i < 4; i++)
    {
        if (*(field + (f.body[i].y + 1)*width + f.body[i].x) == 2 || f.body[i].y == height - 1)
        {
            result = false;
        }
    }
    return result;
}

bool losted(figure f,int* field)
{
    if (!(free_down(f, (int*) field)))
    {
        for (int i = 0; i < 4; i++)
        {
            if (f.body[i].y == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void graphics(sf::RenderWindow &window, int* field, sf::Text &score_t, sf::Text &highscore_t, sf::Text &score_count, sf::Text &highscore_count, int &score, int &highscore)
{
    window.clear();
    window.draw(score_t);
    window.draw(highscore_t);
    sf::RectangleShape rectangle(sf::Vector2f(cube_size*10, cube_size*20));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setPosition(0.9*cube_size, 0.9*cube_size);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(cube_size / 10);
    window.draw(rectangle);
    score_count.setString(std::to_string(score));
    highscore_count.setString(std::to_string(highscore));
    window.draw(score_count);
    window.draw(highscore_count);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (*(field + i*width + j) != 0)
            {
                sf::RectangleShape rectangle(sf::Vector2f(cube_size*0.8, cube_size*0.8));
                rectangle.setFillColor(sf::Color::Red);
                rectangle.setPosition(cube_size + j*cube_size, cube_size + i*cube_size);
                rectangle.setOutlineColor(sf::Color::White);
                rectangle.setOutlineThickness(cube_size / 10);
                window.draw(rectangle);
            }
        }
    }
    window.display();
}

void create_text(sf::Text &text, int pos_x, int pos_y, sf::Font &font, std::string str)
{
    text.setFont(font);
    text.setColor(sf::Color::White);
    text.setString(str);
    text.setCharacterSize(cube_size);
    text.setPosition(pos_x, pos_y);
}
void write_highscore(int number)
{
    std::ofstream file;
    file.open("/home/jordano/tetris/hscores.txt", std::ios::out);
    if(file.is_open())
    {
        file << number;
    }
}
int get_highscore ()
{
    std::ifstream file;
    file.open("/home/jordano/tetris/hscores.txt", std::ios::in);
    std::string str;
    if(file.is_open())
    {
        getline(file, str);
    }
    return std::stoi(str);
}
void LostTheGame(sf::RenderWindow &window, int* field, sf::Font &arial, int &score, int &highscore, bool &gameover);
void play_game(sf::RenderWindow &window, int* field, sf::Font &arial, int &score, int &highscore, bool &gameover)
{
    highscore = get_highscore();
    sf::Text score_t;
    sf::Text highscore_t;
    sf::Text score_count;
    sf::Text highscore_count;
    create_text(score_t, 14*cube_size, cube_size, arial, "Score");
    create_text(highscore_t, 14*cube_size, 3*cube_size, arial, "Highscore");
    create_text(score_count, 20*cube_size, cube_size, arial, "0");
    create_text(highscore_count, 20*cube_size, 3*cube_size, arial, "0");

    lock.restart();
    while (window.isOpen())
    {
        while(!gameover)
        {
            figure f;
            create_figure(f);
            while(free_down(f, (int*) field))
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();

                    if (event.type == sf::Event::KeyPressed)
                    {
                        switch(event.key.code)
                        {
                        case(sf::Keyboard::Space):
                            turn_figure(f, (int*) field);
                            break;
                        case(sf::Keyboard::Left):
                            move_left(f, (int*) field);
                            break;
                        case(sf::Keyboard::Right):
                            move_right(f, (int*) field);
                            break;
                        default:
                            break;
                        }
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { move_down(f, (int*) field); }
                }
                graphics(window, (int*) field, score_t, highscore_t, score_count, highscore_count, score, highscore);
                float elapsed = lock.getElapsedTime().asSeconds();
                if (elapsed >= speed)
                {
                    lock.restart();
                    move_down(f, (int*) field);
                }

            }

            for (int i = 0; i < 4; i++)
            {
                *(field + f.body[i].y*width + f.body[i].x) = 2;
            }
            delete_complete_lines((int*) field, score);
            if(losted(f, (int*) field)) {LostTheGame(window, (int*) field, arial, score, highscore, gameover);}
        }
    }
}

struct Button
{
    int x1, y1, x2, y2;
    bool click(int x, int y)
    {
        if (x > x1 && x < x2 && y > y1 && y < y2)
        {
            return true;
        }

        return false;
    }
};

void create_button(Button &but, int x1, int y1, int x2, int y2)
{
    but.x1 = x1;
    but.y1 = y1;
    but.x2 = x2;
    but.y2 = y2;
}
void show_highsc_inf(sf::RenderWindow &window, sf::Font &arial, int* field, int &score, int &highscore, bool &gameover);
void Menu(sf::RenderWindow &window, sf::Font &arial, int* field, int &score, int &highscore, bool &gameover)
{

    Button Start;
    Button Highscores;
    Button Exit;
    create_button(Start, 2*cube_size, 8*cube_size, 6*cube_size, 9*cube_size);
    create_button(Highscores, 2*cube_size, 10*cube_size, 6*cube_size, 11*cube_size);
    create_button(Exit, 2*cube_size, 12*cube_size, 6*cube_size, 13*cube_size);
    sf::Text startT, highT, exitT;
    create_text(startT, Start.x1, Start.y1, arial, "Start");
    create_text(highT, Highscores.x1, Highscores.y1, arial, "Highscores");
    create_text(exitT, Exit.x1, Exit.y1, arial, "Exit");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                sf::Vector2f pos = window.mapPixelToCoords(pixelPos);
                 if(Start.click(pos.x, pos.y)){
                    play_game(window, (int*) field, arial, score, highscore, gameover);
                 }
                 if(Exit.click(pos.x, pos.y)){
                        window.close();
                 }
                 if(Highscores.click(pos.x, pos.y)){
                        show_highsc_inf(window, arial, field, score, highscore, gameover);
                 }
            }
        }
        window.clear();
        window.draw(startT);
        window.draw(highT);
        window.draw(exitT);
        window.display();
    }
}
void show_highsc_inf(sf::RenderWindow &window, sf::Font &arial, int* field, int &score, int &highscore, bool &gameover)
{
    sf::Text text1, text2, text3;
    create_text(text1, 2*cube_size, 10*cube_size, arial, "Your highscore is:");
    create_text(text2, 12*cube_size, 10*cube_size, arial, std::to_string(get_highscore()));
    create_text(text3, 2*cube_size, 12*cube_size, arial, "Press any key to return to menu");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                Menu(window, arial, (int*) field, score, highscore, gameover);
        }
        window.clear();
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.display();
    }
}

void LostTheGame(sf::RenderWindow &window, int* field, sf::Font &arial, int &score, int &highscore, bool &gameover)
{
    gameover = 0;
    if (score > highscore) {
        highscore = score;
        write_highscore(highscore);
    }
    sf::Text text1, text2, text3;
    create_text(text1, 2*cube_size, 10*cube_size, arial, "Nice game. Your score is:");
    create_text(text2, 15*cube_size, 10*cube_size, arial, std::to_string(score));
    create_text(text3, 2*cube_size, 12*cube_size, arial, "Press any key to return to menu");
    clean_array((int*) field);
    score = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                Menu(window, arial, (int*) field, score, highscore, gameover);
        }
        window.clear();
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.display();
    }
}





int main()
{
    bool gameover = 0;
    int score = 0;
    int highscore = get_highscore();
    int field[height][width] = {0};
    sf::Font arial;
    arial.loadFromFile("/home/jordano/tetris/arial.ttf");
    sf::RenderWindow window(sf::VideoMode(screen_x, screen_y), "Smell like a teen spirit!!!");
    Menu(window, arial, (int*) field, score, highscore, gameover);

    return 0;
}
