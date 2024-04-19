// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from capture_msgs:srv/Capture.idl
// generated code does not contain a copyright notice

#ifndef CAPTURE_MSGS__SRV__DETAIL__CAPTURE__BUILDER_HPP_
#define CAPTURE_MSGS__SRV__DETAIL__CAPTURE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "capture_msgs/srv/detail/capture__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace capture_msgs
{

namespace srv
{

namespace builder
{

class Init_Capture_Request_action
{
public:
  explicit Init_Capture_Request_action(::capture_msgs::srv::Capture_Request & msg)
  : msg_(msg)
  {}
  ::capture_msgs::srv::Capture_Request action(::capture_msgs::srv::Capture_Request::_action_type arg)
  {
    msg_.action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::capture_msgs::srv::Capture_Request msg_;
};

class Init_Capture_Request_filter_type
{
public:
  Init_Capture_Request_filter_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Capture_Request_action filter_type(::capture_msgs::srv::Capture_Request::_filter_type_type arg)
  {
    msg_.filter_type = std::move(arg);
    return Init_Capture_Request_action(msg_);
  }

private:
  ::capture_msgs::srv::Capture_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::capture_msgs::srv::Capture_Request>()
{
  return capture_msgs::srv::builder::Init_Capture_Request_filter_type();
}

}  // namespace capture_msgs


namespace capture_msgs
{

namespace srv
{

namespace builder
{

class Init_Capture_Response_message
{
public:
  explicit Init_Capture_Response_message(::capture_msgs::srv::Capture_Response & msg)
  : msg_(msg)
  {}
  ::capture_msgs::srv::Capture_Response message(::capture_msgs::srv::Capture_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::capture_msgs::srv::Capture_Response msg_;
};

class Init_Capture_Response_success
{
public:
  Init_Capture_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Capture_Response_message success(::capture_msgs::srv::Capture_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Capture_Response_message(msg_);
  }

private:
  ::capture_msgs::srv::Capture_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::capture_msgs::srv::Capture_Response>()
{
  return capture_msgs::srv::builder::Init_Capture_Response_success();
}

}  // namespace capture_msgs

#endif  // CAPTURE_MSGS__SRV__DETAIL__CAPTURE__BUILDER_HPP_
