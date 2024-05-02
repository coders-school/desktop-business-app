# Desktop Business Application

This project is developed within the Ninja C++ Club. 
Its purpose is to familiarize participants with the software development lifecycle, repository creation, and principles of automating CI/CD processes and many more!

## Overview

**Desktop Business Application** is a software designed to assist in managing a dental clinic.
 
This application serves as a practical exercise in software development, offering hands-on experience in building a comprehensive desktop solution for business needs within the healthcare industry.

## Features

- **Appointment Management**: Schedule and manage appointments for patients efficiently.
- **Inventory Management**: Keep track of clinic inventory to ensure availability of necessary supplies.
- **Patient Database**: Maintain a database of patient records for easy access and management.
- **Employee Database**: Store employee information and manage staff effectively.
- **Calendar Functionality**: View appointments and other events conveniently on a calendar interface.

### Prerequisites

- Docker
- Google Test and Google Mock
- C++20
- clang-format (recommended minimum ver. 17)
- OpenSSL

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

```bash
apt-get install -y xvfb
Xvfb :99 -screen 0 1024x768x16 &
export DISPLAY=:99
export QT_QPA_PLATFORM=offscreen
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
