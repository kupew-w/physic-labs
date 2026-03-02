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

    float cx = w / 2.0f;
    float cy = h / 2.0f;

    r->line(0, cy, w, cy, {255,0,0,255});   
    r->line(cx, 0, cx, h, {0,255,0,255}); 

    float scale = 100.0f;

    for (int i = 1; i < data.size(); ++i)
    {
        float x1 = cx+data[i-1].x * scale;
        float y1 = cy-data[i-1].y * scale;

        float x2 = cx+data[i].x * scale;
        float y2 = cy-data[i].y * scale;

        r->line( x1, y1, x2, y2, {0,0,255,255});
    }
}

void pl::Decart::addData(std::shared_ptr<LabToken> token , std::string x, std::string y)
{ }
