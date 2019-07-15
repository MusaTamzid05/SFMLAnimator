#ifndef GAME_H
#define GAME_H


#include <SFML/Graphics.hpp>
#include "animator.h"

namespace GameEngine{


    class Game{

        public:

            Game(const std::string& window_name  , int width , int height);
            virtual ~Game();


            void run(float minimum_framerate);

        private:

            sf::RenderWindow* m_window;

            void update(sf::Time& delta_time);
            void render();
            void process_event();

            void update_if_time(sf::Time& time_since_last_update);

            sf::Time time_per_frame;

            Graphics::Animator animator;




    };

};
#endif
