#ifndef GUI_H
#define GUI_H
#include "GUI\GUIElement.h"

#include <vector>
#include <memory>

namespace Eucolus {
    namespace GUI {
        class GUI {
        public:
            GUI();
            ~GUI();

            bool Init();
            void Update();
            void Render();
            bool Quit();

			static void AddElement(Element);

        private:
            std::vector<std::shared_ptr<Element>> m_elements;
        };
    }
}

#endif