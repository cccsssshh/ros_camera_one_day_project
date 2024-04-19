// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from capture_msgs:srv/Capture.idl
// generated code does not contain a copyright notice

#ifndef CAPTURE_MSGS__SRV__DETAIL__CAPTURE__STRUCT_HPP_
#define CAPTURE_MSGS__SRV__DETAIL__CAPTURE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__capture_msgs__srv__Capture_Request __attribute__((deprecated))
#else
# define DEPRECATED__capture_msgs__srv__Capture_Request __declspec(deprecated)
#endif

namespace capture_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Capture_Request_
{
  using Type = Capture_Request_<ContainerAllocator>;

  explicit Capture_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filter_type = "";
      this->action = "";
    }
  }

  explicit Capture_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : filter_type(_alloc),
    action(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filter_type = "";
      this->action = "";
    }
  }

  // field types and members
  using _filter_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _filter_type_type filter_type;
  using _action_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _action_type action;

  // setters for named parameter idiom
  Type & set__filter_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->filter_type = _arg;
    return *this;
  }
  Type & set__action(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->action = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    capture_msgs::srv::Capture_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const capture_msgs::srv::Capture_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<capture_msgs::srv::Capture_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<capture_msgs::srv::Capture_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      capture_msgs::srv::Capture_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<capture_msgs::srv::Capture_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      capture_msgs::srv::Capture_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<capture_msgs::srv::Capture_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<capture_msgs::srv::Capture_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<capture_msgs::srv::Capture_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__capture_msgs__srv__Capture_Request
    std::shared_ptr<capture_msgs::srv::Capture_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__capture_msgs__srv__Capture_Request
    std::shared_ptr<capture_msgs::srv::Capture_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Capture_Request_ & other) const
  {
    if (this->filter_type != other.filter_type) {
      return false;
    }
    if (this->action != other.action) {
      return false;
    }
    return true;
  }
  bool operator!=(const Capture_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Capture_Request_

// alias to use template instance with default allocator
using Capture_Request =
  capture_msgs::srv::Capture_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace capture_msgs


#ifndef _WIN32
# define DEPRECATED__capture_msgs__srv__Capture_Response __attribute__((deprecated))
#else
# define DEPRECATED__capture_msgs__srv__Capture_Response __declspec(deprecated)
#endif

namespace capture_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Capture_Response_
{
  using Type = Capture_Response_<ContainerAllocator>;

  explicit Capture_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit Capture_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    capture_msgs::srv::Capture_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const capture_msgs::srv::Capture_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<capture_msgs::srv::Capture_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<capture_msgs::srv::Capture_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      capture_msgs::srv::Capture_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<capture_msgs::srv::Capture_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      capture_msgs::srv::Capture_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<capture_msgs::srv::Capture_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<capture_msgs::srv::Capture_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<capture_msgs::srv::Capture_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__capture_msgs__srv__Capture_Response
    std::shared_ptr<capture_msgs::srv::Capture_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__capture_msgs__srv__Capture_Response
    std::shared_ptr<capture_msgs::srv::Capture_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Capture_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const Capture_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Capture_Response_

// alias to use template instance with default allocator
using Capture_Response =
  capture_msgs::srv::Capture_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace capture_msgs

namespace capture_msgs
{

namespace srv
{

struct Capture
{
  using Request = capture_msgs::srv::Capture_Request;
  using Response = capture_msgs::srv::Capture_Response;
};

}  // namespace srv

}  // namespace capture_msgs

#endif  // CAPTURE_MSGS__SRV__DETAIL__CAPTURE__STRUCT_HPP_
