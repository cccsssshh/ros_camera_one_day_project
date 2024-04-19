// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from capture_msgs:srv/Capture.idl
// generated code does not contain a copyright notice
#include "capture_msgs/srv/detail/capture__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `filter_type`
// Member `action`
#include "rosidl_runtime_c/string_functions.h"

bool
capture_msgs__srv__Capture_Request__init(capture_msgs__srv__Capture_Request * msg)
{
  if (!msg) {
    return false;
  }
  // filter_type
  if (!rosidl_runtime_c__String__init(&msg->filter_type)) {
    capture_msgs__srv__Capture_Request__fini(msg);
    return false;
  }
  // action
  if (!rosidl_runtime_c__String__init(&msg->action)) {
    capture_msgs__srv__Capture_Request__fini(msg);
    return false;
  }
  return true;
}

void
capture_msgs__srv__Capture_Request__fini(capture_msgs__srv__Capture_Request * msg)
{
  if (!msg) {
    return;
  }
  // filter_type
  rosidl_runtime_c__String__fini(&msg->filter_type);
  // action
  rosidl_runtime_c__String__fini(&msg->action);
}

bool
capture_msgs__srv__Capture_Request__are_equal(const capture_msgs__srv__Capture_Request * lhs, const capture_msgs__srv__Capture_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // filter_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->filter_type), &(rhs->filter_type)))
  {
    return false;
  }
  // action
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->action), &(rhs->action)))
  {
    return false;
  }
  return true;
}

bool
capture_msgs__srv__Capture_Request__copy(
  const capture_msgs__srv__Capture_Request * input,
  capture_msgs__srv__Capture_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // filter_type
  if (!rosidl_runtime_c__String__copy(
      &(input->filter_type), &(output->filter_type)))
  {
    return false;
  }
  // action
  if (!rosidl_runtime_c__String__copy(
      &(input->action), &(output->action)))
  {
    return false;
  }
  return true;
}

capture_msgs__srv__Capture_Request *
capture_msgs__srv__Capture_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  capture_msgs__srv__Capture_Request * msg = (capture_msgs__srv__Capture_Request *)allocator.allocate(sizeof(capture_msgs__srv__Capture_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(capture_msgs__srv__Capture_Request));
  bool success = capture_msgs__srv__Capture_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
capture_msgs__srv__Capture_Request__destroy(capture_msgs__srv__Capture_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    capture_msgs__srv__Capture_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
capture_msgs__srv__Capture_Request__Sequence__init(capture_msgs__srv__Capture_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  capture_msgs__srv__Capture_Request * data = NULL;

  if (size) {
    data = (capture_msgs__srv__Capture_Request *)allocator.zero_allocate(size, sizeof(capture_msgs__srv__Capture_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = capture_msgs__srv__Capture_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        capture_msgs__srv__Capture_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
capture_msgs__srv__Capture_Request__Sequence__fini(capture_msgs__srv__Capture_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      capture_msgs__srv__Capture_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

capture_msgs__srv__Capture_Request__Sequence *
capture_msgs__srv__Capture_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  capture_msgs__srv__Capture_Request__Sequence * array = (capture_msgs__srv__Capture_Request__Sequence *)allocator.allocate(sizeof(capture_msgs__srv__Capture_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = capture_msgs__srv__Capture_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
capture_msgs__srv__Capture_Request__Sequence__destroy(capture_msgs__srv__Capture_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    capture_msgs__srv__Capture_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
capture_msgs__srv__Capture_Request__Sequence__are_equal(const capture_msgs__srv__Capture_Request__Sequence * lhs, const capture_msgs__srv__Capture_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!capture_msgs__srv__Capture_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
capture_msgs__srv__Capture_Request__Sequence__copy(
  const capture_msgs__srv__Capture_Request__Sequence * input,
  capture_msgs__srv__Capture_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(capture_msgs__srv__Capture_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    capture_msgs__srv__Capture_Request * data =
      (capture_msgs__srv__Capture_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!capture_msgs__srv__Capture_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          capture_msgs__srv__Capture_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!capture_msgs__srv__Capture_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
capture_msgs__srv__Capture_Response__init(capture_msgs__srv__Capture_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    capture_msgs__srv__Capture_Response__fini(msg);
    return false;
  }
  return true;
}

void
capture_msgs__srv__Capture_Response__fini(capture_msgs__srv__Capture_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
capture_msgs__srv__Capture_Response__are_equal(const capture_msgs__srv__Capture_Response * lhs, const capture_msgs__srv__Capture_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
capture_msgs__srv__Capture_Response__copy(
  const capture_msgs__srv__Capture_Response * input,
  capture_msgs__srv__Capture_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

capture_msgs__srv__Capture_Response *
capture_msgs__srv__Capture_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  capture_msgs__srv__Capture_Response * msg = (capture_msgs__srv__Capture_Response *)allocator.allocate(sizeof(capture_msgs__srv__Capture_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(capture_msgs__srv__Capture_Response));
  bool success = capture_msgs__srv__Capture_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
capture_msgs__srv__Capture_Response__destroy(capture_msgs__srv__Capture_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    capture_msgs__srv__Capture_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
capture_msgs__srv__Capture_Response__Sequence__init(capture_msgs__srv__Capture_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  capture_msgs__srv__Capture_Response * data = NULL;

  if (size) {
    data = (capture_msgs__srv__Capture_Response *)allocator.zero_allocate(size, sizeof(capture_msgs__srv__Capture_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = capture_msgs__srv__Capture_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        capture_msgs__srv__Capture_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
capture_msgs__srv__Capture_Response__Sequence__fini(capture_msgs__srv__Capture_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      capture_msgs__srv__Capture_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

capture_msgs__srv__Capture_Response__Sequence *
capture_msgs__srv__Capture_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  capture_msgs__srv__Capture_Response__Sequence * array = (capture_msgs__srv__Capture_Response__Sequence *)allocator.allocate(sizeof(capture_msgs__srv__Capture_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = capture_msgs__srv__Capture_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
capture_msgs__srv__Capture_Response__Sequence__destroy(capture_msgs__srv__Capture_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    capture_msgs__srv__Capture_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
capture_msgs__srv__Capture_Response__Sequence__are_equal(const capture_msgs__srv__Capture_Response__Sequence * lhs, const capture_msgs__srv__Capture_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!capture_msgs__srv__Capture_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
capture_msgs__srv__Capture_Response__Sequence__copy(
  const capture_msgs__srv__Capture_Response__Sequence * input,
  capture_msgs__srv__Capture_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(capture_msgs__srv__Capture_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    capture_msgs__srv__Capture_Response * data =
      (capture_msgs__srv__Capture_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!capture_msgs__srv__Capture_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          capture_msgs__srv__Capture_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!capture_msgs__srv__Capture_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
