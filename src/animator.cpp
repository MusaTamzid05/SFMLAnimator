#include "animator.h"
#include <iostream>

namespace Graphics {


    FrameSprite::FrameSprite(const std::string& file_path , const sf::IntRect& rect) {

        texture = new sf::Texture();

        if(!texture->loadFromFile(file_path , rect )) {
            std::cerr << "Error loading " << file_path << "\n";
            return;
        }

        std::cout << "Texture is loaded.\n";
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);

    }


    void FrameSprite::draw(sf::RenderWindow& window) {

        window.draw(*sprite);
    }


    Animator::Animator(const std::string& file_path):
    file_path(file_path),
    current_frame(0){

    }




    void Animator::add_frame(const sf::IntRect& rect ) {
        m_frames.push_back(FrameSprite(file_path , rect));
    }


    void Animator::play(sf::RenderWindow& window ) {

        if(m_frames.size() == 0) {
            std::cerr << "No frame to animate!!\n";
            return;
        }

        m_frames[current_frame].draw(window);


    }

    void Animator::update() {
        current_frame = (current_frame + 1) % m_frames.size();
    }

    
    void Animator::update(sf::Time& delta_time) {
    

        // TO-DO : Find a better way !!! This is a hack for now !!
        if(clock.getElapsedTime().asSeconds() < 0.1) {
            return;
        }

        clock.restart();
        update();
    }

};
