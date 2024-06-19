#define SFML_STATIC
#include <SFML/Graphics.hpp>
#define TAM 1500

int randomh=0, part=1, itera=0, aux=0, lims=TAM-1, min=0;
bool sorted = false;

struct data{
    int height;
    int posx;
}line[TAM];


int main(){

    sf::RenderWindow window(sf::VideoMode(TAM,600), "Selection", sf::Style::Close);
    sf::Event event;

    sf::RectangleShape rectangle(sf::Vector2f(2,178));
    rectangle.setFillColor(sf::Color(235,149,13));

    srand(time(NULL));

    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
        }

        if(part==2 && !sorted){
            if(itera<=lims){
                min=itera;
                for(int j=itera+1; j<TAM; j++){
                    if(line[j].height < line[min].height){
                        min = j;
                    }
                }
                aux = line[itera].height;
                line[itera].height = line[min].height;
                line[min].height = aux;
                itera++;
            }else{
                sorted = true;
            }
        }

        if(part==1){
            for(int i=0; i<TAM; i++){
                randomh=1+rand()%600;
                line[i].posx=i;
                line[i].height=randomh;
                if(i==TAM-1)part=2;
            }
        }

        window.clear(sf::Color::Black);
        for(int i=0; i<TAM; i++){
            if(sorted){
                rectangle.setFillColor(sf::Color(0,255,0));
            }else{
                rectangle.setFillColor(sf::Color(255,255,255));
                if(i==itera)rectangle.setFillColor(sf::Color(0,0,255));
            }
            rectangle.setPosition(line[i].posx,600);
            rectangle.setSize(sf::Vector2f(2,line[i].height));
            rectangle.setRotation(180);
            window.draw(rectangle);
        }
        window.display();
    }

    

    return 0;
}