# Desktop Business Application

TBD...

## Development

### Prerequisites

- Docker
- Google Test
- C++20
- clang-format (recommended minimum ver. 17)
- requires OpenSSL

### Format code before committing manually

```bash
find . -name '*.cpp' -or -name '*.h' -or -name '*.hpp' | xargs clang-format --verbose -style=file -i
```

### Format code before committing using bash script

```bash
# run once after repo download if permission problem occurs
chmod +x ./clang-fmt-all.sh
# run from the top of workspace directory
./clang-fmt-all.sh
```


### Build

```bash
docker build -t desktop-business-application .
```

### Run image in terminal

```bash
docker run -it --entrypoint /bin/bash desktop-business-application
```

### Run all tests from image
```bash
docker run -it --entrypoint="/application/bin/desktop-business-app-tests" desktop-business-application
```

### Running test locally
After building test target locally  we can run all tests:
```bash
cd bin
./desktop-business-app-tests
```

Or we can limit testing to some tests according to our needs (finding best phrase in our test code like test-case name), for example:
```bash
cd bin
./desktop-business-app-tests --gtest_filter="*ReceptionistTestFixture*"
```

### Run GUI application from docker (on Ubuntu)

```bash
xhost +local:docker
docker run --net=host -e DISPLAY=$DISPLAY desktop-business-application
```

### Investigating memory issues in valgrind
Example of installing `valgrind` on ubuntu:

```bash
sudo apt install valgrind
```
After building tests for example one can run valgrind on tests:

```bash
cd bin
valgrind --leak-check=full ./desktop-business-app-tests
```

If we want to limit our output somehow, we can find a best identification string in our test's name and use it like this:

```bash
valgrind --leak-check=full ./desktop-business-app-tests --gtest_filter="*Association*"
```
