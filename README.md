# Windows bug when nullable argument is passed

Pigeon generated code cannot handle nullable arguments when they are `null`.

1. Run `flutter build windows --debug` in example/
2. Open app on Visual Studio by opening the solution in example/build/windows/x64/runner/runner.sln
3. Put two break points on [these lines](https://github.com/russellwheatley/pigeon_bug_windows/blob/master/windows/messages.g.cpp#L110-L111). Not that it gets to the first line but will crash before getting to the second line.