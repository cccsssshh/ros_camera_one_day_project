// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from capture_msgs:srv/Capture.idl
// generated code does not contain a copyright notice

#ifndef CAPTURE_MSGS__SRV__DETAIL__CAPTURE__STRUCT_H_
#define CAPTURE_MSGS__SRV__DETAIL__CAPTURE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'filter_type'
// Member 'action'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Capture in the package capture_msgs.
typedef struct capture_msgs__srv__Capture_Request
{
  rosidl_runtime_c__String filter_type;
  rosidl_runtime_c__String action;
} capture_msgs__srv__Capture_Request;

// Struct for a sequence of capture_msgs__srv__Capture_Request.
typedef struct capture_msgs__srv__Capture_Request__Sequence
{
  capture_msgs__srv__Capture_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} capture_msgs__srv__Capture_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Capture in the package capture_msgs.
typedef struct capture_msgs__srv__Capture_Response
{
  bool success;
  rosidl_runtime_c__String message;
} capture_msgs__srv__Capture_Response;

// Struct for a sequence of capture_msgs__srv__Capture_Response.
typedef struct capture_msgs__srv__Capture_Response__Sequence
{
  capture_msgs__srv__Capture_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} capture_msgs__srv__Capture_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAPTURE_MSGS__SRV__DETAIL__CAPTURE__STRUCT_H_
