/**
 * Created by Peter Hofmann on 13.01.19.
 */

#include "cpptemplatesub1.h"

using namespace SubModule1;

/// Getter Method
std::string DummySub1::getDummyValue() { return _dummyValue; }
/// Setter Method
void DummySub1::setDummyValue(const std::string &value) { _dummyValue = value;}
