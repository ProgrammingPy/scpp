1:make distclean

2:qmake

3:source envlib.sh

4:./unittest/unittest

[==========] Running 5 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 5 tests from TextUtils
[ RUN      ] TextUtils.upper
[       OK ] TextUtils.upper (0 ms)
[ RUN      ] TextUtils.lower
[       OK ] TextUtils.lower (0 ms)
[ RUN      ] TextUtils.lstrip
[       OK ] TextUtils.lstrip (0 ms)
[ RUN      ] TextUtils.rstrip
[       OK ] TextUtils.rstrip (0 ms)
[ RUN      ] TextUtils.strip
[       OK ] TextUtils.strip (0 ms)
[----------] 5 tests from TextUtils (0 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 5 tests.

5:Qt env
#!/bin/bash
export QTDIR=$HOME/work/qintro/qt-everywhere-opensource-src-5.8.0/qtbase
export PATH=$QTDIR/bin:$PATH
export LD_LIBRARY_PATH=$QTDIR/lib:$LD_LIBRARY_PATH

