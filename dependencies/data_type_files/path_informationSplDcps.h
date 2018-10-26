#ifndef PATH_INFORMATIONSPLTYPES_H
#define PATH_INFORMATIONSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "path_information_DCPS.hpp"


extern c_metaObject __path_information_path_information__load (c_base base);

extern const char *path_information_Msg_metaDescriptor[];
extern const int path_information_Msg_metaDescriptorArrLength;
extern const int path_information_Msg_metaDescriptorLength;
extern c_metaObject __path_information_Msg__load (c_base base);
struct _path_information_Msg ;
extern  v_copyin_result __path_information_Msg__copyIn(c_base base, const class path_information::Msg *from, struct _path_information_Msg *to);
extern  void __path_information_Msg__copyOut(const void *_from, void *_to);
struct _path_information_Msg {
    c_long id;
    c_double lateral_distance_error;
};

#undef OS_API
#endif
