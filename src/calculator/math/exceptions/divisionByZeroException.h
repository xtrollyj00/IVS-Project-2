/*
© Copyright 2022
    Alexaj Ondrej <xalexa09@stud.fit.vutbr.cz>
    Gurka Oliver <xgurka00@stud.fit.vutbr.cz>
    Magda Jakub <xmagda03@stud.fit.vutbr.cz>
*/

#include <stdexcept>

namespace Exc {

    class DivisionByZeroException : public std::runtime_error {
        public:
        DivisionByZeroException(const char* msg) : std::runtime_error(msg) {}
    };

}
