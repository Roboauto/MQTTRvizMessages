#pragma once

#include <iostream>
#include <msgpack.h>

namespace MQTTVisualizationMessages {

    struct OccupancyGrid {

        std::string frame_id{"map"};
        unsigned time_stamp = 0;
        std::string name_space{""};
        double resolution;              // m/cell
        double width;                   // cells
        double height;                  // cells
        std::vector<int8_t> data;

        MSGPACK_DEFINE(frame_id, time_stamp, name_space, resolution, width, height, data);
    };
}