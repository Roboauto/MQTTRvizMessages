#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include <array>

#include <msgpack.hpp>

#include "Types.h"


namespace MQTTVisualizationMsgs {
  enum MarkerType {
    ARROW = 0,
    CUBE,
    SPEHERE,
    CYLINDER,
    LINE_STRIP,
    LINE_LIST,
    CUBE_LIST,
    SPHERE_LIST,
    POINTS,
    TEXT_VIEW_FACING,
    MESH_RESOURCE,
    TRIANGLE_LIST
  };

  struct MarkerMsg {
    int sequence_id;
    std::string frame_id;
    unsigned time_stamp;

    std::string name_space;

    int id;
    int type;
    int action;

    PoseXYZ position; //position
    Orientation orientation; //quaternion
    Scale scale;
    Color color;

    double lifetime;

    bool frame_locked;

    std::vector<PoseXYZ> points;
    std::vector<Color> colors;

    std::string text;
    std::string mesh_resource;
    bool mesh_use_embedded_materials;

    MSGPACK_DEFINE (sequence_id, frame_id, time_stamp, name_space, id, type, action, position, orientation, scale,
                    color, lifetime, frame_locked, points, colors, text, mesh_resource, mesh_use_embedded_materials)

  };

  struct MarkerArrayMsg {
    std::vector<MarkerMsg> markers;
    MSGPACK_DEFINE (markers)
  };
}