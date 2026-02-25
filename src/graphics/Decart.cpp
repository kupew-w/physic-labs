#include "graphics/Decart.h"
#include "graphics/IRender.h"
#include "tokens/lab/ExperimentToken.h"
#include "tokens/lab/LabToken.h"
#include <memory>
#include <math.h>

pl::Decart::Decart(std::shared_ptr<LabToken> token, std::string x, std::string y)
{
    for(std::shared_ptr<ExperimentToken> expToken : *token)
    {
        data.push_back({std::stof((*expToken)[x]), std::stof((*expToken)[y])});
    }
}

void pl::Decart::draw(std::shared_ptr<IRender> r)
{
    int w = r->width();
    int h = r->height();

    // Центр координат
    float cx = w / 2.0f;
    float cy = h / 2.0f;

    // Осі
    r->line(0, cy, w, cy, {0,0,0,255});   // X
    r->line(cx, 0, cx, h, {0,0,0,255});   // Y

    // Масштаб
    float scale = 50.0f;

    // Малюємо sin(x)
    for (float x = -cx; x < cx - 1; x += 1)
    {
        float y1 = std::sin(x / scale) * scale;
        float y2 = std::sin((x + 1) / scale) * scale;

        r->line(
            cx + x,
            cy - y1,
            cx + x + 1,
            cy - y2,
            {0,0,0,255}
        );
    }
}

void pl::Decart::addData(std::shared_ptr<LabToken> token , std::string x, std::string y)
{ }
