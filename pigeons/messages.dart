// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'package:pigeon/pigeon.dart';

@ConfigurePigeon(PigeonOptions(
  dartOut: 'lib/src/messages.g.dart',
  cppOptions: CppOptions(namespace: 'url_launcher_windows'),
  cppHeaderOut: 'windows/messages.g.h',
  cppSourceOut: 'windows/messages.g.cpp',
  copyrightHeader: 'pigeons/copyright.txt',
))
class TestBug {
  TestBug({
    required this.anotherString,
  });

  final String anotherString;
}

@HostApi(dartHostTestHandler: 'TestUrlLauncherApi')
abstract class UrlLauncherApi {
  bool canLaunchUrl(String url, TestBug? testBug);
  bool launchUrl(String url);
}
