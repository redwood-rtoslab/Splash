#include "path_information_DCPS.hpp"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__path_information_Msg__copyIn(
    c_base base,
    const class ::path_information::Msg *from,
    struct _path_information_Msg *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
    to->lateral_distance_error = (c_double)from->lateral_distance_error_;
    return result;
}

void
__path_information_Msg__copyOut(
    const void *_from,
    void *_to)
{
    const struct _path_information_Msg *from = (const struct _path_information_Msg *)_from;
    class ::path_information::Msg *to = (class ::path_information::Msg *)_to;
    to->id((int32_t)from->id);
    to->lateral_distance_error((double)from->lateral_distance_error);
}

