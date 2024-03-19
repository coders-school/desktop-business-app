# Desktop Business Application

TBD...

## Development

### Prerequisites

- Docker
- Google Test
- C++20

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
docker run -it --entrypoint="/application/bin/desktop-business-app-all-tests" desktop-business-application
```

### Run GUI application from docker (on Ubuntu)

```bash
xhost +local:docker
docker run --net=host -e DISPLAY=$DISPLAY desktop-business-application
```
