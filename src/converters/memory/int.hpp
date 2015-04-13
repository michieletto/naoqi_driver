/*
 * Copyright 2015 Aldebaran
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef MEMORY_INT_CONVERTER_HPP
#define MEMORY_INT_CONVERTER_HPP

#include <map>
#include <vector>

#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <naoqi_bridge_msgs/IntStamped.h>

#include <boost/function.hpp>

#include <qi/anyobject.hpp>

#include <alrosbridge/message_actions.h>
#include "../converter_base.hpp"

namespace alros
{
namespace converter
{

class MemoryIntConverter : public BaseConverter<MemoryIntConverter>
{
  typedef boost::function<void(naoqi_bridge_msgs::IntStamped&)> Callback_t;

public:

  MemoryIntConverter( const std::string& name, const float& frequency, const qi::SessionPtr& session, const std::string& memory_key );

  void reset();

  void registerCallback( const message_actions::MessageAction action, Callback_t cb );

  void callAll( const std::vector<message_actions::MessageAction>& actions );

private:
  void convert();

private:
  /** Memory key to retrieve data */
  std::string memory_key_;
  /** Memory (Proxy) configurations */
  qi::AnyObject p_memory_;

  std::map<message_actions::MessageAction, Callback_t> callbacks_;
  naoqi_bridge_msgs::IntStamped msg_;

}; // class

} //publisher
} // alros

#endif
