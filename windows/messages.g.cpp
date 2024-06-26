// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
// Autogenerated from Pigeon (v13.1.2), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#undef _HAS_EXCEPTIONS

#include "messages.g.h"

#include <flutter/basic_message_channel.h>
#include <flutter/binary_messenger.h>
#include <flutter/encodable_value.h>
#include <flutter/standard_message_codec.h>

#include <map>
#include <optional>
#include <string>

namespace url_launcher_windows {
using flutter::BasicMessageChannel;
using flutter::CustomEncodableValue;
using flutter::EncodableList;
using flutter::EncodableMap;
using flutter::EncodableValue;

FlutterError CreateConnectionError(const std::string channel_name) {
    return FlutterError(
        "channel-error",
        "Unable to establish connection on channel: '" + channel_name + "'.",
        EncodableValue(""));
}

// TestBug

TestBug::TestBug(const std::string& another_string)
 : another_string_(another_string) {}

const std::string& TestBug::another_string() const {
  return another_string_;
}

void TestBug::set_another_string(std::string_view value_arg) {
  another_string_ = value_arg;
}


EncodableList TestBug::ToEncodableList() const {
  EncodableList list;
  list.reserve(1);
  list.push_back(EncodableValue(another_string_));
  return list;
}

TestBug TestBug::FromEncodableList(const EncodableList& list) {
  TestBug decoded(
    std::get<std::string>(list[0]));
  return decoded;
}


UrlLauncherApiCodecSerializer::UrlLauncherApiCodecSerializer() {}

EncodableValue UrlLauncherApiCodecSerializer::ReadValueOfType(
  uint8_t type,
  flutter::ByteStreamReader* stream) const {
  switch (type) {
    case 128:
      return CustomEncodableValue(TestBug::FromEncodableList(std::get<EncodableList>(ReadValue(stream))));
    default:
      return flutter::StandardCodecSerializer::ReadValueOfType(type, stream);
  }
}

void UrlLauncherApiCodecSerializer::WriteValue(
  const EncodableValue& value,
  flutter::ByteStreamWriter* stream) const {
  if (const CustomEncodableValue* custom_value = std::get_if<CustomEncodableValue>(&value)) {
    if (custom_value->type() == typeid(TestBug)) {
      stream->WriteByte(128);
      WriteValue(EncodableValue(std::any_cast<TestBug>(*custom_value).ToEncodableList()), stream);
      return;
    }
  }
  flutter::StandardCodecSerializer::WriteValue(value, stream);
}

/// The codec used by UrlLauncherApi.
const flutter::StandardMessageCodec& UrlLauncherApi::GetCodec() {
  return flutter::StandardMessageCodec::GetInstance(&UrlLauncherApiCodecSerializer::GetInstance());
}

// Sets up an instance of `UrlLauncherApi` to handle messages through the `binary_messenger`.
void UrlLauncherApi::SetUp(
  flutter::BinaryMessenger* binary_messenger,
  UrlLauncherApi* api) {
  {
    auto channel = std::make_unique<BasicMessageChannel<>>(binary_messenger, "dev.flutter.pigeon.url_launcher_windows.UrlLauncherApi.canLaunchUrl", &GetCodec());
    if (api != nullptr) {
      channel->SetMessageHandler([api](const EncodableValue& message, const flutter::MessageReply<EncodableValue>& reply) {
        try {
          const auto& args = std::get<EncodableList>(message);
          const auto& encodable_url_arg = args.at(0);
          if (encodable_url_arg.IsNull()) {
            reply(WrapError("url_arg unexpectedly null."));
            return;
          }
          const auto& url_arg = std::get<std::string>(encodable_url_arg);
          const auto& encodable_test_bug_arg = args.at(1);
          const auto* test_bug_arg = &(std::any_cast<const TestBug&>(std::get<CustomEncodableValue>(encodable_test_bug_arg)));
          ErrorOr<bool> output = api->CanLaunchUrl(url_arg, test_bug_arg);
          if (output.has_error()) {
            reply(WrapError(output.error()));
            return;
          }
          EncodableList wrapped;
          wrapped.push_back(EncodableValue(std::move(output).TakeValue()));
          reply(EncodableValue(std::move(wrapped)));
        } catch (const std::exception& exception) {
          reply(WrapError(exception.what()));
        }
      });
    } else {
      channel->SetMessageHandler(nullptr);
    }
  }
  {
    auto channel = std::make_unique<BasicMessageChannel<>>(binary_messenger, "dev.flutter.pigeon.url_launcher_windows.UrlLauncherApi.launchUrl", &GetCodec());
    if (api != nullptr) {
      channel->SetMessageHandler([api](const EncodableValue& message, const flutter::MessageReply<EncodableValue>& reply) {
        try {
          const auto& args = std::get<EncodableList>(message);
          const auto& encodable_url_arg = args.at(0);
          if (encodable_url_arg.IsNull()) {
            reply(WrapError("url_arg unexpectedly null."));
            return;
          }
          const auto& url_arg = std::get<std::string>(encodable_url_arg);
          ErrorOr<bool> output = api->LaunchUrl(url_arg);
          if (output.has_error()) {
            reply(WrapError(output.error()));
            return;
          }
          EncodableList wrapped;
          wrapped.push_back(EncodableValue(std::move(output).TakeValue()));
          reply(EncodableValue(std::move(wrapped)));
        } catch (const std::exception& exception) {
          reply(WrapError(exception.what()));
        }
      });
    } else {
      channel->SetMessageHandler(nullptr);
    }
  }
}

EncodableValue UrlLauncherApi::WrapError(std::string_view error_message) {
  return EncodableValue(EncodableList{
    EncodableValue(std::string(error_message)),
    EncodableValue("Error"),
    EncodableValue()
  });
}

EncodableValue UrlLauncherApi::WrapError(const FlutterError& error) {
  return EncodableValue(EncodableList{
    EncodableValue(error.code()),
    EncodableValue(error.message()),
    error.details()
  });
}

}  // namespace url_launcher_windows
