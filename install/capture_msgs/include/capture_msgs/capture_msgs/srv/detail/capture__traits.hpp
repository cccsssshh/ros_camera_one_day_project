// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from capture_msgs:srv/Capture.idl
// generated code does not contain a copyright notice

#ifndef CAPTURE_MSGS__SRV__DETAIL__CAPTURE__TRAITS_HPP_
#define CAPTURE_MSGS__SRV__DETAIL__CAPTURE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "capture_msgs/srv/detail/capture__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace capture_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Capture_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: filter_type
  {
    out << "filter_type: ";
    rosidl_generator_traits::value_to_yaml(msg.filter_type, out);
    out << ", ";
  }

  // member: action
  {
    out << "action: ";
    rosidl_generator_traits::value_to_yaml(msg.action, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Capture_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: filter_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filter_type: ";
    rosidl_generator_traits::value_to_yaml(msg.filter_type, out);
    out << "\n";
  }

  // member: action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action: ";
    rosidl_generator_traits::value_to_yaml(msg.action, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Capture_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace capture_msgs

namespace rosidl_generator_traits
{

[[deprecated("use capture_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const capture_msgs::srv::Capture_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  capture_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use capture_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const capture_msgs::srv::Capture_Request & msg)
{
  return capture_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<capture_msgs::srv::Capture_Request>()
{
  return "capture_msgs::srv::Capture_Request";
}

template<>
inline const char * name<capture_msgs::srv::Capture_Request>()
{
  return "capture_msgs/srv/Capture_Request";
}

template<>
struct has_fixed_size<capture_msgs::srv::Capture_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<capture_msgs::srv::Capture_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<capture_msgs::srv::Capture_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace capture_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Capture_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Capture_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Capture_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace capture_msgs

namespace rosidl_generator_traits
{

[[deprecated("use capture_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const capture_msgs::srv::Capture_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  capture_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use capture_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const capture_msgs::srv::Capture_Response & msg)
{
  return capture_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<capture_msgs::srv::Capture_Response>()
{
  return "capture_msgs::srv::Capture_Response";
}

template<>
inline const char * name<capture_msgs::srv::Capture_Response>()
{
  return "capture_msgs/srv/Capture_Response";
}

template<>
struct has_fixed_size<capture_msgs::srv::Capture_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<capture_msgs::srv::Capture_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<capture_msgs::srv::Capture_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<capture_msgs::srv::Capture>()
{
  return "capture_msgs::srv::Capture";
}

template<>
inline const char * name<capture_msgs::srv::Capture>()
{
  return "capture_msgs/srv/Capture";
}

template<>
struct has_fixed_size<capture_msgs::srv::Capture>
  : std::integral_constant<
    bool,
    has_fixed_size<capture_msgs::srv::Capture_Request>::value &&
    has_fixed_size<capture_msgs::srv::Capture_Response>::value
  >
{
};

template<>
struct has_bounded_size<capture_msgs::srv::Capture>
  : std::integral_constant<
    bool,
    has_bounded_size<capture_msgs::srv::Capture_Request>::value &&
    has_bounded_size<capture_msgs::srv::Capture_Response>::value
  >
{
};

template<>
struct is_service<capture_msgs::srv::Capture>
  : std::true_type
{
};

template<>
struct is_service_request<capture_msgs::srv::Capture_Request>
  : std::true_type
{
};

template<>
struct is_service_response<capture_msgs::srv::Capture_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CAPTURE_MSGS__SRV__DETAIL__CAPTURE__TRAITS_HPP_
