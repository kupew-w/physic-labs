#include "graphics/Graphic.h"
#include "graphics/IRender.h"

void pl::Graphic::setRenderType(std::unique_ptr<pl::IRender> r)
{ render = std::move(r); }
