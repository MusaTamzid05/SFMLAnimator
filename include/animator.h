#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "animator.h"

namespace Graphics {

    struct FrameSprite {

        sf::Texture* texture;
        sf::Sprite* sprite;

        FrameSprite(const std::string& file_path , const sf::IntRect& rect);
        void draw(sf::RenderWindow& window);

    };

    class Animator {
        
        public:
            
            Animator(const std::string& file_path);

            virtual ~Animator() {}

            void set_texture_path(const std::string& file_path) { this->file_path = file_path; }

            void add_frame(const sf::IntRect& rect);
            int get_total_frames() { return m_frames.size(); }
            void play(sf::RenderWindow& window);;


            /// this is for updating sprite automaticly.
            void update(sf::Time& delta_time);

            // call it when handling event.
            void update();

        private:

            std::vector<FrameSprite> m_frames;
            std::string file_path;

            int current_frame;

            sf::Clock clock;

                                                                                                                                                                                                       
    };

};
#endif
