# **BUILDING TESTS**
---
NOTE: it may be obvious, but if anything in `backend` changes it has to be rebuild before `tests` module is build.
Any of the ways may be used for building.

## Building backend and tests manually

If we want to build `backend` modules from clean state, we need to:
1. Create or cleanup "build" directory
2. ```cd build```
3. Run cmake configuration:
   ```cmake -DCMAKE_BUILD_TYPE=Debug ../modules/backend/```
4. Build `backend` module
   ```cmake --build . --parallel --target install -- -j2```
   NOTE: `-j2` flag sets maximum number of threads used. It origins in attempt to fix building on some machines.
   Everyone is free to experiment with number of threads or can remove this flag if maximum available threads is OK.
   For machines with limited resources or virtual machines it is recommended to use -j2 or -j1 even.
   On the other hand, for machines which can handle this, more threads would speedup build processes.

If we we have `backend` cmake configuration run beforehand and/or built `backend` it is enough to perform step 4 from "build" directory.

After having `backend` module built, we can proceed to building `test` module itself.

If we want to build `tests` module from clean state (and we have `backend` built), we need to:
1. Create or cleanup "build" directory
2. ```cd build```
3. Run cmake configuration:
   ```cmake -DCMAKE_BUILD_TYPE=Debug ../modules/tests/```
4. Build `tests` module
   ```cmake --build . --parallel```
   NOTE: `-j2` flag (or with any other reasonable number) can be used to limit number of threads for building if problems are encountered.

If we we have `tests` cmake configuration run beforehand and/or built `tests` it is enough to perform step 4 from "build" directory.

## Building backend with script from clean state

If we want to build `backend` from clean state, we can just run from top level folder the `backend_clean_build.sh` script.
NOTE: this script cleans "build" directory each time so it performs build from the start (**but external_libraries will be reused if built previously**).
It is up to developer if one prefers to rebuild from clean build each time because it is handy to use script (with the cost of time).
If backend was built previously it might be more efficient to perform just the required steps explained in manual building section.

### Building tests and backend with script from clean state

If we want to build `backend` and `tests` together from clean state, we can just run from top level folder the `tests_and_backend_clean_build.sh` script.
NOTE: this script cleans "build" and "build" directory each time so it performs build from the start (**but external_libraries will be reused if built previously**).
It is up to developer if one prefers to rebuild from clean build each time because it is handy to use script (with the cost of time).
If backend and tests were built previously it might be more efficient to perform just the required steps explained in manual building section.
But remember, that each change in `backend` requires it to be rebuild itself.
In such scenario script might not be a bad idea if one is OK with waiting a bit for rebuilding from clean state.
I sometimes just open enough tabs in terminal to conveniently jump between folder and I use manual rebuilding myself.

# **RUNNING TESTS**
---
In general there are 3 ways of running build tests, each serving a bit different purposes, having pros and conns.

## Running specific test by name

PREREQUISITES: `backend` and `tests` built in one of suggested above ways

If we want to run only one test binary, `TreatmentTest` for example, we can do it directly from bin folder:
```
cd bin
./TreatmentTest
```
Alternatively, if we want valgrind used:
```
valgrind ./TreatmentTest
```
or
```
valgrind --leak-check=full /TreatmentTest
```

## Running all tests by with ctest using scirpt

PREREQUISITES: `backend` and `tests` built in one of suggested above ways
PROS:
+ we run all tests with single script
+ despite running all tests, only failing ones will be printed

CONS: if we work heavily on one specific test, and others are sure to work, it might be more convenient some times
to run just one test, especially if we want pass additional flags, like `--gtest_filter`

We have to scripts for run all tests with ctest:
- `ctest_run.sh` - for normal test running
- `valgrind_ctest_run.sh` - for running ctest under valgrind.

Optionally we can run ctest manually from "build" directory with simple commands:
```ctest```

It is still recommended to use valgrind script for memory checking instead of trying to run ctest with valgrind manually.
It is not easy to do so.

The `valgrind_ctest_run.sh` when run will give us some interesting info. Example print:
```
5/7 MemCheck: #5: TreatmentTests ...................   Defects: 4
6/7 MemCheck: #6: TreatmentStateTests ..............   Defects: 4
7/7 MemCheck: #7: basic_construction-test ..........   Defects: 1
MemCheck log files can be found here: (<#> corresponds to test number)
/home/piworzuop/Klub-Ninja/projekt/desktop-business-app/build/Testing/Temporary/MemoryChecker.<#>.log
Memory checking results:
Memory Leak - 1
Uninitialized Memory Conditional - 6
Uninitialized Memory Read - 2
Memory errors detected.
```
As we can see, we are offered general info about detected problems and we are told where to check detailed logs for each test!
