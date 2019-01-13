/**
 * Created by Peter Hofmann on 13.01.19.
 */

#ifndef CPPTEMPLATESUB1_CPPTEMPLATESUB1_H
#define CPPTEMPLATESUB1_CPPTEMPLATESUB1_H

#include <string>
#include "Cpp-Template-Sub1-Sub/include/cpptemplatesub1sub.h"

namespace SubModule1
{

    class DummySub1 : public NamedClass
    {
    private:
        /// Dummy value
        std::string _dummyValue = "DummyValueSub1";
    public:
        /**
         * Name of Class
         * Returns name of the class
         * @return Class name
         */
        DummySub1() : NamedClass("DummySub1") {}

        /// Getter Method
        std::string getDummyValue();
        /// Setter Method
        void setDummyValue(const std::string &value);
    };

}

#endif //CPPTEMPLATESUB1_CPPTEMPLATESUB1_H
