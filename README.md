# Desktop Business Application

TBD...

## Development

### Prerequisites

- Docker
- Google Test
- C++20
- clang-format (recommended minimum ver. 17)

### Format code before committing

```bash
find . -name '*.cpp' -or -name '*.h' | xargs clang-format --verbose -style=file -i
```

### Build

```bash
docker build -t desktop-business-application .
```

### Run image

```bash
docker run -it --entrypoint /bin/bash desktop-business-application
```

### Run GUI application from docker (on Ubuntu)

```bash
xhost +local:docker
docker run --net=host -e DISPLAY=$DISPLAY desktop-business-application
```
