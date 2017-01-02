#ifndef GUIPANEL_H
#define GUIPANEL_H
#include "Utility\Utility.h"
#include "GUI\GUIElement.h"

#include <vector>
#include <memory>

namespace Eucolus {
    namespace GUI {
        class Panel : Element {
        public:
			Panel();
            ~Panel();

            void Update();
            void Render();

			void AddElement();

        private:
			std::vector<std::shared_ptr<Element>> m_elements;
        };
    }
}

#endif