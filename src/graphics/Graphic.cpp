#include "graphics/Graphic.h"
#include "graphics/IRender.h"
#include <memory>

void pl::Graphic::setRenderType(std::unique_ptr<pl::IRender> r)
{ render = r; }
